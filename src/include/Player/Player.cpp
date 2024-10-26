#include "Player.h"
#include <raylib.h>

Player::Player() : posX(16), posY(16), speed(1), scale(2) {
  this->playerIdle = LoadTexture("../Resources/player/player_idle.png");
  this->playerMovingDown =
      LoadTexture("../Resources/player/player_moving_down.png");
  this->playerMovingSide =
      LoadTexture("../Resources/player/player_moving_side.png");
  this->playerMovingUp =
      LoadTexture("../Resources/player/player_moving_up.png");
}

Player::~Player() {}

void Player::renderPlayer(Rectangle frameRec) {

  Rectangle playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
  DrawTexturePro(playerIdle, frameRec, playerRec, {0, 0}, 0, WHITE);

  DrawRectangleLinesEx(playerRec, 3, RED);
}

void Player::moveDown() { posY += speed; }
void Player::moveUp() { posY -= speed; }
void Player::moveLeft() { posX -= speed; }
void Player::moveRight() { posX += speed; }

int Player::getPosX() { return posX; }

int Player::getPosY() { return posY; }
