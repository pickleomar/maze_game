#define PLAYER_SIZE 16 // Define the player size to 16 for easy adjustments

// Player.cpp
#include "Player.h"
#include "Maze/Maze.h"
#include <raylib.h>

// Constructor: Initializes player attributes and loads textures for different
// states
Player::Player()
    : posX(PLAYER_SIZE), posY(PLAYER_SIZE), speed(2), scale(3),
      state(STATE_IDLE) {

  // Load player textures for different movement states
  playerIdle = LoadTexture("Resources/player/player_idle.png");
  playerMovingDown = LoadTexture("Resources/player/player_moving_down.png");
  playerMovingUp = LoadTexture("Resources/player/player_moving_up.png");
  playerMovingRight = LoadTexture("Resources/player/player_moving_right.png");
  playerMovingLeft = LoadTexture("Resources/player/player_moving_left.png");
}

// Destructor: Cleans up resources
Player::~Player() {}

// Renders the player sprite with the appropriate texture based on current state
void Player::renderPlayer(Rectangle frameRec) {
  Texture2D playerTexture;
  Rectangle playerRec = {posX * scale, posY * scale, PLAYER_SIZE * scale,
                         PLAYER_SIZE * scale};

  // Select the correct texture depending on the player's state
  switch (state) {
  case STATE_IDLE:
    playerTexture = playerIdle;
    break;
  case STATE_MOVING_DOWN:
    playerTexture = playerMovingDown;
    break;
  case STATE_MOVING_UP:
    playerTexture = playerMovingUp;
    break;
  case STATE_MOVING_RIGHT:
    playerTexture = playerMovingRight;
    break;
  case STATE_MOVING_LEFT:
    playerTexture = playerMovingLeft;
    break;
  }

  // Draw the player with the selected texture and position
  DrawTexturePro(playerTexture, frameRec, playerRec, {0, 0}, 0, WHITE);
}

// Updates the player's position and state based on input and collision checks
void Player::updatePlayer(Maze &maze, Camera2D &camera) {
  resetState(); // Reset the state to idle if no keys are pressed
  float nextX = posX, nextY = posY;

  // Check for movement input and attempt to move
  if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))) {
    nextY += speed;
    // Check if movement down collides with maze walls
    if (!isCollidingBottom(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_DOWN);
      moveDown();
    }
  }
  if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))) {
    nextY -= speed;
    // Check if movement up collides with maze walls
    if (!isCollidingTop(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_UP);
      moveUp();
    }
  }
  if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))) {
    nextX += speed;
    // Check if movement right collides with maze walls
    if (!isCollidingRight(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_RIGHT);
      moveRight();
    }
  }
  if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) {
    nextX -= speed;
    // Check if movement left collides with maze walls
    if (!isCollidingLeft(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_LEFT);
      moveLeft();
    }
  }

  // Update camera to follow player
  camera.target = (Vector2){(posX + PLAYER_SIZE / 2) * scale,
                            (posY + PLAYER_SIZE / 2) * scale};
}

// Updates the player's position and state based on input and collision checks
void Player::updatePlayerControls(Maze &maze, Camera2D &camera, bool up,
                                  bool down, bool left, bool right) {
  resetState(); // Reset the state to idle if no keys are pressed
  float nextX = posX, nextY = posY;

  // Check for movement input and attempt to move
  if (down) {
    nextY += speed;
    // Check if movement down collides with maze walls
    if (!isCollidingBottom(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_DOWN);
      moveDown();
    }
  }
  if (up) {
    nextY -= speed;
    // Check if movement up collides with maze walls
    if (!isCollidingTop(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_UP);
      moveUp();
    }
  }
  if (right) {
    nextX += speed;
    // Check if movement right collides with maze walls
    if (!isCollidingRight(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_RIGHT);
      moveRight();
    }
  }
  if (left) {
    nextX -= speed;
    // Check if movement left collides with maze walls
    if (!isCollidingLeft(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_LEFT);
      moveLeft();
    }
  }

  // Update camera to follow player
  camera.target = (Vector2){(posX + PLAYER_SIZE / 2) * scale,
                            (posY + PLAYER_SIZE / 2) * scale};
}

// Resets the player's state to idle if no movement keys are pressed
void Player::resetState() {
  if (IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_S) ||
      IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_W) ||
      IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_D) ||
      IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_A)) {
    setState(STATE_IDLE);
  }
}

// Sets the player's state (idle, moving in different directions)
void Player::setState(int state) { this->state = state; }

// Movement functions that update the player's position
void Player::moveDown() { posY += speed; }
void Player::moveUp() { posY -= speed; }
void Player::moveLeft() { posX -= speed; }
void Player::moveRight() { posX += speed; }

// Getters for the player's position
float Player::getPosX() { return posX; }
float Player::getPosY() { return posY; }

// Returns the player's current position as a cell in the maze grid
int Player::getCellX() { return posX / PLAYER_SIZE; }
int Player::getCellY() { return posY / PLAYER_SIZE; }

// Sets the scale for rendering the player (used to zoom in/out)
void Player::setScale(float scale) { this->scale = scale; }

// Collision detection functions for the player's movement
bool Player::isCollidingWithWall(float x, float y, float width, float height,
                                 Maze &maze) {
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int rightX = static_cast<int>(x + width - 1) / PLAYER_SIZE;
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int bottomY = static_cast<int>(y + height - 1) / PLAYER_SIZE;

  // Check if any of the corners of the player collide with a wall (represented
  // by 1 in the maze)
  return maze.getMaze()[topY][leftX] == 1 ||
         maze.getMaze()[topY][rightX] == 1 ||
         maze.getMaze()[bottomY][leftX] == 1 ||
         maze.getMaze()[bottomY][rightX] == 1;
}

// Checks for collisions at the top of the player
bool Player::isCollidingTop(float x, float y, float size, Maze &maze) {
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int rightX = static_cast<int>(x + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[topY][leftX] == 1 || maze.getMaze()[topY][rightX] == 1;
}

// Checks for collisions at the bottom of the player
bool Player::isCollidingBottom(float x, float y, float size, Maze &maze) {
  int bottomY = static_cast<int>(y + size - 1) / PLAYER_SIZE;
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int rightX = static_cast<int>(x + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[bottomY][leftX] == 1 ||
         maze.getMaze()[bottomY][rightX] == 1;
}

// Checks for collisions on the left side of the player
bool Player::isCollidingLeft(float x, float y, float size, Maze &maze) {
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int bottomY = static_cast<int>(y + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[topY][leftX] == 1 ||
         maze.getMaze()[bottomY][leftX] == 1;
}

// Checks for collisions on the right side of the player
bool Player::isCollidingRight(float x, float y, float size, Maze &maze) {
  int rightX = static_cast<int>(x + size - 1) / PLAYER_SIZE;
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int bottomY = static_cast<int>(y + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[topY][rightX] == 1 ||
         maze.getMaze()[bottomY][rightX] == 1;
}

// Resets the player's position to the starting point
void Player::resetPosition() {
  posX = PLAYER_SIZE;
  posY = PLAYER_SIZE;
}

void Player::setExitkey() { hasExitKey = 1; }

bool Player::getExitkey() { return hasExitKey; }
