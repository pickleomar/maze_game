#pragma once
#include "Game/Manager.h"
#include "raylib.h"
#include <vector>

#define EASY_DIFF 1000
#define MEDIUM_DIFF 1100
#define HARD_DIFF 1110

using std::vector;

class Maze {
public:
  // Maze(int height, int width);
  Maze();

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
  int getWidth();
  int getHeight();
  vector<vector<int>> getMaze();
  void resizeMaze();

  void setDifficulty(int diff);

  void setScale(float scale);

private:
  vector<vector<int>> maze;
  float scale = 1;
  int __width = -1;
  int __height = -1;
  int difficulty = EASY_DIFF;
};
