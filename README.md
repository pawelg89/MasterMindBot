# MasterMindBot
CLI bot that wants to play Master Mind with you.

Example gameplay
```
Hello! This is the MasterMind game.
[q|Q]      - quit game
[h/H]      - print this message
[rules]    - print rules of the game
[new_game] - reset bot's solution and start a new game
I'm picking a colors combination, you guess. You can take as much time as you like. Good luck with your guesses!

rules
Game Rules
One player (me) is choosing sequence of 4 colors with repetitions.
Available colors: Blue(B), Green(G), Red(R), Yellow(Y) that the other player (you) has to guess.
If you guess a color on correct position you get a 'hit',
If you guess a color but it's in another position (other than hit) you get a 'pseudohit'.
Example: I pick 'RGBY', you guess 'RYGG' and you get 1 hit and 2 pseudohits.
How many guesses do you need to win? ;)

RGGR
Hits: 0, Pseudohits: 1
BBYY
Hits: 1, Pseudohits: 2
BBYR
Hits: 1, Pseudohits: 3
BBRY
Hits: 2, Pseudohits: 2
BRBY
Hits: 1, Pseudohits: 3
YBBR
Hits: 0, Pseudohits: 4
BYRB
!!! CONGRATULATIONS !!!
You guessed my pick 'BYRB' in 7 guesses. Wanna play again?
Type 'new_game' to restart.
```
