#include "Game.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <iostream>
#include <raylib.h>
#include <vector>

Game::Game(Window &win, Maze &maze, Player &player)
    : __window(win), __maze(maze), __player(player) {}

Game::~Game() {
  UnloadTexture(this->__player.playerIdle);
  UnloadTexture(this->__player.playerMovingUp);
  UnloadTexture(this->__player.playerMovingSide);
  UnloadTexture(this->__player.playerMovingDown);
  CloseWindow();
};

void Game::Loop(Texture2D wallTexture, Texture2D floorTexture,
                Texture2D playerIdle) {

  while (!WindowShouldClose()) {

    int leftX = static_cast<int>(__player.getPosX()) / 16;
    int rightX = static_cast<int>(__player.getPosX() + 16) / 16;
    int topY = static_cast<int>(__player.getPosY()) / 16;
    int bottomY = static_cast<int>(__player.getPosY() + 16) / 16;

    if (IsKeyDown(KEY_DOWN) && (__maze.maze[bottomY][leftX] != 1)) {
      __player.moveDown();
    }
    if (IsKeyDown(KEY_UP) && (__maze.maze[topY][leftX] != 1)) {
      __player.moveUp();
    }
    if (IsKeyDown(KEY_RIGHT) && (__maze.maze[topY][rightX] != 1)) {
      __player.moveRight();
    }
    if (IsKeyDown(KEY_LEFT) && (__maze.maze[topY][leftX] != 1)) {
      __player.moveLeft();
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    __maze.renderMaze(wallTexture, floorTexture);
    __player.renderPlayer();

    EndDrawing();
  }
}

void Game::init() { __maze.generateMaze(); }
