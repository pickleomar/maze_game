#pragma once

#include "ini.h"

#define MAIN_MENU_SCREEN 00
#define GAME_SCREEN 01

#define EASY_DIFF 1000
#define MEDIUM_DIFF 1100
#define HARD_DIFF 1110

class Manager {
public:
  Manager();
  ~Manager();
  void setScreen(int screen);
  void setDifficulty(int diff);
  int generateMazeWidth();
  int generateMazeHeight();
  int getScreen();
  inih::INIReader iniFile;
  int exitGame = 0;
  int isPaused = 0;
  int showDifficltty = 0;

private:
  // Maze *maze;
  int difficulty = EASY_DIFF;
  int currentScreen = MAIN_MENU_SCREEN;
};
