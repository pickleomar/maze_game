#include "Game/Game.h"
#include "Window/Window.h"
#include <Maze/Maze.h>

#include <iostream>
#include <raylib.h>

#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 1

Texture2D floor_texture;
Texture2D wall_texture;
Texture2D player_Idle;

int main() {

  std::srand(std::time(0));
  Window window(1270, 720, "Hello World");
  Maze maze(50, 30);
  maze.generateMaze();
  // maze.printMaze();
  // floor_texture = LoadTexture("../Resources/texture/floor_texture.png");
  // wall_texture = LoadTexture("../Resources/texture/wall.png");

  player_Idle = LoadTexture("../Resources/player/Player_idle.png");
  Rectangle frameRec = {0.0f, 0.0f, (float)player_Idle.width / 2,
                        (float)player_Idle.height};

  int currentFrame = 0;

  int framesCounter = 0;
  int framesSpeed = 8;

  while (!window.ShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)player_Idle.width / 2;
    }

    if (IsKeyPressed(KEY_RIGHT))
      framesSpeed++;
    else if (IsKeyPressed(KEY_LEFT))
      framesSpeed--;

    if (framesSpeed > MAX_FRAME_SPEED)
      framesSpeed = MAX_FRAME_SPEED;
    else if (framesSpeed < MIN_FRAME_SPEED)
      framesSpeed = MIN_FRAME_SPEED;
    // DrawTextureEx(player_Idle, {100, 100}, 0, 10, WHITE);
    //
    DrawTextureRec(player_Idle, frameRec, {350.0f, 280.0f}, WHITE);

    EndDrawing();
  }
  // Game game(window);
  // game.Loop(maze.maze, floor_texture, wall_texture);

  CloseWindow();
  return 0;
}
