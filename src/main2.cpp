#include "Window/Window.h"
#include <iostream>
#include <raylib.h>

#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 1

Texture2D player_Idle;
Image player;

int main() {

  Window win(1270, 720, "Hello World");
  player_Idle = LoadTexture("../Resources/player/player_moving_side.png");

  float playerX = 100;
  float playerY = 100;
  float speed = 1.5;

  // Sprite Animation
  int currentFrame = 0;

  int framesCounter = 0;
  int framesSpeed = 8;
  Rectangle frameRec = {0.0f, 0.0f, (float)player_Idle.width / 4,
                        (float)player_Idle.height};

  // Sprite ANimation ended
  Rectangle colRec = {200, 200, 100, 100};
  float scale = 2;
  while (!win.ShouldClose()) {
    // FrameAnimations
    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 5)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)player_Idle.width / 4;
    }

    // FrameAnimationsEnded
    if (IsKeyDown(KEY_DOWN)) {
      playerY += speed;
    }

    if (IsKeyDown(KEY_UP)) {
      playerY -= speed;
    }

    if (IsKeyDown(KEY_RIGHT)) {
      playerX += speed;
    }

    if (IsKeyDown(KEY_LEFT)) {
      playerX -= speed;
    }
    BeginDrawing();
    ClearBackground(WHITE);
    // DrawTextureRec(player_Idle, frameRec, {playerX, playerY}, WHITE);
    DrawTexturePro(player_Idle, frameRec, {playerX, playerY, 32, 32}, {0, 0}, 0,
                   WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
