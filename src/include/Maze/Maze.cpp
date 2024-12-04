#include "Maze.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <raylib.h>
#include <stack>
#include <vector>

// Resources Files ///////////////////////////
#include "texture/bottom_wall.h"
#include "texture/floor_texture.h"
#include "texture/left_bottom_corner.h"
#include "texture/left_top_corner.h"
#include "texture/left_wall.h"
#include "texture/right_bottom_corner.h"
#include "texture/right_top_corner.h"
#include "texture/right_wall.h"
#include "texture/top_wall.h"
#include "texture/wall_latterale.h"

#include "texture/wall.h"
//////////////////////////////////////////////

#define TILE_SIZE 16

int dx[4] = {0, 1, 0, -1}; // Directions: Up, Right, Down, Left
int dy[4] = {-1, 0, 1, 0};

Maze::Maze() {

  __width = 15;
  __height = 15;

  maze.resize(__height);
  for (auto &row : maze) {
    row.resize(__width, 1); // Resize each row to the new number of columns,
                            // initialize new elements to 0
  }

  Image wall = {0};
  wall.format = WALL_FORMAT;
  wall.height = WALL_HEIGHT;
  wall.width = WALL_WIDTH;
  wall.data = WALL_DATA;
  wall.mipmaps = 1;
  wallTexture = LoadTextureFromImage(wall);

  Image floor = {0};
  floor.format = FLOOR_TEXTURE_FORMAT;
  floor.height = FLOOR_TEXTURE_HEIGHT;
  floor.width = FLOOR_TEXTURE_WIDTH;
  floor.data = FLOOR_TEXTURE_DATA;
  floor.mipmaps = 1;
  floorTexture = LoadTextureFromImage(floor);

  Image leftWall = {0};
  leftWall.format = LEFT_WALL_FORMAT;
  leftWall.height = LEFT_WALL_HEIGHT;
  leftWall.width = LEFT_WALL_WIDTH;
  leftWall.data = LEFT_WALL_DATA;
  leftWall.mipmaps = 1;
  leftWallTexture = LoadTextureFromImage(leftWall);

  Image rightWall = {0};
  rightWall.format = RIGHT_WALL_FORMAT;
  rightWall.height = RIGHT_WALL_HEIGHT;
  rightWall.width = RIGHT_WALL_WIDTH;
  rightWall.data = RIGHT_WALL_DATA;
  rightWall.mipmaps = 1;

  rightWallTexture = LoadTextureFromImage(rightWall);

  Image leftTopCornerWall = {0};
  leftTopCornerWall.format = LEFT_TOP_CORNER_FORMAT;
  leftTopCornerWall.height = LEFT_TOP_CORNER_HEIGHT;
  leftTopCornerWall.width = LEFT_TOP_CORNER_WIDTH;
  leftTopCornerWall.data = LEFT_TOP_CORNER_DATA;
  leftTopCornerWall.mipmaps = 1;

  leftTopCornerTexture = LoadTextureFromImage(leftTopCornerWall);

  Image rightTopCornerWall = {0};
  rightTopCornerWall.format = RIGHT_TOP_CORNER_FORMAT;
  rightTopCornerWall.height = RIGHT_TOP_CORNER_HEIGHT;
  rightTopCornerWall.width = RIGHT_TOP_CORNER_WIDTH;
  rightTopCornerWall.data = RIGHT_TOP_CORNER_DATA;
  rightTopCornerWall.mipmaps = 1;

  rightTopCornerTexture = LoadTextureFromImage(rightTopCornerWall);

  Image rightBottomCornerWall = {0};
  rightBottomCornerWall.format = RIGHT_BOTTOM_CORNER_FORMAT;
  rightBottomCornerWall.height = RIGHT_BOTTOM_CORNER_HEIGHT;
  rightBottomCornerWall.width = RIGHT_BOTTOM_CORNER_WIDTH;
  rightBottomCornerWall.data = RIGHT_BOTTOM_CORNER_DATA;
  rightBottomCornerWall.mipmaps = 1;

  rightBottomCornerTexture = LoadTextureFromImage(rightBottomCornerWall);

  Image leftBottomCornerWall = {0};
  leftBottomCornerWall.format = LEFT_BOTTOM_CORNER_FORMAT;
  leftBottomCornerWall.height = LEFT_BOTTOM_CORNER_HEIGHT;
  leftBottomCornerWall.width = LEFT_BOTTOM_CORNER_WIDTH;
  leftBottomCornerWall.data = LEFT_BOTTOM_CORNER_DATA;
  leftBottomCornerWall.mipmaps = 1;

  leftBottomCornerTexture = LoadTextureFromImage(leftBottomCornerWall);

  Image topWall = {0};
  topWall.format = TOP_WALL_FORMAT;
  topWall.height = TOP_WALL_HEIGHT;
  topWall.width = TOP_WALL_WIDTH;
  topWall.data = TOP_WALL_DATA;
  topWall.mipmaps = 1;

  topWallTexture = LoadTextureFromImage(topWall);

  Image bottomWall = {0};
  bottomWall.format = BOTTOM_WALL_FORMAT;
  bottomWall.height = BOTTOM_WALL_HEIGHT;
  bottomWall.width = BOTTOM_WALL_WIDTH;
  bottomWall.data = BOTTOM_WALL_DATA;
  bottomWall.mipmaps = 1;

  bottomWallTexture = LoadTextureFromImage(bottomWall);

  Image latteraleWall = {0};
  latteraleWall.format = WALL_LATTERALE_FORMAT;
  latteraleWall.height = WALL_LATTERALE_HEIGHT;
  latteraleWall.width = WALL_LATTERALE_WIDTH;
  latteraleWall.data = WALL_LATTERALE_DATA;
  latteraleWall.mipmaps = 1;
  wallLatteraleTexture = LoadTextureFromImage(latteraleWall);
}

void Maze::generateMaze() {
  for (int y = 0; y < __height; ++y) {
    for (int x = 0; x < __width; ++x) {
      maze[y][x] = 1; // Reset all cells to walls
    }
  }

  // maze.resize(__height, vector<int>(__width, 1));

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
  maze[1][0] = 0;

  int exit = rand() % 3;

  if (exit == 0) {
    maze[__height - 2][__width - 1] = 0;

  } else if (exit == 1) {
    maze[1][__width - 1] = 0;

  } else {
    maze[__height - 2][0] = 0;
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

void Maze::printMazeToConsole() {
  // generateMaze();
  for (int y = 0; y < maze.size(); ++y) {
    for (int x = 0; x < maze[0].size(); ++x) {
      if (maze[y][x] == 1)
        std::cout << "# "; // Wall
      else
        std::cout << "  "; // Path
    }
    std::cout << std::endl;
  }
}

int Maze::getWidth() { return __width; }

int Maze::getHeight() { return __height; }

vector<vector<int>> Maze::getMaze() { return maze; }

void Maze::setScale(float scale) { this->scale = scale; }

bool Maze::isWall(int x, int y) { return maze[x][y] == 1; }

void Maze::setDifficulty(int diff) { this->difficulty = diff; }

void Maze::resizeMaze() {
  if (difficulty == EASY_DIFF) {
    TraceLog(LOG_INFO, "EASY DIFF");
    __width = 15;
    __height = 15;
  } else if (difficulty == MEDIUM_DIFF) {
    TraceLog(LOG_INFO, "MEDIUM DIFF");
    __width = 20;
    __height = 20;
  } else {
    TraceLog(LOG_INFO, "HARD DIFF");
    __width = 30;
    __height = 30;
  }

  if (__width % 2 == 0)
    __width++; // Ensure maze width is odd for proper path generation
  if (__height % 2 == 0)
    __height++; // Ensure maze height is odd for proper path generation

  maze.resize(__height);
  for (auto &row : maze) {
    row.resize(__width, 1); // Resize each row to the new number of columns,
                            // initialize new elements to 0
  }
}
