#include "Game.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>
#include <vector>

Game::Game(Window &win) : __window(win) {}
Game::~Game() {};

void Game::Loop(std::vector<std::vector<int>> maze, Texture2D floorTexture,
                Texture2D wallTexture) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    int originX = 0;
    int originY = 0;

    for (int y = 0; y < maze.size(); ++y) {
      for (int x = 0; x < maze[0].size(); ++x) {
        if (maze[y][x] == 1) {
          DrawTexture(wallTexture, originX + (x * 16), originY + (y * 16),
                      RAYWHITE);
        } // std::cout << "#"; // Wall
        else {
          DrawTexture(floorTexture, originX + (x * 16), originY + (y * 16),
                      RAYWHITE);
        }
        // std::cout << " "; // Path
      }
      // std::cout << std::endl;
    }

    EndDrawing();
  }
}
