# CPPND: Capstone Snake Game Project

## Build the project
- Install SDL 2.0 on your machine
```
sudo apt-get install libsdl2-dev
```
- Create the build directory
```
mkdir build && cd build
```
- Build the project
```
cmake .. && make
```
- Run the program
```
./SnakeGame
```

## Project description
The project consists of the snake game.
To the simple implementation of the game, obstacles have been added. Every time the snake grows of 3 units, an obstacle is added.
The obstacle is added at a random location, and is randomly shaped as an L, an I, or a T.
If the snake hits an obstacle it dies and the game is over. When this happens the window will close automatically and the score is displayed on terminal.

## Project Rubric points

### The project demonstrates an understanding of C++ functions and control structures.
The project is clearly organized into functions, in fact some functions were added to the Game class, in order to enhance readability and avoid code repetitions.
For example:
-  `bool IsInObstacleVector(int const &x, int const &y);` is a function used for checking if an obstacle is present in the passed location.

### The project uses Object Oriented Programming techniques.
The project is organized into classes.
The class `Obstacle` has been added and has methods and attributes.

### Classes use appropriate access specifiers for class members.
All class data members are explicitly specified as public, protected, or private.
In fact, when adding the class `Obstacle` the specifiers have been used to determine which attribute and methods should be accessible, and which should be only used within the class itself.

### Class constructors utilize member initialization lists.
The constructor of the class `Obstacle` initializes the shape and the position of the obstacle through member initialization lists.
It is used whenever an obstacle is created, in file Game.cpp at line 122.

### Classes abstract implementation details from their interfaces.
The `Obstacle` class uses self-explanatory names, so that the user does not need to know how the function is implemented internally.
For example void `MakeObstacle();`

### Classes encapsulate behavior.
Appropriate data is encapsulated in classes, in fact the class `Obstacle` represents an obstacle which has a shape, a position, and an area that is occupied by it.

### The project makes use of references in function declarations.
At least 2 functions use pass-by-reference.
- `bool IsInObstacleVector(int const &x, int const &y);`
- `bool CheckLocationFree(int const &x, int const &y);`

