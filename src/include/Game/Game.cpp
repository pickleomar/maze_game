/*
The Game Class is responsible of instansiating the game and handling the game
loop, the variables updates , and camera movements

*/

#include "Game.h"
#include "Game/Manager.h"
#include "Gui/Button.h"
#include "Gui/Gui.h"
#include "Maze/Map.h"
#include "Player/Player.h"
#include "Timer/Timer.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

/*
Game Class Constructor.
instantiate and Load the Texture from a file to the GPU VRAM
*/
Game::Game(Window &win, Maze &maze, Player &player, float scale)
    : __window(win), __maze(maze), __player(player), scale(scale) {
  __manager = Manager();
  __map = Map();
  darknessTexture = LoadTexture("Resources/texture/darkness.png");
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
  UnloadTexture(this->__maze.wallTexture);
  UnloadTexture(this->__maze.floorTexture);
  UnloadTexture(this->__maze.leftWallTexture);
  UnloadTexture(this->__maze.rightWallTexture);
  UnloadTexture(this->__maze.leftTopCornerTexture);
  UnloadTexture(this->__maze.leftBottomCornerTexture);
  UnloadTexture(this->__maze.rightTopCornerTexture);
  UnloadTexture(this->__maze.rightBottomCornerTexture);
  UnloadTexture(this->__maze.topWallTexture);
  UnloadTexture(this->__maze.bottomWallTexture);
  CloseWindow();
};

void Game::DrawGame(int &framesCounter, int &framesSpeed, int &currentFrame,
                    Rectangle &frameRec, Timer &inputTimer, Music &music) {

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
  __map.update();

  BeginDrawing();
  ClearBackground(BLACK);

  for (int j = 0; j <= 25; j++) {
    for (int i = 0; i <= 40; i++) {
      DrawTexture(darknessTexture, i * 64, j * 64, RAYWHITE);
    }
  }

  BeginMode2D(camera);

  __maze.renderMaze();

  __player.renderPlayer(frameRec);

  EndMode2D();

  if (__player.getCellX() == __maze.getWidth() - 1 &&
      __player.getCellY() == __maze.getHeight() - 2) {
    DrawText("You Win", __window.getWindowWidth() / 2,
             __window.getWindowHeight() / 2, 50, GREEN);
  }

  __map.renderMap(__maze, __player);

  EndDrawing();
}

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
  inputTimer.startTimer(0.2);

  camera.target = (Vector2){(__player.getPosX() + 16) * scale,
                            (__player.getPosY() + 16) * scale};
  // camera.offset = (Vector2){400, 400};

  camera.offset = (Vector2){__window.getWindowWidth() / (3.0f),
                            __window.getWindowHeight() / (3.0f)};
  camera.rotation = 0;
  camera.zoom = 3.0f;

  Music music = LoadMusicStream("Resources/audio/ambient.mp3");

  PlayMusicStream(music);

  Menu menu;

  bool showMap = false;

  while (!WindowShouldClose() && !__manager.exitGame) {
    // Updates

    // Ends Updates
    if (__manager.getScreen() == MAIN_MENU_SCREEN)
      menu.DrawMenu(__manager);
    else {
      // HideCursor();
      DrawGame(framesCounter, framesSpeed, currentFrame, frameRec, inputTimer,
               music);
    }
  }
}

// Function that runs in the start of the Game loop.
void Game::init() {
  __maze.generateMaze();
  __player.setScale(scale);
  __maze.setScale(scale);
}
