#include "Manager.h"
#include <filesystem>
#include <fstream>

Manager::Manager() {
  if (!std::filesystem::exists("./data.ini")) {
    std::ofstream file("./data.ini");
    file.close();

    iniFile = {"./data.ini"};
  } else {
    iniFile = {"./data.ini"};
  }
}
Manager::~Manager() {}

void Manager::setScreen(int screen) { this->currentScreen = screen; }

int Manager::getScreen() { return currentScreen; }

void Manager::setDifficulty(int diff) { difficulty = diff; }

int Manager::generateMazeHeight() {
  switch (difficulty) {
  case EASY_DIFF:
    return 30;
  case MEDIUM_DIFF:
    return 50;
  case HARD_DIFF:
    return 80;
  }
  // return 20;
}
int Manager::generateMazeWidth() {
  switch (difficulty) {
  case EASY_DIFF:
    return 30;
  case MEDIUM_DIFF:
    return 50;
  case HARD_DIFF:
    return 80;
  }
}
