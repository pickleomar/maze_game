#pragma once
#include "Maze/Maze.h"
#include <raylib.h>

// Constants defining the player's state
#define STATE_IDLE 00001         // Player is idle (not moving)
#define STATE_MOVING_UP 00010    // Player is moving up
#define STATE_MOVING_DOWN 00100  // Player is moving down
#define STATE_MOVING_RIGHT 01000 // Player is moving right
#define STATE_MOVING_LEFT 10000  // Player is moving left

class Player {
public:
  // Constructor and Destructor
  Player();  // Constructor to initialize player object
  ~Player(); // Destructor to clean up any resources

  // Textures representing the player's state
  Texture2D playerIdle;        // Texture when the player is idle
  Texture2D playerMovingDown;  // Texture when the player is moving down
  Texture2D playerMovingUp;    // Texture when the player is moving up
  Texture2D playerMovingRight; // Texture when the player is moving right
  Texture2D playerMovingLeft;  // Texture when the player is moving left

  // Movement functions for each direction
  void moveDown();  // Move the player down
  void moveUp();    // Move the player up
  void moveLeft();  // Move the player left
  void moveRight(); // Move the player right

  // Getter functions to retrieve player's position and cell position
  float getPosX(); // Get the player's X position
  float getPosY(); // Get the player's Y position
  int getCellX();  // Get the player's X cell in the maze
  int getCellY();  // Get the player's Y cell in the maze

  // Render player using a rectangle (frame) for animation
  void renderPlayer(Rectangle frameRec); // Draw player based on animation frame

  // Update player's movement and interaction with the maze
  void updatePlayer(Maze &maze, Camera2D &camera);
  void updatePlayerControls(Maze &maze, Camera2D &camera, bool up, bool down,
                            bool left, bool right);

  // Collision detection functions for each side of the player
  bool isCollidingWithWall(float x, float y, float width, float height,
                           Maze &maze);
  bool isCollidingTop(float x, float y, float size,
                      Maze &maze); // Check collision at the top
  bool isCollidingBottom(float x, float y, float size,
                         Maze &maze); // Check collision at the bottom
  bool isCollidingLeft(float x, float y, float size,
                       Maze &maze); // Check collision on the left
  bool isCollidingRight(float x, float y, float size,
                        Maze &maze); // Check collision on the right

  // Reset the player's state and position
  void resetState();    // Reset the player's movement state (idle)
  void resetPosition(); // Reset the player's position to initial starting point

  // Set player's scale (size)
  void setScale(float scale); // Scale the player texture size

  // Set the player's current state (moving or idle)
  void setState(int state); // Change the player's movement state

private:
  // Private variables to store player's position, speed, and state
  float posX;             // Player's current X position in the world
  float posY;             // Player's current Y position in the world
  int state = STATE_IDLE; // Current movement state (initially idle)
  float speed;            // Player's speed (movement speed)
  float scale; // Scale factor for the player (adjusts size of the player)
};
