from src.Repository import Word

class ControllGame:
    def __init__(self, word_to_play: Word):
        self.__word_to_play = word_to_play

    def get_random_word_to_play(self):
        return self.__word_to_play.get_random_word_to_play()

    def shuffle_word(self):
        return self.__word_to_play.shuffle_word()

    def get_word_to_play_shuffled(self):
        return self.__word_to_play.get_word_to_play_shuffled()

    def swap_letters_of_words(self, word_1: int, letter_1: int, word_2: int, letter_2: int):
        return self.__word_to_play.swap_letters_of_words(word_1, letter_1, word_2, letter_2)

    def get_score(self):
        score = 0
        score = self.__word_to_play.get_number_of_letters_in_word() - self.__word_to_play.get_number_of_words()
        return score

    def decrease_score(self, score: int):
        if score != 0:
            return score-1
        else:
            return score
