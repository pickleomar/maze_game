#pragma once
#include "raylib.h"
#include <vector>
using std::vector;

class Maze {
public:
  Maze(int height, int width);

  void generateMaze();
  bool isWall(int x, int y);
  void printMazeToConsole();
  void renderMaze(Texture2D wallTexture, Texture2D floorTexture);
  int getWidth();
  int getHeight();
  vector<vector<int>> getMaze();

  void setScale(float scale);

private:
  vector<vector<int>> maze;
  float scale = 1;
  int __width;
  int __height;
};
