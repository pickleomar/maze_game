#pragma once
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include "raylib.h"

class Game {

public:
  Game(Window &win, Maze &maze, Player &player, float scale);
  ~Game();

  void init();
  void Loop();
  void DrawFrame(int framesCounter, int framesSpeed, int currentFrame,
                 Rectangle frameRec, Camera2D camera, Timer inputTimer,
                 Music music);
  void setScale(float scale);

private:
  Texture2D darknessTexture;
  float scale = 1;
  Window __window;
  Maze __maze;
  Player __player;
};
