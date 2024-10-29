#include "Game.h"
#include "Player/Player.h"
#include "Timer/Timer.h"
#include "Window/Window.h"
#include <Maze/Maze.h>

#include <cstddef>
#include <raylib.h>

Game::Game(Window &win, Maze &maze, Player &player, float scale)
    : __window(win), __maze(maze), __player(player), scale(scale) {}

Game::~Game() {
  UnloadTexture(this->__player.playerIdle);
  UnloadTexture(this->__player.playerMovingUp);
  UnloadTexture(this->__player.playerMovingRight);
  UnloadTexture(this->__player.playerMovingLeft);
  UnloadTexture(this->__player.playerMovingDown);
  CloseWindow();
};

void Game::Loop(Texture2D wallTexture, Texture2D floorTexture,
                Texture2D playerIdle) {

  this->init();
  int currentFrame = 0;

  int framesCounter = 0;
  int framesSpeed = 8;
  Rectangle frameRec = {0.0f, 0.0f, (float)playerIdle.width / 4,
                        (float)playerIdle.height};

  Timer inputTimer;
  inputTimer.startTimer(0.12);

  // Camera2D camera = {0};
  // camera.target = (Vector2){__player.getPosX() + (16 * scale),
  //                           __player.getPosy() + (16 * scale)};
  // camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenWidth()
  // / 2.0f}; camera.rotation = 0.0f; camera.zoom = 1.0f;
  while (!WindowShouldClose()) {

    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 5)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)playerIdle.width / 4;
    }

    inputTimer.UpdateTimer();
    if (inputTimer.timerDone()) {
      __player.updatePlayer(__maze);
      inputTimer.startTimer(0.12);
    }

    BeginDrawing();
    ClearBackground(BLACK);

    __maze.renderMaze(wallTexture, floorTexture);

    __player.renderPlayer(frameRec);

    EndDrawing();
  }
}

void Game::init() {
  __maze.generateMaze();
  __player.setScale(scale);
  __maze.setScale(scale);
}
