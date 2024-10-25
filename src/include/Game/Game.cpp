#include "Game.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <iostream>
#include <raylib.h>
#include <vector>

Game::Game(Window &win, Maze &maze) : __window(win), __maze(maze) {}
Game::~Game() { CloseWindow(); };

void Game::Loop(Texture2D wallTexture, Texture2D floorTexture,
                Texture2D playerIdle) {
  int playerX = 16;
  int playerY = 16;
  float speed = 1.5;

  while (!WindowShouldClose()) {

    int leftX = static_cast<int>(playerX) / 16;
    int rightX = static_cast<int>(playerX + 15) / 16;
    int topY = static_cast<int>(playerY) / 16;
    int bottomY = static_cast<int>(playerY + 15) / 16;
    Rectangle playerRec = {(float)playerX, (float)playerY, 20, 20};

    BeginDrawing();
    ClearBackground(RAYWHITE);
    this->__maze.renderMaze(wallTexture, floorTexture);

    if (IsKeyDown(KEY_DOWN) && (__maze.maze[bottomY][leftX] != 1)) {
      playerY += speed;
    }
    if (IsKeyDown(KEY_UP) && (__maze.maze[topY][leftX] != 1)) {
      playerY -= speed;
    }
    if (IsKeyDown(KEY_RIGHT) && (__maze.maze[topY][rightX] != 1)) {
      playerX += speed;
    }
    if (IsKeyDown(KEY_LEFT) && (__maze.maze[topY][leftX] != 1)) {
      playerX -= speed;
    }
    DrawTextureRec(playerIdle, {0, 0, 16, 16}, {(float)playerX, (float)playerY},
                   WHITE);
    EndDrawing();
  }
}

void Game::init() { __maze.generateMaze(); }
