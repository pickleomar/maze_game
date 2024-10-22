#include "Game/Game.h"
#include "Window/Window.h"
#include <Maze/Maze.h>

#include <iostream>
#include <raylib.h>

#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

Texture2D floor_texture;
Texture2D wall_texture;

int main() {

  std::srand(std::time(0));
  Window window(1920, 1080, "Hello World");
  Maze maze(100, 50);
  maze.generateMaze();
  // maze.printMaze();
  floor_texture = LoadTexture("../Resources/texture/floor_texture.png");
  wall_texture = LoadTexture("../Resources/texture/wall.png");

  Game game(window);
  game.Loop(maze.maze, floor_texture, wall_texture);

  CloseWindow();
  return 0;
}
