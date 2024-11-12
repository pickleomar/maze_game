#include "Game/Game.h"
#include "Game/Manager.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>

// #include "ini.h"
//
//
#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

int main() {

  std::srand(std::time(0));
  Window window(1270, 720, "Hello World");
  Maze maze(30, 20);
  Manager manager;

  InitAudioDevice(); // Initialize audio device

  Player player;

  Game game(window, maze, player, manager, 1);

  game.Loop();

  return 0;
}
