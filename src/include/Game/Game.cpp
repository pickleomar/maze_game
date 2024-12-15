/*
The Game Class is responsible of instansiating the game and handling the game
loop, the variables updates , and camera movements

*/

#include "Game.h"
#include "Game/Manager.h"
#include "Gui/Menus.h"
#include "Player/Player.h"
#include "Timer/Timer.h"
#include "Window/Window.h"
#include <Maze/Maze.h>
#include <raylib.h>

#include "texture/darkness.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

/*
Game Class Constructor.
instantiate and Load the Texture from a file to the GPU VRAM
*/
Game::Game(Window *win, float scale) : __window(win), scale(scale) {
  __player = new Player();
  __manager = new Manager();
  __maze = new Maze();
  __menu = new Menu(__maze, __player);

  Image darknessIMG = {
      .data = DARKNESS_DATA,
      .width = DARKNESS_WIDTH,
      .height = DARKNESS_HEIGHT,
      .mipmaps = 1,
      .format = DARKNESS_FORMAT,
  };

  darknessTexture = LoadTextureFromImage(darknessIMG);
}

/*
Game Class destructor.
Unload the Textures from the GPU VRAM.
close the window Context.
*/
Game::~Game() {
  // Unload All loaded file from VRAM and RAM
  UnloadTexture(__player->playerIdle);
  UnloadTexture(__player->playerMovingUp);
  UnloadTexture(__player->playerMovingRight);
  UnloadTexture(__player->playerMovingLeft);
  UnloadTexture(__player->playerMovingDown);
  UnloadTexture(__maze->wallTexture);
  UnloadTexture(__maze->floorTexture);
  UnloadTexture(__maze->leftWallTexture);
  UnloadTexture(__maze->rightWallTexture);
  UnloadTexture(__maze->leftTopCornerTexture);
  UnloadTexture(__maze->leftBottomCornerTexture);
  UnloadTexture(__maze->rightTopCornerTexture);
  UnloadTexture(__maze->rightBottomCornerTexture);
  UnloadTexture(__maze->topWallTexture);
  UnloadTexture(__maze->bottomWallTexture);
  // unload Ends

  delete __player;
  delete __menu;
  delete __manager;
  delete __window;

  // Close Window
  // CloseWindow();
};

void Game::DrawGame(Rectangle &frameRec) {
  BeginDrawing();
  ClearBackground(BLACK);

  for (int j = 0; j <= 25; j++) {
    for (int i = 0; i <= 40; i++) {
      DrawTexture(darknessTexture, i * 64, j * 64, RAYWHITE);
    }
  }

  BeginMode2D(camera);

  __maze->renderMaze();

  __player->renderPlayer(frameRec);

  EndMode2D();
  if (!__manager->isPaused)
    __menu->DrawPlayerControls(*__player, *__maze, camera);

  if (__manager->isPaused) {
    DrawText("The Game is Paused", 450, 320, 40, GREEN);
  }

  if (__maze->getMaze()[__player->getCellY()][__player->getCellX()] == 2) {

    // Win Menu GOES HERE
    DrawText("You Win", __window->getWindowWidth() / 2,
             __window->getWindowHeight() / 2, 50, GREEN);
  }

  __menu->DrawGameBar(*__manager);

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
  Rectangle frameRec = {0.0f, 0.0f, (float)__player->playerIdle.width / 4,
                        (float)__player->playerIdle.height};

  Timer inputTimer;
  inputTimer.startTimer(0.2);

  camera.target = (Vector2){(__player->getPosX() + 16) * scale,
                            (__player->getPosY() + 16) * scale};
  // camera.offset = (Vector2){400, 400};

  camera.offset = (Vector2){__window->getWindowWidth() / (3.0f),
                            __window->getWindowHeight() / (3.0f)};
  camera.rotation = 0;
  camera.zoom = 3.0f;

  Music music = LoadMusicStream("Resources/audio/ambient.mp3");

  PlayMusicStream(music);

  bool showMap = false;

  while (!WindowShouldClose() && !__manager->exitGame) {
    // Updates
    if (!__manager->isPaused) {

      framesCounter++;
      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 5)
          currentFrame = 0;

        frameRec.x =
            (float)currentFrame * (float)__player->playerIdle.width / 4;
      }

      camera.zoom += ((float)GetMouseWheelMove() * 0.1f);

      __player->updatePlayer(*__maze, camera);
    }

    if (IsKeyPressed(KEY_SPACE) && __manager->getScreen() == GAME_SCREEN) {
      __manager->isPaused = !__manager->isPaused;
    }

    if (__manager->isPaused) {
      PauseMusicStream(music);
    } else {
      ResumeMusicStream(music);
    }

    // Ends Updates
    if (__manager->getScreen() == MAIN_MENU_SCREEN)
      __menu->DrawMainMenu(*__manager);
    else {
      UpdateMusicStream(music);
      // HideCursor();
      DrawGame(frameRec);
    }
  }
}

// Function that runs in the start of the Game loop.
void Game::init() {

  __player->setScale(scale);
  __maze->setScale(scale);
}
