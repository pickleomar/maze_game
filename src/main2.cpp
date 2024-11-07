#include "Gui/Gui.h"
#include "raylib.h"

#define NUM_FRAMES                                                             \
  3 // Number of frames (rectangles) for the button sprite texture

int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight,
             "raylib [textures] example - sprite button");

  Button btnStart("../Resources/button_start.png", 6, {100, 100});
  Button btnOptions("../Resources/button_options.png", 6, {100, 200});
  Button btnExit("../Resources/button_exit.png", 6, {100, 300});
  Vector2 mousePoint = {0.0f, 0.0f};

  SetTargetFPS(60);
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {

    mousePoint = GetMousePosition();

    btnStart.checkState(mousePoint);
    btnOptions.checkState(mousePoint);
    btnExit.checkState(mousePoint);

    if (btnStart.isPressed()) {
      TraceLog(LOG_INFO, "Start Button Clicked");
    }

    if (btnOptions.isPressed()) {
      TraceLog(LOG_INFO, "Options Button Clicked");
    }
    if (btnExit.isPressed()) {
      TraceLog(LOG_INFO, "Exit Button Clicked");
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    btnStart.drawbutton();
    btnOptions.drawbutton();
    btnExit.drawbutton();

    EndDrawing();
    //----------------------------------------------------------------------------------
  }
  CloseWindow(); // Close window and OpenGL context

  return 0;
}
