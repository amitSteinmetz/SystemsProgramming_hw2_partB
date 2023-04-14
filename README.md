# SystemsProgramming_hw2_partB
## CardWar game

This is the old, classic and fun game that everyone knows since childhood.
Two players can play in a game. There are 52 cards, and the player that collect more cards is the winner.

The program split to four classes - card, deck, player and game.

**Card** - represent one card. There are 4 types of symbols, and 13 optional values, all implemented as ENUM.

**Deck** - represent a bunch of cards. It can be the dealer deck, or player deck.
The deck stored in a vector - especially because of varied functions that vector can perform.
An important feature in the deck is that it can be shuffled randomly.

**Player** - represent the entity of a player, holding an attributes such as name, cards collected, number of wins, and the player deck.
This class has many functions that are widely used in the program.

**Game** - represent the running game. There are two players, dealer deck, record of the turns, and more attributes.
This class is the most important class. The game is played by activating the functions of this class.


NOTE - there are some edge cases that could happend in a game. we covered all of them in order to avoid from bugs in the game. 
