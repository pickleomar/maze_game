#include "Game.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>
#include <vector>

Game::Game(Window &win, Maze &maze) : __window(win), __maze(maze) {}
Game::~Game() {};

void Game::Loop(Texture2D wallTexture, Texture2D floorTexture,
                Texture2D playerIdle) {
  int playerX = 16;
  int playerY = 16;
  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_DOWN)) {
      playerY += 16;
    }
    if (IsKeyPressed(KEY_UP)) {
      playerY -= 16;
    }
    if (IsKeyPressed(KEY_RIGHT)) {
      playerX += 16;
    }
    if (IsKeyPressed(KEY_LEFT)) {
      playerX -= 16;
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    this->__maze.renderMaze(wallTexture, floorTexture);
    DrawTextureRec(playerIdle, {0, 0, 16, 16}, {(float)playerX, (float)playerY},
                   WHITE);
    EndDrawing();
  }
}

void Game::init() { __maze.generateMaze(); }
