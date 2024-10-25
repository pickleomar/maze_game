#pragma once
#include <raylib.h>

class Player {
public:
  Player();
  ~Player();
  // Texture Started
  Texture2D playerIdle;
  Texture2D playerMovingDown;
  Texture2D playerMovingUp;
  Texture2D playerMovingSide;
  // Texture Ended
  float getSpeed();
  float setSpeed(float speed);
  Vector2 getPositionV();
  float getPosX();
  float getPosY();

  void moveUp();
  void moveDown();
  void moveRight();
  void moveLeft();

  void renderPlayer();

private:
  float speed;
  float posX;
  float posY;
  float scale;
  int textureSize = 16;
};
