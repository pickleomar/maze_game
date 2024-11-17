#include "Gui.h"
#include "Button.h"
#include "Game/Manager.h"
#include "raylib.h"

Menu::Menu() {
  btnStart = {"Resources/gui/button_start.png", 8};
  btnOptions = {"Resources/gui/button_options.png", 8};
  btnExit = {"Resources/gui/button_exit.png", 8};
  clickSound = LoadSound("Resources/audio/button_clicked.mp3");
}

Menu::~Menu() { UnloadSound(clickSound); }

void Menu::DrawMenu(Manager &manager) {
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
