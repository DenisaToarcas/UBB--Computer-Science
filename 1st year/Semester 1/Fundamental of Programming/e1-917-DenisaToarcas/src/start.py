from Repository import Word
from Controller import ControllGame
from UI import UI

word_or_sentence = Word()
game_controller = ControllGame(word_or_sentence)
ui = UI(game_controller)

ui.main()
