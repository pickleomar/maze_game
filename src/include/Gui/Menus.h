#pragma once
#include "Button.h"
#include "Game/Manager.h"
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "Timer/Timer.h"
#include "raylib.h"

class Menu {
public:
  Menu(Maze *maze, Player *player, Timer *sessionTimer);
  ~Menu();
  void DrawMainMenu(Manager &manager);
  void DrawGameBar(Manager &manager);
  void DrawDifficultyMenu(Manager &manager);
  void DrawPlayerControls(Player &player, Maze &maze, Camera2D &camera);
  void DrawExitConfirmMenu(Manager &manager);
  void DrawWinMenu(Manager &manager);

private:
  // Background for the main menu
  Texture2D background;
  // Menu Main Buttons
  Button btnStart;
  Button btnExit;

  // Game Status Buttons
  Button btnPause;
  Button btnRegenerate;
  Button btnRestart;
  Button btnHome;
  // Button btnSound;
  Button btnfullScreen;

  // Game Difficulty Buttons
  Button btnEasy;
  Button btnMedium;
  Button btnHard;

  // Game Controls Buttons
  Button btnMoveLeft;
  Button btnMoveRight;
  Button btnMoveUp;
  Button btnMoveDown;

  // Game Controls Buttons
  Button btnYes;
  Button btnNo;
  Texture2D confirmTexture;

  Texture2D winBgTexture;
  Texture2D showCase;

  Sound clickSound;
  // Timer for the session
  Timer *sessionTimer;
  // Maze Pointer
  Maze *maze;
  // Player Poiter
  Player *player;
};
