## Student README starts here

- I am choosing to add a feature to the Snake game as my capstone project
    I am creating a Map class that will read a .txt file that contains a 32x32 block of 1's and 0's. This will render a map of walls on the snake game.
    The walls are colored cyan. Don't touch them or the snake will die!
    I've provided two maps for testing.

# Rubric Items

1. Loops, Functions, I/O: The project demonstrates an understanding of C++ functions and control structures.

Location: Game.cpp, line 59

I've updated the Gnake PlaceFood() function to check if the food will be placed on a wall, and then picking another location for the food. This required iterating over the walls vector with a for loop and modifying the control flow to pick another spot for the food if the first one was occupied by a wall.

2. Loops, Functions, I/O: The project reads data from a file and process the data, or the program writes data to a file.

Location: map.cpp, line 20

I've added a Map class that reads in a .txt file that defines the map of the game. The function returns a boolean which can be used at the start of the game to check that the map was read successfully.

3. Object Oriented Programming: The project uses Object Oriented Programming techniques.

Location: map.cpp, map.h

The map class is used to compose a Game object. When the game is instantiated, it reads in the map file. The map code contains a class enum that defines what type of objects can be on the map. There are functions to return the height and width of the map, and a function to return an object at a map coordinate.

There are many improvements that could be made here. The Height() and Width() functions could be used to change the size of the map, rather than hard coding those sizes in main(). The GetObjectAtPoint() function is also bugged. I've worked around it, but it would have been easier to use that function to check for walls in PlaceFood(), for example.

4. Object Oriented Programming: Classes use appropriate access specifiers for class members.

Location: map.h

Map height, width, and the 2D vector map itself are all private. I would prefer the walls vector to be private as well. I chose to make it public so I could render it in the same was as the Snake body is rendered, which is with a public vector of SDL_Points.

Access to private member variables is given through the Width(), Height() and GetObjectAtPoint() functions.

5. Memory Management: The project makes use of references in function declarations.

Location: snake.cpp, line 23 and game.cpp, line 59

I've modified the Snake's UpdateHead() function and the Game's PlaceFood() functions to take a reference to the map. This is more efficient than passing a 2D vector of 1024 MapObjects.

# Student Notes
- Must copy a map.txt file into build dir before running game
- You are welcome to make a custom map
- To make things easy, all maps should be 32 x 32
- Put name of map in line 11 of game.cpp to choose map

TODO:
- Map::GetObjectAt() is bugged. Had to find other ways to find if point was a wall
- Make the map a smart pointer
- Add snake color matching to food feature
- Take in the name of the map as a command line argument

# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
