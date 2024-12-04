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
