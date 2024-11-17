#pragma once
#include "raylib.h"
#include <vector>
using std::vector;

class Maze {
public:
  Maze(int height, int width);

  Texture2D wallTexture;
  Texture2D topWallTexture;
  Texture2D bottomWallTexture;
  Texture2D leftWallTexture;
  Texture2D rightWallTexture;
  Texture2D floorTexture;
  Texture2D leftTopCornerTexture;
  Texture2D rightTopCornerTexture;
  Texture2D rightBottomCornerTexture;
  Texture2D leftBottomCornerTexture;
  Texture2D wallLatteraleTexture;

  void generateMaze();
  bool isWall(int x, int y);
  void printMazeToConsole();
  void renderMaze();
  void renderMaze02();
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
