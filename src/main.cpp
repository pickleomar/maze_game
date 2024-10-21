#include "Game/Game.h"
#include "Window/Window.h"

#include <raylib.h>

int main() {
  Window window(1270, 720, "Hello World");

  Game game(window);
  game.Loop();

  CloseWindow();
  return 0;
}
