#pragma once
#include "Game/Manager.h"
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include "raylib.h"

class Game {

public:
  Game(Window &win, Maze &maze, Player &player, Manager &manager, float scale);
  ~Game();

  void init();
  void Loop();
  void DrawGame(int &framesCounter, int &framesSpeed, int &currentFrame,
                Rectangle &frameRec, Camera2D &camera, Timer &inputTimer,
                Music &music);
  void setScale(float scale);

private:
  Texture2D darknessTexture;
  Vector2 mousePosition = {0.0f, 0.0f};
  float scale = 1;
  Window __window;
  Maze __maze;
  Player __player;
  Manager __manager;
};
