
#include "Engine.h"
#include "Maze/maze.h"
#include <iostream>
#include <raylib.h>

Texture2D walls_texture;

int main() {
  // Initialize window
  InitWindow(0, 0, "Random Maze Generator - Recursive Backtracking");

  walls_texture = LoadTexture("../Resources/walls.png");

  Cell maze[WIDTH][HEIGHT];

  // Initialize the maze with coordinates
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      maze[x][y].x = x;
      maze[x][y].y = y;
    }
  }

  // Seed the random generator with the current time
  std::random_device rd;
  std::mt19937 rng(rd());

  // Generate the maze
  GenerateMaze(maze, rng);

  // Main loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRAY);

    DrawFPS(10, 10);

    DrawMaze(maze, walls_texture);

    EndDrawing();
  }

  CloseWindow(); // Close the window
  return 0;
}
