#pragma once
#include "Game/Manager.h"
#include "Gui/Gui.h"
#include "Maze/Map.h"
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include "raylib.h"

class Game {

public:
  Game(Window *win, float scale);
  ~Game();

  void init();
  void Loop();
  void DrawGame(Rectangle &frameRec);
  void setScale(float scale);

private:
  Texture2D darknessTexture;
  Vector2 mousePosition = {0.0f, 0.0f};
  float scale = 1;
  Window *__window;
  // The Maze class need reworking due to conflict in adding level and endless
  // mode.
  Maze *__maze;
  // TODO Later.

  Player *__player;
  Manager *__manager;
  Camera2D camera = {0};
  Map *__map;
  Menu *__menu;
};
