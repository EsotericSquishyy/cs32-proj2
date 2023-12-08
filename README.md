# cs32-proj2 (Colosseum Game)

This game is a survival colosseum game. The object is to survive as long as possible without being overwhelmed by the enemies flowing in from the perimeter.

### Compiling
- Make your way to the `src/` directoy.
- Run `make Prog` (or `make Prog_OSX` for MacOS) to compile the Colosseum game.
- Run `./Prog` (or `./Prog_OSX`) to begin the game and enjoy.
- Simply close the game window to stop the game or play until you die and press `[space]`.

### Controls
> Control your character (green) that spawns in the center of the colosseum with `w` and `s` to move forward and back, and use `a` and `d` to rotate the player.
> You can use `[space]` to attack and kill your enemies.

### Enemies
> Enemies spawn at the perimeter of the arena and immediately begin moving towards the `PLAYER`'s positions. They will die when they are touched by your projectiles or the `PLAYER` but be careful as touching them will hurt you as well.

### Gameplay
> Once you run the game you will be greated with a start screen. When you press `[space]` it starts the game.
> A number of enemies will spawn every few seconds with the interval between spawns decreasing linearly over time. Kill them quickly to avoid being overwhelmed when more enemies spawn.
> When your health points reach zero from being hit by enemies you will be shown the "Game Over" screen with your score to compare with friends. You can either close the game to start it again or press `[space]` to end the game to run the game again.

