#pragma once
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include "raylib.h"
#include <vector>

class Game {

public:
  Game(Window &win, Maze &maze, Player &player, float scale);
  ~Game();

  void init();
  void Loop();
  void setScale(float scale);

private:
  Texture2D wallTexture;
  Texture2D floorTexture;
  float scale = 1;
  Window __window;
  Maze __maze;
  Player __player;
};
