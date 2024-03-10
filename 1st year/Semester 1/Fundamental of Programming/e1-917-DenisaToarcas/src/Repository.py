import random

class Word:
    def __init__(self, filename="input"):
        self.__word_to_play = None
        self.__filename = filename
        self.__words_or_sentences = []
        self.__all_words = []
        self._load_file()

    def _load_file(self):
        file_input = open(self.__filename, "rt")
        word = file_input.readline()
        while word != "/":
            self.__words_or_sentences.append(word)
            word = file_input.readline()

    def __len__(self):
        return len(self.__words_or_sentences)

    def get_number_of_letters_in_word(self):
        return len(self.__word_to_play)

    def get_random_word_to_play(self):
        number_in_list = random.randint(0, len(self.__words_or_sentences) - 1)
        return self.__words_or_sentences[number_in_list]

    def shuffle_word(self):
        word_to_play = self.get_random_word_to_play()
        self.__word_to_play = word_to_play
        number_of_switches = random.randint(15, 20)

        while number_of_switches != 0:
            number_of_switches = number_of_switches - 1
            letter_1_to_switch = random.randint(1, len(word_to_play) - 2)

            if word_to_play[letter_1_to_switch] == ' ':
                while word_to_play[letter_1_to_switch] == ' ':
                    letter_1_to_switch = random.randint(1, len(word_to_play) - 2)

            letter_2_to_switch = random.randint(1, len(word_to_play) - 2)

            if word_to_play[letter_2_to_switch] == ' ':
                while word_to_play[letter_2_to_switch] == ' ':
                    letter_2_to_switch = random.randint(1, len(word_to_play) - 2)

            new_word = ""

            for i in range(0, len(word_to_play)):
                if i == letter_1_to_switch:
                    new_word += word_to_play[letter_2_to_switch]
                elif i == letter_2_to_switch:
                    new_word += word_to_play[letter_1_to_switch]
                else:
                    new_word += word_to_play[i]

            word_to_play = new_word

        self.__word_to_play = word_to_play

        return self.__word_to_play

    def get_word_to_play_shuffled(self):
        return self.shuffle_word()

    def create_list_of_words_to_play(self):
        new_word = ""
        self.__all_words = []

        for i in range(0, self.get_number_of_letters_in_word()):
            if self.__word_to_play[i] != ' ':
                new_word += self.__word_to_play[i]
            else:
                if new_word != "":
                    self.__all_words.append(new_word)
                    new_word = ""

        self.__all_words.append(new_word)
        return self.__all_words

    def __str__(self):
        return str(self)

    def swap_letters_of_words(self, word_1: int, letter_1: int, word_2: int, letter_2: int):
        if word_1 < 0 or word_1 > self.get_number_of_words():
            raise ValueError("Word not part of the list!")
        elif word_2 < 0 or word_2 > self.get_number_of_words():
            raise ValueError("Word not part of the list!")
        elif letter_1 <= 0 or letter_1 == self.get_number_of_letters_in_word()-1:
            raise ValueError("Cannot switch these characters!")
        elif letter_2 <= 0 or letter_2 == self.get_number_of_letters_in_word()-1:
            raise ValueError("Cannot switch these characters!")
        else:

            new_word = ""

            self.create_list_of_words_to_play()

            if self.get_number_of_words() != 1 and word_1 != word_2:
                for i in range(0, self.get_number_of_words()):
                    if i == word_1:
                        if word_1 != 0:
                            new_word += ' '
                        for j in range(0, self.get_letters(self.__all_words[i])):
                            if j == letter_1:
                                second_letter_to_swap = self.__all_words[i][letter_1]
                                new_word += self.__all_words[word_2][letter_2]
                            else:
                                new_word += self.__all_words[i][j]
                        new_word += ' '

                    elif i == word_2:
                        for j in range(0, self.get_letters(self.__all_words[i])):
                            if j == letter_2:
                                new_word += second_letter_to_swap
                            else:
                                new_word += self.__all_words[i][j]
                        new_word += ' '
                    else:
                        if i == 0:
                            new_word += self.__all_words[i]
                            new_word += ' '
                        else:

                            new_word += self.__all_words[i]
                            new_word += ' '

                self.__word_to_play = new_word

            elif word_1 == word_2:
                for i in range(0, self.get_number_of_words()):
                    if i == word_1:
                        for j in range(0, self.get_letters(self.__all_words[word_1])):
                            if j == letter_1:
                                second_letter_to_swap = self.__all_words[word_1][letter_1]
                                new_word += self.__all_words[word_1][letter_2]
                            if j == letter_2:
                                new_word += second_letter_to_swap
                            else:
                                new_word += self.__all_words[word_1][j]
                        new_word += ' '
                    else:
                        if self.get_number_of_words() != 1:
                            if i == 0:
                                new_word += self.__all_words[i]
                                new_word += ' '
                            else:
                                new_word += ' '
                                new_word += self.__all_words[i]
                self.__word_to_play = new_word

        self.__word_to_play = new_word

        return self.__word_to_play



    def get_number_of_words(self):
        number_of_words = 1
        for i in range(0, self.get_number_of_letters_in_word()):
            if self.__word_to_play[i] == ' ':
                number_of_words = number_of_words + 1

        return number_of_words

    def get_letters(self, word: str):
        return len(word)

"""
word = Word()
print(word.get_word_to_play_shuffled())
print(word.swap_letters_of_words(0, 1, 1, 2))
"""


