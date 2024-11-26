#pragma once
#include "Button.h"
#include "Game/Manager.h"
#include "raylib.h"
class Menu {
public:
  Menu();
  ~Menu();
  void DrawMainMenu(Manager &manager);
  void DrawGameBar(Manager &manager);
  void DrawDifficultyMenu(Manager &manager);

private:
  Button btnStart;
  Button btnExit;
  Button btnOptions;
  Button btnPause;
  Button btnHome;

  Button btnEasy;
  Button btnMedium;
  Button btnHard;

  Vector2 mainMenuPosition = {800, 160};

  Sound clickSound;
};
