#pragma once
#include "raylib.h"
#include <vector>

#define EASY_DIFF 1000
#define MEDIUM_DIFF 1100
#define HARD_DIFF 1110

using std::vector;

class Maze {
public:
  Maze();

  // Textures
  Texture2D wallTexture;
  Texture2D keyTexture;
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

  void generateMaze();       // Generate the Maze
  bool isWall(int x, int y); //  check if it's a wall
  void printMazeToConsole();
  void renderMaze();             // render the maze to the Game
  int getWidth();                // return the width
  int getHeight();               // return the height
  vector<vector<int>> getMaze(); // return maze vector
  void resetMaze();              // resizing the Maze to new width and height
  void unlockMaze();

  void setDifficulty(int diff); // change difficulty

  void setScale(float scale); // (deprecated) change scale
  bool showKey = true;

private:
  vector<vector<int>> maze; // 2d vector the the maze
  float scale = 1;
  int __width = -1;
  int __height = -1;
  int difficulty = EASY_DIFF; // difficulty
};
