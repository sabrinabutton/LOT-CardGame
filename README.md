# Legend of Tarot
Text-Based Card Game in C++ made for ICS3U

Legend of Tarot is a battling game where the user collects cards in order to become more powerful. The cards in the game are based off of Tarot cards, which are commonly used in fortune telling, hence the name "Legend of Tarot". 

## Battling
Elven Tarot, the deck used in the game, has five suits: hearts, pentacles, wands, swords and runes.

The power order goes as follows:
Hearts > Pentacles > Wands > Swords > Runes > Hearts

Keep in mind, if 2 suits are not directly beside eachother on the power order,
they are nuetral to eachother andtheir attack value is average. If one suit is better, it will user its strong attack value.
The weaker of the two will use a weak attack value. 

Runes do not do attack, but are special cards that can cause disadvantages to the opponent. 

You can own as many cards as you like, however you can only store 5 in your hand at one time. 
In a game, the goal is to make the opponent run out of health before you do.

To battle, select a card from your hand. The other player will play automatically and the round will finish. Each players move, health and damage dealt will be logged after the round. Each battle has five rounds. 

## Buying and Collecting
The user can buy cards from the in-game shop using in-game money gained in battle. The shop also allows the user to buy more health and change their name for a small fee. In the shop, any card can be bought at any time, however more powerful cards will cost more. The cards are ranked from I-V, with I being the weakest cards and V being the strongest. To get money to afford these cards, the user must bet in battles.

## Winning
Legend of Tarot has no official ending, but the point of the game is to collect all of the cards. This doesn't have to be done in one sitting, however, as LOT has a saving feature.
