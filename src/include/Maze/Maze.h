#pragma once
#include <vector>
using std::vector;

class Maze {
public:
  Maze(int height, int width);

  void generateMaze();
  bool isWall(int x, int y);
  vector<vector<int>> maze;
  void printMaze();

private:
  int __width;
  int __height;
};
