#include "Gui.h"
#include "Button.h"
#include "Game/Manager.h"
#include "raylib.h"

Menu::Menu() {
  btnStart = {"Resources/gui/button_start.png", 8};
  btnOptions = {"Resources/gui/button_options.png", 8};
  btnExit = {"Resources/gui/button_exit.png", 8};
  btnPause = {"Resources/gui/button_pause.png", 5};
  btnHome = {"Resources/gui/button_home.png", 5};
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

  if (btnStart.isPressed()) {
    manager.setScreen(GAME_SCREEN);
    PlaySound(clickSound);
  }

  if (IsKeyPressed(KEY_ENTER)) {
    manager.setScreen(GAME_SCREEN);
  }

  if (btnOptions.isPressed()) {
    PlaySound(clickSound);
  }

  if (btnExit.isPressed()) {
    manager.exitGame = 1;
    PlaySound(clickSound);
  }

  BeginDrawing();
  ClearBackground(GRAY);

  btnStart.drawbutton();
  btnOptions.drawbutton();
  btnExit.drawbutton();

  EndDrawing();
}

void Menu::DrawGameBar(Manager &manager) {

  // Updates
  btnPause.update(GetMousePosition());
  btnHome.update(GetMousePosition());

  // Positions
  btnPause.SetPosition({1160, 30});
  btnHome.SetPosition({1060, 30});

  // Actions
  if (btnPause.isPressed()) {
    manager.isPaused = true;
    TraceLog(LOG_INFO, "Paused");
  }
  if (btnHome.isPressed()) {
    manager.setScreen(MAIN_MENU_SCREEN);
    TraceLog(LOG_INFO, "Paused");
  }

  // Rendering
  if (!manager.isPaused)
    btnPause.drawbutton();
  btnHome.drawbutton();
}
