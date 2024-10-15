#include "raylib.h"
#include "raymath.h" // Required for: Vector2Clamp()
#include <iostream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  const int windowWidth = 0;
  const int windowHeight = 0;

  // Enable config flags for resizable window and vertical synchro
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(windowWidth, windowHeight,
             "raylib [core] example - window scale letterbox");
  SetWindowMinSize(1270, 720);
  SetWindowSize(GetMonitorWidth(GetCurrentMonitor()) / 2,
                GetMonitorHeight(GetCurrentMonitor()) / 2);

  int gameScreenWidth = 1270;
  int gameScreenHeight = 720;

  // Render texture initialization, used to hold the rendering result so we can
  // easily resize it
  RenderTexture2D target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
  SetTextureFilter(target.texture,
                   TEXTURE_FILTER_BILINEAR); // Texture scale filter to use

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // Compute required framebuffer scaling
    float scale = MIN((float)GetScreenWidth() / gameScreenWidth,
                      (float)GetScreenHeight() / gameScreenHeight);

    if (IsKeyPressed(KEY_SPACE)) {
      std::cout << "Space key cliked \n";
    }

    // Update virtual mouse (clamped mouse value behind game screen)
    Vector2 mouse = GetMousePosition();
    Vector2 virtualMouse = {0};
    virtualMouse.x =
        (mouse.x - (GetScreenWidth() - (gameScreenWidth * scale)) * 0.5f) /
        scale;
    virtualMouse.y =
        (mouse.y - (GetScreenHeight() - (gameScreenHeight * scale)) * 0.5f) /
        scale;
    virtualMouse = Vector2Clamp(
        virtualMouse, (Vector2){0, 0},
        (Vector2){(float)gameScreenWidth, (float)gameScreenHeight});

    // Apply the same transformation as the virtual mouse to the real mouse
    // (i.e. to work with raygui)
    // SetMouseOffset(-(GetScreenWidth() - (gameScreenWidth*scale))*0.5f,
    // -(GetScreenHeight() - (gameScreenHeight*scale))*0.5f);
    // SetMouseScale(1/scale, 1/scale);
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    // Draw everything in the render texture, note this will not be rendered on
    // screen, yet
    BeginTextureMode(target);
    ClearBackground(RAYWHITE); // Clear render texture background color

    DrawText("If executed inside a window,\nyou can resize the window,\nand "
             "see the screen scaling!",
             10, 25, 20, WHITE);
    DrawText(TextFormat("Default Mouse: [%i , %i]", (int)mouse.x, (int)mouse.y),
             350, 25, 20, GREEN);
    DrawText(TextFormat("Virtual Mouse: [%i , %i]", (int)virtualMouse.x,
                        (int)virtualMouse.y),
             350, 55, 20, YELLOW);
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK); // Clear screen background

    // Draw render texture to screen, properly scaled
    DrawTexturePro(
        target.texture,
        (Rectangle){0.0f, 0.0f, (float)target.texture.width,
                    (float)-target.texture.height},
        (Rectangle){
            (GetScreenWidth() - ((float)gameScreenWidth * scale)) * 0.5f,
            (GetScreenHeight() - ((float)gameScreenHeight * scale)) * 0.5f,
            (float)gameScreenWidth * scale, (float)gameScreenHeight * scale},
        (Vector2){0, 0}, 0.0f, WHITE);
    EndDrawing();
    //--------------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  UnloadRenderTexture(target); // Unload render texture

  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
