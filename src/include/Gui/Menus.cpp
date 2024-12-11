#include "Menus.h"
#include "Button.h"
#include "Game/Manager.h"
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "raylib.h"

Menu::Menu(Maze *maze, Player *player) {
  this->maze = maze;
  this->player = player;
  btnStart = {"Resources/gui/button_start.png", 8};
  btnOptions = {"Resources/gui/button_options.png", 8};
  btnExit = {"Resources/gui/button_exit.png", 8};

  btnEasy = {"Resources/gui/button_empty.png", 10};
  btnMedium = {"Resources/gui/button_empty.png", 10};
  btnHard = {"Resources/gui/button_empty.png", 10};

  btnPause = {"Resources/gui/button_pause.png", 5};
  btnHome = {"Resources/gui/button_home.png", 5};
  btnRegenerate = {"Resources/gui/button_regenerate.png", 5};
  btnfullScreen = {"Resources/gui/button_expand.png", 5};
  clickSound = LoadSound("Resources/audio/button_clicked.mp3");
}

Menu::~Menu() { UnloadSound(clickSound); }

void Menu::DrawMainMenu(Manager &manager) {
  // Update Functions
  btnStart.update(GetMousePosition());
  btnOptions.update(GetMousePosition());
  btnExit.update(GetMousePosition());

  // Positions Settings
  btnStart.SetPosition(mainMenuPosition);
  btnOptions.SetPosition({mainMenuPosition.x, mainMenuPosition.y + 140});
  btnExit.SetPosition({mainMenuPosition.x, mainMenuPosition.y + 280});

  // Logic
  if (btnStart.isPressed()) {
    manager.showDifficlttyMenu = true;
    PlaySound(clickSound);
  }

  if (btnOptions.isPressed()) {
    PlaySound(clickSound);
    manager.showDifficlttyMenu = 1;
  }

  if (btnExit.isPressed()) {
    manager.exitGame = 1;
    PlaySound(clickSound);
  }

  // Drawing
  BeginDrawing();
  ClearBackground(GRAY);

  if (manager.showDifficlttyMenu != 1) {
    btnStart.drawbutton();
    btnOptions.drawbutton();
    btnExit.drawbutton();
  } else {
    DrawDifficultyMenu(manager);
  };
  EndDrawing();
}

void Menu::DrawGameBar(Manager &manager) {

  // Updates
  btnPause.update(GetMousePosition());
  btnHome.update(GetMousePosition());
  btnRegenerate.update(GetMousePosition());
  btnfullScreen.update(GetMousePosition());

  // Positions
  btnPause.SetPosition({1160, 30});
  btnHome.SetPosition({1060, 30});
  btnRegenerate.SetPosition({960, 30});
  btnfullScreen.SetPosition({860, 30});

  // Actions
  if (btnPause.isPressed()) {
    manager.isPaused = true;
    TraceLog(LOG_INFO, "Paused");
  }
  if (btnHome.isPressed()) {
    manager.setScreen(MAIN_MENU_SCREEN);
  }

  if (btnRegenerate.isPressed()) {
    maze->generateMaze();
    player->resetPosition();
    TraceLog(LOG_INFO, "Generating New Maze");
  }

  if (btnfullScreen.isPressed()) {
    TraceLog(LOG_INFO, "Full Screen Trigered");
    ToggleFullscreen();
  }

  if (IsKeyPressed(KEY_F)) {
    ToggleFullscreen();
  }

  // Rendering
  if (!manager.isPaused)
    btnPause.drawbutton();
  btnHome.drawbutton();
  btnRegenerate.drawbutton();
  btnfullScreen.drawbutton();
}

void Menu::DrawDifficultyMenu(Manager &manager) {
  btnEasy.update(GetMousePosition());
  btnMedium.update(GetMousePosition());
  btnHard.update(GetMousePosition());

  btnEasy.SetPosition({635 - 48 * 5, 100});
  btnMedium.SetPosition({635 - 48 * 5, 280});
  btnHard.SetPosition({635 - 48 * 5, 460});

  if (btnEasy.isPressed()) {
    maze->setDifficulty(EASY_DIFF);
    maze->resizeMaze();
    PlaySound(clickSound);
    maze->generateMaze();
    manager.setScreen(GAME_SCREEN);
    manager.showDifficlttyMenu = false;
  }

  if (btnMedium.isPressed()) {
    maze->setDifficulty(MEDIUM_DIFF);
    maze->resizeMaze();
    PlaySound(clickSound);
    maze->generateMaze();
    manager.setScreen(GAME_SCREEN);
    manager.showDifficlttyMenu = false;
  }

  if (btnHard.isPressed()) {
    maze->setDifficulty(HARD_DIFF);
    maze->resizeMaze();
    PlaySound(clickSound);
    maze->generateMaze();
    manager.setScreen(GAME_SCREEN);
    manager.showDifficlttyMenu = false;
  }

  btnEasy.drawbutton();
  DrawText("Easy", btnEasy.position.x + (5 * 33), btnEasy.position.y + 50, 60,
           GREEN);

  btnMedium.drawbutton();
  DrawText("Medium", btnMedium.position.x + (5 * 28), btnMedium.position.y + 50,
           60, WHITE);

  btnHard.drawbutton();
  DrawText("Hard", btnHard.position.x + (5 * 33), btnHard.position.y + 50, 60,
           RED);
}
