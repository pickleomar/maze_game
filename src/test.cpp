// #include "Gui/Button.h"
// #include "raylib.h"

// int main() {
//   InitWindow(800, 600, "Button Example");
//   Texture2D buttonTexture = LoadTexture("Resources/gui/button_exit.png");

//   Button myButton(200, 200, buttonTexture.width, buttonTexture.height,
//                   buttonTexture);

//   while (!WindowShouldClose()) {
//     BeginDrawing();
//     ClearBackground(RAYWHITE);

//     myButton.Update();
//     myButton.Draw();

//     if (myButton.IsClicked()) {
//       DrawText("Button Clicked!", 350, 300, 20, RED);
//     }

//     EndDrawing();
//   }

//   UnloadTexture(buttonTexture);
//   CloseWindow();

//   return 0;
// }
