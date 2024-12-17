#pragma once
#include "Button.h"
#include "Game/Manager.h"
#include "Player/Player.h"
#include "raylib.h"
#include <Maze/Maze.h>
class Menu {
public:
  Menu(Maze *maze, Player *player);
  ~Menu();
  void DrawMainMenu(Manager &manager);
  void DrawGameBar(Manager &manager);
  void DrawDifficultyMenu(Manager &manager);
  void DrawPlayerControls(Player &player, Maze &maze, Camera2D &camera);

private:
  // Background for the main menu
  Texture2D background;
  // Menu Main Buttons
  Button btnStart;
  Button btnExit;
  Button btnOptions;

  // Game Status Buttons
  Button btnPause;
  Button btnRegenerate;
  Button btnHome;
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

  // The Main Menu position on the Screen
  Vector2 mainMenuPosition = {800, 160};

  Sound clickSound;
  // Maze Pointer

  Maze *maze;
  // Player Poiter
  Player *player;
};
