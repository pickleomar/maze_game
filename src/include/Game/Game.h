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
  void Loop(Texture2D wallTexture, Texture2D floorTexture,
            Texture2D playerIdle);
  void setScale(float scale);

private:
  float scale = 1;
  Window __window;
  Maze __maze;
  Player __player;
};
