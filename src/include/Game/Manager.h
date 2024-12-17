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
  inih::INIReader iniFile;    // data.ini file
  int exitGame = 0;           // exit game state
  int isPaused = 0;           // is the game paused 1, 0 is running
  int showDifficlttyMenu = 0; // show difficulty menu !!
  int windowExitRequested = 0;

  int getWinState();
  void changeToWinState();
  void resetWinState();

private:
  int currentScreen = MAIN_MENU_SCREEN; // Current screen State
  int wining = 0;
};
