#include "Map/map.h"
#include <Engine.h>
#include <iostream>
#include <raylib.h>

Texture2D walls_texture;
Texture2D floor_texture;

int main() {
  Engine::Window window(1270, 720, "Maze Game");
  walls_texture = LoadTexture("../Resources/walls.png");
  floor_texture = LoadTexture("../Resources/floor.png");

  while (!window.ShouldClose()) {
    BeginDrawing();

    ClearBackground(GRAY);

    EndDrawing();
  }

  return 0;
}
