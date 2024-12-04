#pragma once

#include "ini.h"

#define MAIN_MENU_SCREEN 00
#define GAME_SCREEN 01

class Manager {
public:
  Manager();
  ~Manager();
  void setScreen(int screen);
  int getScreen();
  inih::INIReader iniFile;
  int exitGame = 0;
  int isPaused = 0;
  int showDifficlttyMenu = 0;

private:
  // Maze *maze;
  int currentScreen = MAIN_MENU_SCREEN;
};
