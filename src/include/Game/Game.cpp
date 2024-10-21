#include "Game.h"
#include "Window/Window.h"
#include <raylib.h>

Game::Game(Window &win) : __window(win) {}
Game::~Game() {};

void Game::Loop() {
  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    EndDrawing();
  }
}
