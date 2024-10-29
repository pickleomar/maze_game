#include "Player.h"
#include "Maze/Maze.h"
#include <raylib.h>

Player::Player() : posX(16), posY(16), speed(16), scale(3) {
  this->playerIdle = LoadTexture("../Resources/player/player_idle.png");
  this->playerMovingDown =
      LoadTexture("../Resources/player/player_moving_down.png");
  this->playerMovingUp =
      LoadTexture("../Resources/player/player_moving_up.png");
  this->playerMovingRight =
      LoadTexture("../Resources/player/player_moving_right.png");
  this->playerMovingLeft =
      LoadTexture("../Resources/player/player_moving_left.png");
}

Player::~Player() {}

void Player::renderPlayer(Rectangle frameRec) {
  Texture2D playerTexture;

  Rectangle playerRec;
  if (this->state == STATE_IDLE) {
    playerTexture = playerIdle;
    playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
  } else if (this->state == STATE_MOVING_DOWN) {
    playerTexture = playerMovingDown;
    playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
  } else if (this->state == STATE_MOVING_UP) {
    playerTexture = playerMovingUp;
    playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
  } else if (this->state == STATE_MOVING_RIGHT) {
    playerTexture = playerMovingRight;
    playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
  } else if (this->state == STATE_MOVING_LEFT) {
    playerTexture = playerMovingLeft;
    playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
  }

  DrawTexturePro(playerTexture, frameRec, playerRec, {0, 0}, 0, WHITE);
}

void Player::updatePlayer(Maze &maze) {

  if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) &&
      (maze.getMaze()[getCellY() + 1][getCellX()] != 1)) {

    setState(STATE_MOVING_DOWN);
    moveDown();
  }

  if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) &&
      (maze.getMaze()[getCellY() - 1][getCellX()] != 1)) {

    setState(STATE_MOVING_UP);
    moveUp();
  }

  if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) &&
      (maze.getMaze()[getCellY()][getCellX() + 1] != 1)) {

    setState(STATE_MOVING_RIGHT);
    moveRight();
  }

  if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) &&
      (maze.getMaze()[getCellY()][getCellX() - 1] != 1)) {

    setState(STATE_MOVING_LEFT);
    moveLeft();
  }
}

void Player::setState(int state) { this->state = state; }

void Player::moveDown() { posY += speed; }
void Player::moveUp() { posY -= speed; }
void Player::moveLeft() { posX -= speed; }
void Player::moveRight() { posX += speed; }

float Player::getPosX() { return posX; }

float Player::getPosY() { return posY; }

int Player::getCellX() { return posX / 16; }
int Player::getCellY() { return posY / 16; }

void Player::setScale(float scale) { this->scale = scale; }
