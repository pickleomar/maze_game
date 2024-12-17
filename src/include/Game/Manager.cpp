/*
The Game Manager Class is Holding all the logic handeling the game state
*/

#include "Manager.h"
#include <filesystem>
#include <fstream>

// Manager Constructor Creates a data.ini file for storing the info about player
// score  etc ..
Manager::Manager() {
  if (!std::filesystem::exists("./data.ini")) {
    std::ofstream file("./data.ini");
    file.close();

    iniFile = {"./data.ini"};
  } else {
    iniFile = {"./data.ini"};
  }
}

// Manager Destructor
Manager::~Manager() {}

// Set The current Screen
void Manager::setScreen(int screen) { this->currentScreen = screen; }

// Get The current Screen
int Manager::getScreen() { return currentScreen; }

int Manager::getWinState() { return wining; }
void Manager::changeToWinState() { wining = 1; }
void Manager::resetWinState() { wining = 0; }
