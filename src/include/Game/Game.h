#pragma once
#include "Window/Window.h"

class Game {

public:
  Game(Window &win);
  ~Game();
  void Loop();

private:
  Window __window;
};
