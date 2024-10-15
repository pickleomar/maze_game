#include "Map/map.cpp"
#include "Map/map.h"
#include <Engine.h>
#include <iostream>
#include <raylib.h>

Texture2D walls;
Texture2D floor_texture;

int main() {
  Engine::Window window(1270, 720, "Maze Game");

  walls = LoadTexture("../Resources/walls.png");
  floor_texture = LoadTexture("../Resources/floor.png");

  while (!window.ShouldClose()) {
    BeginDrawing();

    DrawTexture(walls, 0, 0, WHITE);

    MapTile().DrawLeftWall(walls);
    ClearBackground(GRAY);

    EndDrawing();
  }

  return 0;
}
