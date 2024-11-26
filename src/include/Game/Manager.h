#pragma once

#define MAIN_MENU_SCREEN 00
#define GAME_SCREEN 01

class Manager {
public:
  void setScreen(int screen);
  int getScreen();
  int exitGame = 0;
  int isPaused = 0;
  int showDifficltty = 0;

private:
  int currentScreen = MAIN_MENU_SCREEN;
};
