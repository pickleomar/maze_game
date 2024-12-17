#include "Game/Game.h"
#include "Window/Window.h"
#include "ini.h"
#include <Maze/Maze.h>
#include <raylib.h>
// #include "ini.h"
//
//
#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

int main() {

  std::srand(std::time(0));
  Window *window = new Window(1280, 720, "Hello World");
  // Maze maze(60, 40);

  InitAudioDevice(); // Initialize audio device

  Game game(window, 1);

  game.Loop();

  return 0;
}
