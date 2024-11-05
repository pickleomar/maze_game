#include "Game/Game.h"
#include "Player/Player.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>

// #include "ini.h"

#include <cstdlib> // For std::rand() and std::srand
#include <ctime>

int main() {

  std::srand(std::time(0));
  Window window(0, 0, "Hello World");
  Maze maze(50, 50);

  InitAudioDevice(); // Initialize audio device

  Player player;

  Game game(window, maze, player, 1);

  game.Loop();
  // UnloadMusicStream(music); // Unload music stream buffers from RAM

  // CloseAudioDevice();

  // CloseWindow();
  return 0;
}
