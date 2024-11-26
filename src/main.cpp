#include "Game/Game.h"
#include "Game/Manager.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include "ini.h"
#include <Maze/Maze.h>
#include <filesystem>
#include <fstream>
#include <raylib.h>
// #include "ini.h"
//
//
#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

int main() {

  if (!std::filesystem::exists("./data.ini")) {
    std::ofstream file("./data.ini");
    file.close();
  } else {
    inih::INIReader r{"./data.ini"};
  }

  std::srand(std::time(0));
  Window *window = new Window(1270, 720, "Hello World");
  Maze maze(60, 40);

  InitAudioDevice(); // Initialize audio device

  Game game(window, maze, 1);

  game.Loop();

  return 0;
}
