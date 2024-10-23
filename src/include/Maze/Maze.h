#pragma once
#include "raylib.h"
#include <vector>
using std::vector;

class Maze {
public:
  Maze(int height, int width);

  void generateMaze();
  bool isWall(int x, int y);
  vector<vector<int>> maze;
  void printMaze();
  void renderMaze(Texture2D wallTexture, Texture2D floorTexture);

private:
  int __width;
  int __height;
};
