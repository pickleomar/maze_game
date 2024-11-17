#include "Maze.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <raylib.h>
#include <stack>
#include <vector>

#define TILE_SIZE 16

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
  wallTexture = LoadTexture("Resources/texture/wall.png");
  floorTexture = LoadTexture("Resources/texture/floor_texture.png");
  leftWallTexture = LoadTexture("Resources/texture/left_wall.png");
  rightWallTexture = LoadTexture("Resources/texture/right_wall.png");
  leftTopCornerTexture = LoadTexture("Resources/texture/left_top_corner.png");
  rightTopCornerTexture = LoadTexture("Resources/texture/right_top_corner.png");
  rightBottomCornerTexture =
      LoadTexture("Resources/texture/right_bottom_corner.png");
  leftBottomCornerTexture =
      LoadTexture("Resources/texture/left_bottom_corner.png");

  topWallTexture = LoadTexture("Resources/texture/top_wall.png");
  bottomWallTexture = LoadTexture("Resources/texture/bottom_wall.png");
  wallLatteraleTexture = LoadTexture("Resources/texture/wall_latterale.png");
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

  int exit = rand() % 3;

  if (exit == 0) {
    this->maze[__height - 2][__width - 1] = 0;

  } else if (exit == 1) {
    this->maze[1][__width - 1] = 0;

  } else {
    this->maze[__height - 2][0] = 0;
  }
  // Set an Exit for the player
  // this->maze[__height - 2][__width - 1] = 0;
};

void Maze::renderMaze() {
  int originX = 0;
  int originY = 0;

  for (int y = 0; y < maze.size(); ++y) {
    for (int x = 0; x < maze[0].size(); ++x) {
      if (maze[y][x] == 1) {

        // Handle Drawing sides wall
        if (x == 0) {
          DrawTextureEx(leftWallTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        } else if (x == __width - 1) {
          DrawTextureEx(rightWallTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        } else {
          DrawTextureEx(wallTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        }

        // Handle Drawing top and bottom walls
        if (y == 0) {
          DrawTextureEx(topWallTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        } else if (y == __height - 1) {
          DrawTextureEx(bottomWallTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        }

        // Handle Drawing Corners
        if (x == 0 && y == 0) {
          DrawTextureEx(leftTopCornerTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        } else if (x == 0 && y == __height - 1) {
          DrawTextureEx(leftBottomCornerTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        } else if (x == __width - 1 && y == 0) {
          DrawTextureEx(rightTopCornerTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        } else if (x == __width - 1 && y == __height - 1) {
          DrawTextureEx(rightBottomCornerTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        }

        if (x != 0 && x != __width - 1 && maze[y][x - 1] == 0 &&
            maze[y][x + 1] == 0) {
          DrawTextureEx(wallLatteraleTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        }

        if (x != 0 && x != __width - 1 && maze[y][x - 1] == 0 &&
            maze[y][x + 1] == 0 && maze[y + 1][x] == 0) {
          DrawTextureEx(wallTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        }

        if (x != 0 && x != __width - 1 && maze[y][x - 1] == 0 &&
            ((maze[y][x] == 1 && maze[y][x + 1] == 0 && maze[y + 1][x] == 1 &&
              maze[y - 1][x] == 1) ||
             maze[y][x] == 1 && maze[y][x - 1] == 0 && maze[y + 1][x] == 1 &&
                 maze[y - 1][x] == 1)) {
          DrawTextureEx(wallLatteraleTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        }

      } else {
        DrawTextureEx(floorTexture,
                      {(float)(originX + (x * TILE_SIZE * scale)),
                       (float)(originY + (y * TILE_SIZE * scale))},
                      0, scale, RAYWHITE);
      }
    }
  }
}

void Maze::renderMaze02() {
  int originX = 0;
  int originY = 0;

  for (int y = 0; y < maze.size(); ++y) {
    for (int x = 0; x < maze[0].size(); ++x) {
      if (maze[y][x] == 1) {

        if (x != 0 && x != __width - 1 && maze[y][x - 1] == 0 &&
            maze[y][x + 1] == 0) {
          if (maze[y + 1][x] == 1) {

            DrawTextureEx(wallLatteraleTexture,
                          {(float)(originX + 8 + (x * TILE_SIZE * scale)),
                           (float)(originY + (y * TILE_SIZE * scale))},
                          0, scale, RAYWHITE);
          } else {
            DrawTextureEx(bottomWallTexture,
                          {(float)(originX + 8 + (x * TILE_SIZE * scale)),
                           (float)(originY + (y * TILE_SIZE * scale))},
                          0, scale, RAYWHITE);
          }
        } else {

          DrawTextureEx(wallTexture,
                        {(float)(originX + (x * TILE_SIZE * scale)),
                         (float)(originY + (y * TILE_SIZE * scale))},
                        0, scale, RAYWHITE);
        }

      } else {
        DrawTextureEx(floorTexture,
                      {(float)(originX + (x * TILE_SIZE * scale)),
                       (float)(originY + (y * TILE_SIZE * scale))},
                      0, scale, RAYWHITE);
      }
    }
  }
}

void Maze::printMazeToConsole() {
  generateMaze();
  for (int y = 0; y < maze.size(); ++y) {
    for (int x = 0; x < maze[0].size(); ++x) {
      if (maze[y][x] == 1)
        std::cout << "1 "; // Wall
      else
        std::cout << "0 "; // Path
    }
    std::cout << std::endl;
  }
}

int Maze::getWidth() { return __width; }

int Maze::getHeight() { return __height; }

vector<vector<int>> Maze::getMaze() { return maze; }

void Maze::setScale(float scale) { this->scale = scale; }

bool Maze::isWall(int x, int y) { return this->maze[x][y] == 1; }
