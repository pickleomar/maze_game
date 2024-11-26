#include "raylib.h"
#include "traps/Spike_Trap.h"
int main() {

  InitWindow(1270, 729, " const char *title");

  Texture2D trapTexture;

  Image trap = {
      .data = SPIKE_TRAP_DATA,
      .width = SPIKE_TRAP_WIDTH,
      .height = SPIKE_TRAP_HEIGHT,
      .mipmaps = 1,
      .format = SPIKE_TRAP_FORMAT,
  };

  trapTexture = LoadTextureFromImage(trap);

  // trapTexture = LoadTexture("./Resources/traps/Spike_Trap.png");

  Rectangle frameRec = {0.0f, 0.0f, (float)trapTexture.width / 14,
                        (float)trapTexture.height};
  int currentFrame = 0;

  int framesCounter = 0;
  int framesSpeed = 1;

  while (!WindowShouldClose()) {
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 28)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)trapTexture.width / 14;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexture(trapTexture, 100, 100, RAYWHITE);

    DrawTextureRec(trapTexture, frameRec, {400, 400}, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
