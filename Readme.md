# Credits
This Project Was Made By 3 students : 
### ZARQI Ezzoubair.
### AZZAOUI Mohamed Omar .
### AMAMI Yousra .

## Overview

Maze Game is a 2D maze exploration game where the player navigates through randomly generated mazes with increasing difficulty levels. The game utilizes a procedural generation algorithm to create unique mazes each time the player starts a new game. The objective is to reach the exit while avoiding walls and solving increasingly complex mazes.

## Features

- **Procedural Maze Generation:** Each maze is randomly generated, ensuring a unique experience every time the game is played.
- **Dynamic Difficulty Levels:** Choose between three difficulty levels (Easy, Medium, and Hard) that affect the complexity of the maze and the challenge of solving it.
- **Player Movement:** The player can move up, down, left, or right in the maze using the arrow keys or WASD keys.
- **Collision Detection:** The game includes a collision system to prevent the player from walking through walls.
- **Key Mechanic:** In higher difficulty levels, the player must find a key to unlock the exit.
- **Regenerate Maze:** The player can regenerate the maze at any time via a button, adding replayability.
- **Animated Player Sprite:** The player has idle and moving animations based on their current movement direction.
- **2.5D Effect:** The game implements a basic 2.5D effect to give the maze a sense of depth, enhancing the visual experience.

## Controls

- **Arrow keys** or **WASD keys** for movement:
  - **UP** or **W** – Move up
  - **DOWN** or **S** – Move down
  - **LEFT** or **A** – Move left
  - **RIGHT** or **D** – Move right
- **R** to regenerate the maze.
- **ESC** to pause or exit the game.

## Difficulty Levels

- **Easy:** Larger paths and fewer walls, suitable for beginners.
- **Medium:** A balanced level with moderately complex mazes and occasional key-based exits.
- **Hard:** Narrower paths with more obstacles, key constraints for unlocking the exit, and a more challenging layout.

## Game Development

### Technologies Used

- **C++**: Main programming language.
- **Raylib**: 2D game library used for rendering the game, handling user input, and managing animations.

### Key Features Implemented

1. **Maze Generation Algorithm**:

   - The maze is generated using a randomized depth-first search (DFS) algorithm with backtracking, ensuring a challenging and varied maze layout.
   - The maze size and complexity are adjustable, depending on the selected difficulty.

2. **Collision Detection**:

   - The player's movements are restricted by the maze walls using a collision detection system.
   - The player can’t move through walls and must navigate around them to find the exit.

3. **Camera Control**:

   - The camera is dynamically updated as the player moves, ensuring the player is always centered in the view.

4. **Player Movement and Animations**:

   - The player sprite has different animations based on the movement state (idle, moving up, down, left, right).
   - Smooth movement is achieved with a basic frame-rate-independent system.

5. **Dynamic Maze Regeneration**:

   - The player can press a button to regenerate a new maze layout, providing new challenges every time.

6. **Key Mechanic**:

   - In Medium and Hard difficulties, the player must locate a key in the maze to unlock the exit.

### Game Loop

The main game loop runs continuously, checking for user inputs, updating the player's position, regenerating the maze when necessary, and rendering the updated game state.

---

## How to Build and Run

### Prerequisites

- **C++ compiler**: Ensure you have a C++ compiler installed (e.g., GCC or MSVC).
- **CMake**: Install CMake for cross-platform project building.
- **Raylib**: Download and install Raylib from [https://www.raylib.com/](https://www.raylib.com/).
  - Follow the installation instructions provided on the Raylib website for your specific operating system.

### Building the Game with CMake

1. Clone or download the repository:

   ```bash
   git clone https://github.com/regisx001/maze-game.git
   cd maze-game
   ```

2. Create a build directory and navigate to it:

   ```bash
   mkdir build
   ```

3. Configure the project using CMake:

   ```bash
   cmake -S . -B build
   ```

4. Build the project:

   ```bash
   cmake --build build/.
   ```

5. Run the game:

   ```bash
   ./game
   ```

---

## Files and Directories

- **main.cpp**: Main entry point for the game.
- **Player.h**: Contains the player's movement logic, collision handling, and animation.
- **Maze.h**: Contains the maze generation and rendering logic.
- **Timer.h**: Manages timing for movement and input delays (if applicable).
- **Resources/**: Contains texture files for the player and maze walls.
- **Assets/**: Contains all the assets such as textures and sprites.

---

## Known Issues

- Sometimes, the maze generation may cause the entire grid to reset to walls (issue with maze bounds handling).
- Some animations may not be perfectly smooth on low-end hardware.

---

## Future Improvements

- **Multiplayer Support**: Adding co-op or competitive multiplayer gameplay.
- **Enemies**: Implement AI enemies that chase the player.
- **Power-Ups**: Add items that help the player, such as speed boosts or wall-breaking abilities.
- **Sound Effects and Music**: Adding audio to enhance the player experience.
- **More Maze Variants**: Implement different maze styles (e.g., hexagonal mazes, circular mazes, etc.).

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Acknowledgements

- **Raylib**: For providing a powerful, easy-to-use library for 2D game development.
- **OpenGameArt**: For the free assets used in the game (if applicable).
- **Stack Overflow and GitHub**: For community support and solutions.

