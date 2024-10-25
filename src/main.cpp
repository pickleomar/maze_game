#include "Game/Game.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>

#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

Texture2D floor_texture;
Texture2D wall_texture;
Texture2D player_Idle;

int main() {

  std::srand(std::time(0));
  Window window(1270, 720, "Hello World");
  Maze maze(20, 10);

  floor_texture = LoadTexture("../Resources/texture/floor_texture.png");
  wall_texture = LoadTexture("../Resources/texture/wall.png");

  player_Idle = LoadTexture("../Resources/player/Player_idle.png");

  Game game(window, maze);
  game.init();
  game.Loop(wall_texture, floor_texture, player_Idle);

  // CloseWindow();
  return 0;
}
