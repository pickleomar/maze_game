#pragma once
#include "Button.h"
#include "Game/Manager.h"
#include "Player/Player.h"
#include "raylib.h"
#include <Maze/Maze.h>
class Menu {
public:
  Menu(Maze *maze, Player *player);
  ~Menu();
  void DrawMainMenu(Manager &manager);
  void DrawGameBar(Manager &manager);
  void DrawDifficultyMenu(Manager &manager);

private:
  // Menu Buttons
  Button btnStart;
  Button btnExit;
  Button btnOptions;

  Button btnPause;
  Button btnRegenerate;
  Button btnHome;
  Button btnfullScreen;

  Button btnEasy;
  Button btnMedium;
  Button btnHard;

  // The Main Menu position on the Screen
  Vector2 mainMenuPosition = {800, 160};

  Sound clickSound;
  // Maze Pointer

  Maze *maze;
  // Player Poiter
  Player *player;
};
