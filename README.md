<h1 align="center">
	So_Long
</h1>

<p align="center">
	<b><i>42 CURSUS SO_LONG PROJECT</i></b><br>
</p>

## 💡 About the project

The project consists of creating a 2D mini-game with the help of the MLX library.

## Instructions

- The W, A, S and D keys will be used to move the player.
</br>
<p align="center">
<img src="https://github.com/jariza-o/So_long/blob/main/game_picture.png" width="800px" alt="mandatory"/><br>
</p>
</br>
-  The player cannot enter the walls.
</br>
-  After each movement, the current number of moves should be displayed in the terminal.
</br>
-  The game doesn’t need to be real-time.
</br>
-  You can revise the help with the next command:
</br>

```sh
./so_long --help
```
</br>

<p align="center">
<img src="https://github.com/jariza-o/So_long/blob/main/help_picture.png" width="800px" alt="mandatory"/><br>
</p>


### Map

The program should accept a single argument, which will be the map file with the .ber extension.
It must contain the following elements:
• '0' for the floor. \
• '1' for the walls. \
• 'P' for the player, only one. \
• 'E' for the exit, only one. \
• 'C' for the collectibles, at least one.

• The map must be rectangular. \
• The map must be closed/surrounded by walls. \
• You have to check if there’s a valid path in the map. \
• You must be able to parse any kind of map, as long as it respects the above rules.

### Graphics management

• The program will display the image in a window. \
• Window management should be clean, allowing tasks such as switching between windows, minimizing, etc. \
• Pressing the ESC key should close the window and terminate the program cleanly. \
• Clicking on the red cross button of the window should also close the window and terminate the program cleanly.

## Project structure

1. Check the number of arguments and the file extension.
2. Read and parsing the map into data, mostly in one big struct.
3. Check the validity of the provided map.
4. Initialize a window and create and maintain a loop to keep the window open.
5. Initialize/create the images that we are going to use in our game.
6. Render our game map and necessary elements.
7. Create an event loop to handle input.
8. Create the playable mechanics of the game.
9. Play the game.

## Installation

Before compiling the project it is necessary to install MLX42 library a guide can be found
in the [MLX42](https://github.com/codam-coding-college/MLX42) repository.


This project also uses the external library [Libft](https://github.com/jariza-o/Libft) 
also developed in the 42 school curriculum, with some improvements. To clone this project and this library use the command:

```sh
git clone git@github.com:jariza-o/So_long.git
```
</br>

To compile the **mandatory** part (character movement and item collection) use:
```sh
make
```

