/*
The Game Class is responsible of instansiating the game and handling the game
loop, the variables updates , and camera movements

*/

#include "Game.h"
#include "Player/Player.h"
#include "Timer/Timer.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>

/*
Game Class Constructor.
instantiate and Load the Texture from a file to the GPU VRAM
*/
Game::Game(Window &win, Maze &maze, Player &player, float scale)
    : __window(win), __maze(maze), __player(player), scale(scale) {

  wallTexture = LoadTexture("../Resources/texture/wall.png");
  floorTexture = LoadTexture("../Resources/texture/floor_texture.png");
}

/*
Game Class destructor.
Unload the Textures from the GPU VRAM.
close the window Context.
*/
Game::~Game() {
  UnloadTexture(this->__player.playerIdle);
  UnloadTexture(this->__player.playerMovingUp);
  UnloadTexture(this->__player.playerMovingRight);
  UnloadTexture(this->__player.playerMovingLeft);
  UnloadTexture(this->__player.playerMovingDown);
  UnloadTexture(wallTexture);
  UnloadTexture(floorTexture);
  CloseWindow();
};

/*
Game Lopp.
This function is the core of the game,it handle the input for the player using
the update function

*/
void Game::Loop() {

  this->init();
  int currentFrame = 0;

  int framesCounter = 0;
  int framesSpeed = 8;
  Rectangle frameRec = {0.0f, 0.0f, (float)__player.playerIdle.width / 4,
                        (float)__player.playerIdle.height};

  Timer inputTimer;
  inputTimer.startTimer(0.12);

  Camera2D camera = {0};
  camera.target = (Vector2){(__player.getPosX() + 16) * scale,
                            (__player.getPosY() + 16) * scale};
  // camera.offset = (Vector2){400, 400};

  camera.offset = (Vector2){__window.getWindowWidth() / (2.5f),
                            __window.getWindowHeight() / (2.5f)};
  camera.rotation = 0;
  camera.zoom = 2.0f;

  Music music = LoadMusicStream("../Resources/audio/ambient.mp3");

  PlayMusicStream(music);

  while (!WindowShouldClose()) {
    UpdateMusicStream(music);
    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 5)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)__player.playerIdle.width / 4;
    }

    camera.zoom += ((float)GetMouseWheelMove() * 0.1f);

    __player.updatePlayer(__maze, camera, inputTimer);

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);

    __maze.renderMaze(wallTexture, floorTexture);

    __player.renderPlayer(frameRec);

    EndMode2D();

    if (__player.getCellX() == __maze.getWidth() - 1 &&
        __player.getCellY() == __maze.getHeight() - 2) {
      DrawText("You Win", __window.getWindowWidth() / 2,
               __window.getWindowHeight() / 2, 50, GREEN);
    }
    EndDrawing();
  }
}

// Function that runs in the start of the Game loop.
void Game::init() {
  __maze.generateMaze();
  __player.setScale(scale);
  __maze.setScale(scale);
}
