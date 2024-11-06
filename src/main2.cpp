#include "Window/Window.h"
#include <Gui/Gui.h>
#include <iostream>
#include <raylib.h>

int main() {

  Window win(1270, 720, "Hello World");
  Button startBtn{"../Resources/gui/start_button.png", {100, 100}, 6};
  Button optionsBtn{"../Resources/gui/option_button.png", {100, 200}, 6};
  Button exitBtn{"../Resources/gui/exit_button.png", {100, 300}, 6};

  while (!win.ShouldClose()) {

    Vector2 mousePos = GetMousePosition();
    if (startBtn.isPressed(mousePos, IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
      std::cout << "Start Button Clicked" << "\n";
    }

    BeginDrawing();
    ClearBackground(WHITE);

    startBtn.Draw();
    optionsBtn.Draw();
    exitBtn.Draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
