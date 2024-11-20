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

private:
  Button btnStart;
  Button btnExit;
  Button btnOptions;
  Button btnPause;
  Button btnHome;
  Vector2 mainMenuPosition = {800, 160};

  Sound clickSound;
};
