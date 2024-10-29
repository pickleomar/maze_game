#pragma once
#include "Maze/Maze.h"
#include <raylib.h>

#define STATE_IDLE 00001
#define STATE_MOVING_UP 00010
#define STATE_MOVING_DOWN 00100
#define STATE_MOVING_RIGHT 01000
#define STATE_MOVING_LEFT 10000

class Player {
public:
  Player();
  ~Player();

  // Texture Started
  Texture2D playerIdle;
  Texture2D playerMovingDown;
  Texture2D playerMovingUp;
  Texture2D playerMovingRight;
  Texture2D playerMovingLeft;

  // Movement
  void moveDown();
  void moveUp();
  void moveLeft();
  void moveRight();
  //

  float getPosX();
  float getPosY();
  int getCellX();
  int getCellY();

  void renderPlayer(Rectangle frameRec);
  void updatePlayer(Maze &maze);
  void setScale(float scale);
  void setState(int state);

private:
  float posX;
  float posY;
  int state = STATE_IDLE;
  float speed;
  float scale;
};
