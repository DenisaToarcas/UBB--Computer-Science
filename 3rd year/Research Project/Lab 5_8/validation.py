import pandas as pd
import matplotlib.pyplot as plt
from collections import Counter

# Load datasets
initial_data = pd.read_csv('social_media_data.csv')
evolved_data = pd.read_csv('evolved_posts.csv')

# Ensure fitness calculation is consistent
def calculate_fitness(row, hashtags_map):
    relevance_score = sum(1 for hashtag in row['hashtags'] if hashtag in hashtags_map.get(row['destination'], []))
    return row['engagement'] + relevance_score * 10

HASHTAGS = {
    'Barcelona': ['BarcelonaTravel', 'GaudiArchitecture', 'BarcelonaBeaches'],
    'Lisbon': ['LisbonViews', 'PastelDeNata', 'LisbonTravel']
}

# Convert string field lists back to Python lists
evolved_data['hashtags'] = evolved_data['hashtags'].apply(eval)

# Add fitness scores to both datasets
initial_data['fitness'] = initial_data.apply(calculate_fitness, axis=1, args=(HASHTAGS,))
evolved_data['fitness'] = evolved_data.apply(calculate_fitness, axis=1, args=(HASHTAGS,))

# 1. Average Fitness Trend
# Calculate average fitness for both datasets
initial_avg_fitness = initial_data['fitness'].mean()
evolved_avg_fitness = evolved_data['fitness'].mean()

print(f"Initial Average Fitness: {initial_avg_fitness}")
print(f"Evolved Average Fitness: {evolved_avg_fitness}")

# Plot fitness trend
plt.bar(['Initial', 'Evolved'], [initial_avg_fitness, evolved_avg_fitness], color=['blue', 'green'])
plt.title("Average Fitness Comparison")
plt.ylabel("Average Fitness")
plt.show()

# 2. Engagement Trends
# Engagement comparison
initial_avg_engagement = initial_data['engagement'].mean()
evolved_avg_engagement = evolved_data['engagement'].mean()

print(f"Initial Average Engagement: {initial_avg_engagement}")
print(f"Evolved Average Engagement: {evolved_avg_engagement}")

# Plot engagement trend
plt.bar(['Initial', 'Evolved'], [initial_avg_engagement, evolved_avg_engagement], color=['orange', 'purple'])
plt.title("Average Engagement Comparison")
plt.ylabel("Average Engagement")
plt.show()

# 3. High-Performing Hashtags
# Count hashtags in both datasets
initial_hashtags = Counter([tag for tags in initial_data['hashtags'] for tag in tags])
evolved_hashtags = Counter([tag for tags in evolved_data['hashtags'] for tag in tags])

# Most common hashtags
initial_top_hashtags = initial_hashtags.most_common(5)
evolved_top_hashtags = evolved_hashtags.most_common(5)

print("Top Hashtags in Initial Data:", initial_top_hashtags)
print("Top Hashtags in Evolved Data:", evolved_top_hashtags)

# Plot hashtag comparison
labels = list(set([tag for tag, _ in initial_top_hashtags + evolved_top_hashtags]))
initial_counts = [initial_hashtags[tag] for tag in labels]
evolved_counts = [evolved_hashtags[tag] for tag in labels]

x = range(len(labels))
plt.bar(x, initial_counts, width=0.4, label='Initial', color='blue', align='center')
plt.bar(x, evolved_counts, width=0.4, label='Evolved', color='green', align='edge')

plt.xticks(x, labels, rotation=45)
plt.title("Hashtag Frequency Comparison")
plt.ylabel("Frequency")
plt.legend()
plt.show()

# 4. Empirical Evidence: Fitness Improvement
# Fitness improvement percentage
fitness_improvement = ((evolved_avg_fitness - initial_avg_fitness) / initial_avg_fitness) * 100
print(f"Fitness Improvement: {fitness_improvement:.2f}%")

# Engagement improvement percentage
engagement_improvement = ((evolved_avg_engagement - initial_avg_engagement) / initial_avg_engagement) * 100
print(f"Engagement Improvement: {engagement_improvement:.2f}%")

