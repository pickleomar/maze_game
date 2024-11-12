#pragma once

#include "Button.h"
#include "Game/Manager.h"
#include "raylib.h"
class Menu {
public:
  Menu();
  ~Menu();
  void DrawMenu(Manager &manager);

private:
  Button btnStart;
  Button btnExit;
  Button btnOptions;
  Vector2 mainMenuPosition = {800, 160};

  Sound clickSound;
};
