#include "Maze.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <raylib.h>
#include <stack>
#include <vector>

int dx[4] = {0, 1, 0, -1}; // Directions: Up, Right, Down, Left
int dy[4] = {-1, 0, 1, 0};

Maze::Maze(int width, int height) {
  if (width % 2 == 0)
    width++; // Ensure maze width is odd for proper path generation
  if (height % 2 == 0)
    height++; // Ensure maze height is odd for proper path generation
  this->__width = width;
  this->__height = height;

  maze.resize(height,
              vector<int>(width, 1)); // Initialize all cells as walls (1)
}

void Maze::generateMaze() {
  std::stack<std::pair<int, int>> stack;

  // Step 1: Start with a random cell in the grid (ensure it is an odd cell for
  // proper path generation)
  int startX = 1;
  int startY = 1;

  stack.push({startX, startY});
  maze[startY][startX] = 0; // Mark the start cell as a path

  std::random_device rd;
  std::mt19937 g(rd());

  while (!stack.empty()) {
    auto [x, y] = stack.top();
    stack.pop();

    std::vector<int> directions = {0, 1, 2, 3};
    std::shuffle(directions.begin(), directions.end(),
                 g); // Shuffle directions for random exploration

    bool hasUnvisitedNeighbors =
        false; // Track if we have any unvisited neighbors

    // Step 2: For each shuffled direction, check for valid neighbors
    for (int i = 0; i < 4; i++) {
      int nx =
          x +
          dx[directions[i]] *
              2; // Look two cells away (so the maze has space between walls)
      int ny = y + dy[directions[i]] * 2;

      // Check if the new position is within bounds and hasn't been visited
      if (nx > 0 && ny > 0 && nx < __width - 1 && ny < __height - 1 &&
          maze[ny][nx] == 1) {
        // Break the wall between the current cell and the new cell
        maze[y + dy[directions[i]]][x + dx[directions[i]]] =
            0;            // Mark the wall as a path
        maze[ny][nx] = 0; // Mark the new cell as a path

        // Push the new cell onto the stack to explore it further
        stack.push(
            {x, y}); // Push the current cell (for backtracking if necessary)
        stack.push({nx, ny}); // Push the new cell

        hasUnvisitedNeighbors = true;
        break; // Stop after finding a valid neighbor to ensure deeper
               // exploration
      }
    }

    // If no unvisited neighbors, we will automatically backtrack via stack
  }

  // Set an Entrence for the player
  this->maze[1][0] = 0;
  // Set an Exit for the player
  this->maze[__height - 2][__width - 1] = 0;
};

void Maze::renderMaze(Texture2D wallTexture, Texture2D floorTexture) {
  int originX = 0;
  int originY = 0;

  for (int y = 0; y < maze.size(); ++y) {
    for (int x = 0; x < maze[0].size(); ++x) {
      if (maze[y][x] == 1) {
        DrawTextureEx(wallTexture,
                      {(float)(originX + (x * 16 * scale)),
                       (float)(originY + (y * 16 * scale))},
                      0, scale, RAYWHITE);

      } else {
        DrawTextureEx(floorTexture,
                      {(float)(originX + (x * 16 * scale)),
                       (float)(originY + (y * 16 * scale))},
                      0, scale, RAYWHITE);
      }
      // std::cout << " "; // Path
    }
    // std::cout << std::endl;
  }
}

void Maze::printMazeToConsole() {
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

int Maze::getWidth() { return __width; }

int Maze::getHeight() { return __height; }

vector<vector<int>> Maze::getMaze() { return maze; }

void Maze::setScale(float scale) { this->scale = scale; }

bool Maze::isWall(int x, int y) { return this->maze[x][y] == 1; }
