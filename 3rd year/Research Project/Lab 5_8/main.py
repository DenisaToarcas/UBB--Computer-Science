import tweepy
import pandas as pd
import random

#Setup: Required Libraries

# Setup API credentials
API_KEY = ''
API_SECRET = ''
ACCESS_TOKEN = ''
ACCESS_SECRET = ''

# Authenticate
auth = tweepy.OAuth1UserHandler(API_KEY, API_SECRET, ACCESS_TOKEN, ACCESS_SECRET)
api = tweepy.API(auth)

# Parameters for the experiment
DESTINATIONS = ['Barcelona', 'Lisbon']
HASHTAGS = {
    'Barcelona': ['#BarcelonaTravel', '#GaudiArchitecture', '#BarcelonaBeaches'],
    'Lisbon': ['#LisbonViews', '#PastelDeNata', '#LisbonTravel']
}

# Data Collection
def collect_tweets(destination, hashtags, count=100):
    """
    Collect tweets for a given destination and hashtags.
    """
    query = f"{' OR '.join(hashtags)} -filter:retweets"
    tweets = tweepy.Cursor(api.search_tweets, q=query, lang="en", tweet_mode='extended').items(count)

    data = []
    for tweet in tweets:
        data.append({
            'destination': destination,
            'created_at': tweet.created_at,
            'text': tweet.full_text,
            'engagement': tweet.favorite_count + tweet.retweet_count,
            'hashtags': [hashtag['text'] for hashtag in tweet.entities['hashtags']]
        })

    return pd.DataFrame(data)

# Collect data for both destinations
barcelona_data = collect_tweets('Barcelona', HASHTAGS['Barcelona'], count=100)
lisbon_data = collect_tweets('Lisbon', HASHTAGS['Lisbon'], count=100)

# Combine the datasets
all_data = pd.concat([barcelona_data, lisbon_data])
all_data.to_csv('data/social_media_data.csv', index=False)

# Fitness Evaluation
def calculate_fitness(row):
    """
    Fitness function: Calculate the effectiveness of a post.
    Fitness = Engagement + Relevance Score (proportional to hashtag match).
    """
    relevance_score = sum(1 for hashtag in row['hashtags'] if hashtag in HASHTAGS[row['destination']])
    return row['engagement'] + relevance_score * 10  # Weight relevance score higher

# Add fitness scores to the dataset
all_data['fitness'] = all_data.apply(calculate_fitness, axis=1)

# Evolutionary Process
def selection(df, top_percent=0.2):
    """
    Select the top-performing posts based on fitness.
    """
    top_n = int(len(df) * top_percent)
    return df.nlargest(top_n, 'fitness')

def crossover(post1, post2):
    """
    Combine hashtags from two posts to generate a new one.
    """
    combined_hashtags = random.sample(post1['hashtags'] + post2['hashtags'], k=3)
    return combined_hashtags

def mutation(hashtags, mutation_prob=0.1):
    """
    Randomly mutate hashtags with a given probability.
    """
    if random.random() < mutation_prob:
        hashtags.append(random.choice(HASHTAGS[random.choice(list(HASHTAGS.keys()))]))
    return hashtags

# Simulate one generation
def simulate_generation(df):
    """
    Simulate one generation of evolution.
    """
    selected_posts = selection(df)
    new_generation = []

    for i in range(len(selected_posts) // 2):
        post1 = selected_posts.iloc[2 * i]
        post2 = selected_posts.iloc[2 * i + 1]

        new_hashtags = crossover(post1, post2)
        new_hashtags = mutation(new_hashtags)

        new_generation.append({
            'destination': post1['destination'],
            'hashtags': new_hashtags,
            'engagement': 0,  # Initial engagement for new posts
            'fitness': 0
        })

    return pd.DataFrame(new_generation)

# Simulate multiple generations
generations = 5
current_generation = all_data

for gen in range(generations):
    print(f"Simulating generation {gen + 1}")
    current_generation = simulate_generation(current_generation)
    current_generation['fitness'] = current_generation.apply(calculate_fitness, axis=1)

current_generation.to_csv('data/evolved_posts.csv', index=False)
