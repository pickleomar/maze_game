#pragma once
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include "raylib.h"
#include <vector>

class Game {

public:
  Game(Window &win, Maze &maze, Player &player);
  ~Game();

  void init();
  void Loop(Texture2D wallTexture, Texture2D floorTexture,
            Texture2D playerIdle);

private:
  Window __window;
  Maze __maze;
  Player __player;
};
