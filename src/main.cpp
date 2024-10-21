#include "Game/Game.h"
#include "Window/Window.h"
#include <Maze/Maze.h>

#include <iostream>
#include <raylib.h>

#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

int main() {
  std::srand(std::time(0));
  Maze maze(30, 60);
  maze.generateMaze();
  // Window window(1270, 720, "Hello World");

  // Game game(window);
  // game.Loop();

  // CloseWindow();
  maze.printMaze();
  return 0;
}
