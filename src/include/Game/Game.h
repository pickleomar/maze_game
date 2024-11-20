#pragma once
#include "Game/Manager.h"
#include "Maze/Map.h"
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
  void DrawGame(Rectangle &frameRec);
  void setScale(float scale);

private:
  Texture2D darknessTexture;
  Vector2 mousePosition = {0.0f, 0.0f};
  float scale = 1;
  Window __window;
  Maze __maze;
  Player __player;
  Manager __manager;
  Camera2D camera = {0};
  Map __map;
};
