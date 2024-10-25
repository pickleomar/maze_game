#include "Player.h"
#include <raylib.h>

Player::Player() {
  this->playerIdle = LoadTexture("../Ressources/player/player_idle.png");
  this->playerMovingDown =
      LoadTexture("../Ressources/player/player_moving_down.png");
  this->playerMovingSide =
      LoadTexture("../Ressources/player/player_moving_side.png");
  this->playerMovingUp =
      LoadTexture("../Ressources/player/player_moving_up.png");
}

Player::~Player() {
  UnloadTexture(this->playerIdle);
  UnloadTexture(this->playerMovingUp);
  UnloadTexture(this->playerMovingSide);
  UnloadTexture(this->playerMovingDown);
}

float Player::setSpeed(float speed) { this->speed = speed; }

float Player::getSpeed() { return this->speed; }

Vector2 Player::getPositionV() { return {this->posX, this->posY}; }

float Player::getPosX() { return this->posX; }

float Player::getPosY() { return this->posY; }

void Player::moveUp() { this->posY -= this->speed; }
void Player::moveDown() { this->posY += this->speed; }
void Player::moveLeft() { this->posX -= this->speed; }
void Player::moveRight() { this->posX += this->speed; }

void Player::renderPlayer() {
  Rectangle frameRec = {0.0f, 0.0f, (float)playerIdle.width / 2,
                        (float)playerIdle.height};
  DrawTexturePro(playerIdle, frameRec,
                 {posX, posY, textureSize * scale, textureSize * scale}, {0, 0},
                 0, WHITE);
}
