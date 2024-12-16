#include "Menus.h"
#include "Button.h"
#include "Game/Manager.h"
#include "Maze/Maze.h"
#include "Timer/Timer.h"
#include "Player/Player.h"
#include "Game/Game.h"
#include "raylib.h"

// Menu class constructor
Menu::Menu(Maze *maze, Player *player, Timer *timer, Game *game) {
  // Initializing maze and player pointers
  this->maze = maze;
  this->player = player;
  this->sessionTimer = timer;
  this->game= game;

  // Initializing buttons with images and sizes
  btnStart = {"Resources/gui/button_start.png", 8};
  btnOptions = {"Resources/gui/button_options.png", 8};
  btnExit = {"Resources/gui/button_exit.png", 8};

  // Buttons for difficulty selection
  btnEasy = {"Resources/gui/button_empty.png", 10};
  btnMedium = {"Resources/gui/button_empty.png", 10};
  btnHard = {"Resources/gui/button_empty.png", 10};

  // Buttons for game options like pause, home, regenerate, and fullscreen
  btnPause = {"Resources/gui/button_pause.png", 5};
  btnHome = {"Resources/gui/button_home.png", 5};
  btnRegenerate = {"Resources/gui/button_regenerate.png", 5};
  btnfullScreen = {"Resources/gui/button_expand.png", 5};

  // Button for Player Controlling up, down, left, right
  btnMoveUp = {"Resources/controls/MoveUp_Control.png", 4};
  btnMoveDown = {"Resources/controls/MoveDown_Control.png", 4};
  btnMoveRight = {"Resources/controls/MoveRight_Control.png", 4};
  btnMoveLeft = {"Resources/controls/MoveLeft_Control.png", 4};

  // Load sound effect for button click
  clickSound = LoadSound("Resources/audio/button_clicked.mp3");
}

// Destructor to unload sound when Menu object is destroyed
Menu::~Menu() { UnloadSound(clickSound); }

// Draws the main menu screen
void Menu::DrawMainMenu(Manager &manager) {
  // Updates button states based on mouse position
  btnStart.update(GetMousePosition());
  btnOptions.update(GetMousePosition());
  btnExit.update(GetMousePosition());

  // Set button positions relative to mainMenuPosition
  btnStart.SetPosition(mainMenuPosition);
  btnOptions.SetPosition({mainMenuPosition.x, mainMenuPosition.y + 140});
  btnExit.SetPosition({mainMenuPosition.x, mainMenuPosition.y + 280});

  // Check if any button is pressed and perform respective actions
  if (btnStart.isPressed()) {
    manager.showDifficlttyMenu = true; // Show difficulty menu
    PlaySound(clickSound);             // Play button click sound
  }

  if (btnOptions.isPressed()) {
    PlaySound(clickSound);          // Play button click sound
    manager.showDifficlttyMenu = 1; // Show difficulty menu
  }

  if (btnExit.isPressed()) {
    manager.exitGame = 1;  // Exit the game
    PlaySound(clickSound); // Play button click sound
  }

  // Drawing the screen
  BeginDrawing();
  ClearBackground(GRAY); // Set background color

  // Draw buttons or show the difficulty menu based on the state
  if (manager.showDifficlttyMenu != 1) {
    btnStart.drawbutton();
    btnOptions.drawbutton();
    btnExit.drawbutton();
  } else {
    DrawDifficultyMenu(manager); // Draw difficulty menu if active
  }

  EndDrawing();
}

// Draws the game bar (pause, home, regenerate, fullscreen) in the game screen
void Menu::DrawGameBar(Manager &manager) {
  // Update button states based on mouse position
  btnPause.update(GetMousePosition());
  btnHome.update(GetMousePosition());
  btnRegenerate.update(GetMousePosition());
  btnfullScreen.update(GetMousePosition());

  // Set button positions for the game bar
  btnPause.SetPosition({1160, 30});
  btnHome.SetPosition({1060, 30});
  btnRegenerate.SetPosition({960, 30});
  btnfullScreen.SetPosition({860, 30});

  // Check if any button is pressed and perform respective actions
  if (btnPause.isPressed()) {
    manager.isPaused = !manager.isPaused; // Pause the game
    TraceLog(LOG_INFO, "Paused");
  }

  if (btnHome.isPressed()) {
    manager.setScreen(MAIN_MENU_SCREEN); // Go back to main menu
  }

  if (btnRegenerate.isPressed()) {
    maze->generateMaze();    // Regenerate maze
    player->resetPosition(); // Reset player position
    sessionTimer->startTimer();
    TraceLog(LOG_INFO, "Generating New Maze");
  }

  if (btnfullScreen.isPressed()) {
    TraceLog(LOG_INFO, "Full Screen Triggered");
    ToggleFullscreen(); // Toggle fullscreen mode
  }

  // If the game is not paused, draw the pause button

  btnPause.drawbutton();

  // Always draw the other game control buttons
  btnHome.drawbutton();
  btnRegenerate.drawbutton();
  btnfullScreen.drawbutton();
}

// Draws the difficulty selection menu when the user is setting the difficulty
void Menu::DrawDifficultyMenu(Manager &manager) {
  // Update button states for difficulty selection
  btnEasy.update(GetMousePosition());
  btnMedium.update(GetMousePosition());
  btnHard.update(GetMousePosition());

  // Set positions for difficulty buttons
  btnEasy.SetPosition({635 - 48 * 5, 100});
  btnMedium.SetPosition({635 - 48 * 5, 280});
  btnHard.SetPosition({635 - 48 * 5, 460});

  // Check if a difficulty button is pressed and perform respective actions
  if (btnEasy.isPressed()) {
    maze->setDifficulty(EASY_DIFF); // Set difficulty to easy
    maze->resizeMaze();             // Resize maze to fit the difficulty
    PlaySound(clickSound);          // Play button click sound
    maze->generateMaze(); // Generate maze based on selected difficulty
    manager.setScreen(GAME_SCREEN);     // Switch to game screen
    manager.showDifficlttyMenu = false; // Close difficulty menu
    player->resetPosition();
    sessionTimer->startTimer();
    game->resetWinState();
  }

  if (btnMedium.isPressed()) {
    maze->setDifficulty(MEDIUM_DIFF);   // Set difficulty to medium
    maze->resizeMaze();                 // Resize maze
    PlaySound(clickSound);              // Play button click sound
    maze->generateMaze();               // Generate maze
    manager.setScreen(GAME_SCREEN);     // Switch to game screen
    manager.showDifficlttyMenu = false; // Close difficulty menu
    player->resetPosition();
    sessionTimer->startTimer();
    game->resetWinState();
  }

  if (btnHard.isPressed()) {
    maze->setDifficulty(HARD_DIFF);     // Set difficulty to hard
    maze->resizeMaze();                 // Resize maze
    PlaySound(clickSound);              // Play button click sound
    maze->generateMaze();               // Generate maze
    manager.setScreen(GAME_SCREEN);     // Switch to game screen
    manager.showDifficlttyMenu = false; // Close difficulty menu
    player->resetPosition();
    sessionTimer->startTimer();
    game->resetWinState();
  }

  // Draw the difficulty buttons and labels
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

// Draws Controls for the Player
void Menu::DrawPlayerControls(Player &player, Maze &maze, Camera2D &camera) {

  btnMoveUp.update(GetMousePosition());
  btnMoveDown.update(GetMousePosition());
  btnMoveLeft.update(GetMousePosition());
  btnMoveRight.update(GetMousePosition());

  btnMoveUp.SetPosition({150, 460});
  btnMoveDown.SetPosition({150, 570});
  btnMoveLeft.SetPosition({960, 510});
  btnMoveRight.SetPosition({1100, 510});

  player.updatePlayerControls(maze, camera, btnMoveUp.isPressed(),
                              btnMoveDown.isPressed(), btnMoveLeft.isPressed(),
                              btnMoveRight.isPressed());

  btnMoveUp.drawbutton();
  btnMoveDown.drawbutton();
  btnMoveLeft.drawbutton();
  btnMoveRight.drawbutton();
}
