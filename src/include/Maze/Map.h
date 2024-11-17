#pragma once

#include "Maze/Maze.h"
#include "Player/Player.h"
#include "raylib.h"

class Map {

public:
  void update();
  void renderMap(Maze &maze, Player &player);
  // void setBlockSize
private:
  bool showMap = 0;
};
