#include "Game.h"
#include "Player/Player.h"
#include "Timer/Timer.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
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

  Camera2D camera = {0};
  camera.target = (Vector2){(__player.getPosX() + 16) * scale,
                            (__player.getPosY() + 16) * scale};
  camera.offset = (Vector2){__window.getWindowWidth() / (2.0f),
                            __window.getWindowHeight() / (2.0f)};
  camera.rotation = 0;
  camera.zoom = 2.0f;

  while (!WindowShouldClose()) {
    // if (IsKeyPressedRepeat(KEY_SPACE)) {
    //   camera.zoom = 0.8;
    // }

    // if (IsKeyPressed(KEY_L)) {
    //   camera.zoom = 2;
    // }

    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 5)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)playerIdle.width / 4;
    }

    camera.zoom += ((float)GetMouseWheelMove() * 0.1f);

    __player.updatePlayer(__maze, camera, inputTimer);

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);

    __maze.renderMaze(wallTexture, floorTexture);

    __player.renderPlayer(frameRec);
    EndMode2D();
    EndDrawing();
  }
}

void Game::init() {
  __maze.generateMaze();
  __player.setScale(scale);
  __maze.setScale(scale);
}
