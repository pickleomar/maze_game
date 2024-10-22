#pragma once
#include "Window/Window.h"
#include "raylib.h"
#include <vector>

class Game {

public:
  Game(Window &win);
  ~Game();
  void Loop(std::vector<std::vector<int>> maze, Texture2D floorTexture,
            Texture2D wallTexture);

private:
  Window __window;
};
