
// Player.h - ensure these declarations exist in your header file
#define PLAYER_SIZE 16 // Define player size to 16 for easy adjustments

// Player.cpp
#include "Player.h"
#include "Maze/Maze.h"
#include <raylib.h>

// There is a BUG if the speed is setted to a odd number
Player::Player()
    : posX(PLAYER_SIZE), posY(PLAYER_SIZE), speed(2), scale(3),
      state(STATE_IDLE) {

  playerIdle = LoadTexture("Resources/player/player_idle.png");
  playerMovingDown = LoadTexture("Resources/player/player_moving_down.png");
  playerMovingUp = LoadTexture("Resources/player/player_moving_up.png");
  playerMovingRight = LoadTexture("Resources/player/player_moving_right.png");
  playerMovingLeft = LoadTexture("Resources/player/player_moving_left.png");
}

Player::~Player() {}

void Player::renderPlayer(Rectangle frameRec) {
  Texture2D playerTexture;
  Rectangle playerRec = {posX * scale, posY * scale, PLAYER_SIZE * scale,
                         PLAYER_SIZE * scale};

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

  DrawTexturePro(playerTexture, frameRec, playerRec, {0, 0}, 0, WHITE);
}

void Player::updatePlayer(Maze &maze, Camera2D &camera, Timer &inputTimer) {
  resetState();
  float nextX = posX, nextY = posY;

  if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))) {
    nextY += speed;
    // if (!isCollidingWithWall(nextX, nextY, PLAYER_SIZE, PLAYER_SIZE, maze)) {
    if (!isCollidingBottom(nextX, nextY, PLAYER_SIZE, maze)) {

      setState(STATE_MOVING_DOWN);

      moveDown();
    }
  }
  if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))) {
    nextY -= speed;
    // if (!isCollidingWithWall(nextX, nextY, PLAYER_SIZE, PLAYER_SIZE, maze)) {
    if (!isCollidingTop(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_UP);
      moveUp();
    }
  }
  if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))) {
    nextX += speed;
    // if (!isCollidingWithWall(nextX, nextY, PLAYER_SIZE, PLAYER_SIZE, maze)) {
    if (!isCollidingRight(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_RIGHT);
      moveRight();
    }
  }
  if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) {
    nextX -= speed;
    // if (!isCollidingWithWall(nextX, nextY, PLAYER_SIZE, PLAYER_SIZE, maze)) {
    if (!isCollidingLeft(nextX, nextY, PLAYER_SIZE, maze)) {
      setState(STATE_MOVING_LEFT);
      moveLeft();
    }
  }
  camera.target = (Vector2){(posX + PLAYER_SIZE / 2) * scale,
                            (posY + PLAYER_SIZE / 2) * scale};
}

void Player::resetState() {
  if (IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_S) ||
      IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_W) ||
      IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_D) ||
      IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_A)) {
    setState(STATE_IDLE);
  }
}

void Player::setState(int state) { this->state = state; }

void Player::moveDown() { posY += speed; }
void Player::moveUp() { posY -= speed; }
void Player::moveLeft() { posX -= speed; }
void Player::moveRight() { posX += speed; }

float Player::getPosX() { return posX; }
float Player::getPosY() { return posY; }

int Player::getCellX() { return posX / PLAYER_SIZE; }
int Player::getCellY() { return posY / PLAYER_SIZE; }

void Player::setScale(float scale) { this->scale = scale; }

// Enhanced collision check for 16x16 player sprite
bool Player::isCollidingWithWall(float x, float y, float width, float height,
                                 Maze &maze) {
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int rightX = static_cast<int>(x + width - 1) / PLAYER_SIZE;
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int bottomY = static_cast<int>(y + height - 1) / PLAYER_SIZE;

  return maze.getMaze()[topY][leftX] == 1 ||
         maze.getMaze()[topY][rightX] == 1 ||
         maze.getMaze()[bottomY][leftX] == 1 ||
         maze.getMaze()[bottomY][rightX] == 1;
}

bool Player::isCollidingTop(float x, float y, float size, Maze &maze) {
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int rightX = static_cast<int>(x + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[topY][leftX] == 1 || maze.getMaze()[topY][rightX] == 1;
}

bool Player::isCollidingBottom(float x, float y, float size, Maze &maze) {
  int bottomY = static_cast<int>(y + size - 1) / PLAYER_SIZE;
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int rightX = static_cast<int>(x + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[bottomY][leftX] == 1 ||
         maze.getMaze()[bottomY][rightX] == 1;
}

bool Player::isCollidingLeft(float x, float y, float size, Maze &maze) {
  int leftX = static_cast<int>(x) / PLAYER_SIZE;
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int bottomY = static_cast<int>(y + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[topY][leftX] == 1 ||
         maze.getMaze()[bottomY][leftX] == 1;
}

bool Player::isCollidingRight(float x, float y, float size, Maze &maze) {
  int rightX = static_cast<int>(x + size - 1) / PLAYER_SIZE;
  int topY = static_cast<int>(y) / PLAYER_SIZE;
  int bottomY = static_cast<int>(y + size - 1) / PLAYER_SIZE;

  return maze.getMaze()[topY][rightX] == 1 ||
         maze.getMaze()[bottomY][rightX] == 1;
}
