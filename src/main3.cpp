#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

const int WIDTH = 41;     // Maze width (without borders)
const int HEIGHT = 31;    // Maze height (without borders)
const int CELL_SIZE = 20; // Size of each cell
std::vector<std::vector<int>>
    maze(HEIGHT + 2, std::vector<int>(WIDTH + 2, 1)); // 1 = wall, 0 = path

struct Player {
  int x; // Player's x position in maze coordinates
  int y; // Player's y position in maze coordinates
};

void generateMaze(int x, int y) {
  int dx[] = {2, -2, 0, 0};
  int dy[] = {0, 0, 2, -2};

  // Shuffle directions
  for (int i = 0; i < 4; ++i) {
    int j = rand() % 4;
    std::swap(dx[i], dx[j]);
    std::swap(dy[i], dy[j]);
  }

  maze[y][x] = 0; // Mark current cell as path

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    // Ensure we are within the bounds of the maze
    if (nx > 0 && nx < WIDTH + 1 && ny > 0 && ny < HEIGHT + 1 &&
        maze[ny][nx] == 1) {
      maze[y + dy[i] / 2][x + dx[i] / 2] = 0; // Remove wall between the cells
      generateMaze(nx, ny);                   // Recursive call
    }
  }
}

bool canMove(int newX, int newY) {
  // Check if the new position is within maze bounds and not a wall
  return maze[newY][newX] == 0;
}

int main() {
  // Initialization
  InitWindow(0, 0, "Maze Game");
  SetTargetFPS(60); // Set the target frames per second

  srand(static_cast<unsigned int>(time(0))); // Seed random number generator
  generateMaze(1, 1);                        // Start generating from (1, 1)

  // Initialize player position
  Player player = {1, 1}; // Start the player in the maze

  while (!WindowShouldClose()) { // Main game loop
    // Player movement input
    if (IsKeyDown(KEY_UP) && canMove(player.x, player.y - 1)) {
      player.y--; // Move up
    }
    if (IsKeyDown(KEY_DOWN) && canMove(player.x, player.y + 1)) {
      player.y++; // Move down
    }
    if (IsKeyDown(KEY_LEFT) && canMove(player.x - 1, player.y)) {
      player.x--; // Move left
    }
    if (IsKeyDown(KEY_RIGHT) && canMove(player.x + 1, player.y)) {
      player.x++; // Move right
    }

    // Drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw the maze
    for (int y = 0; y < HEIGHT + 2; ++y) {
      for (int x = 0; x < WIDTH + 2; ++x) {
        if (maze[y][x] == 1) {
          DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE,
                        BLACK); // Draw wall
        }
      }
    }

    // Draw the player
    DrawRectangle(player.x * CELL_SIZE, player.y * CELL_SIZE, CELL_SIZE,
                  CELL_SIZE, BLUE); // Draw player

    EndDrawing();
  }

  // De-Initialization
  CloseWindow(); // Close window and OpenGL context

  return 0;
}
