#include "Maze.h"
#include <algorithm>
#include <iostream>
#include <stack>

int dx[4] = {0, 1, 0, -1}; // Directions: Up, Right, Down, Left
int dy[4] = {-1, 0, 1, 0};

Maze::Maze(int width, int height)
    : __width(width), __height(height)

{
  maze.resize(width,
              vector<int>(height, 1)); // Initialize all cells as walls (1)
}

bool Maze::isWall(int x, int y) { return this->maze[x][y] == 1; }

void Maze::generateMaze() {

  std::stack<std::pair<int, int>> stack;
  stack.push({1, 1});   // Start at the top-left corner
  this->maze[1][1] = 0; // Mark the start as a path

  while (!stack.empty()) {
    auto [x, y] = stack.top();
    stack.pop();
    std::vector<int> directions = {0, 1, 2,
                                   3}; // Directions: Up, Right, Down, Left
    std::random_shuffle(directions.begin(),
                        directions.end()); // Shuffle directions for randomness

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[directions[i]] * 2; // Calculate the next x position
      int ny = y + dy[directions[i]] * 2; // Calculate the next y position

      // Ensure the new position is within bounds and hasn't been visited
      if (nx > 0 && ny > 0 && nx < __width - 1 && ny < __height - 1 &&
          maze[nx][ny] == 1) {
        maze[x + dx[directions[i]]][y + dy[directions[i]]] = 0; // Break wall
        maze[nx][ny] = 0; // Mark the new cell as a path
        stack.push(
            {nx, ny}); // Push the new cell to the stack for future exploration
      }
    }
  }
};

void Maze::printMaze() {
  for (int y = 0; y < maze.size(); ++y) {
    for (int x = 0; x < maze[0].size(); ++x) {
      if (maze[y][x] == 1)
        std::cout << "#"; // Wall
      else
        std::cout << " "; // Path
    }
    std::cout << std::endl;
  }
}
