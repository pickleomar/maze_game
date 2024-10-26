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
  // Movement
  void moveDown();
  void moveUp();
  void moveLeft();
  void moveRight();
  //

  int getPosX();
  int getPosY();
  // Texture Ended
  void renderPlayer();

private:
  float posX;
  float posY;
  float speed;
};
