// #include "Player.h"
// #include "Maze/Maze.h"
// #include "Timer/Timer.h"
// #include <raylib.h>
// //
// Player::Player() : posX(24), posY(24), speed(16), scale(3) {
//   this->playerIdle = LoadTexture("../Resources/player/player_idle.png");
//   this->playerMovingDown =
//       LoadTexture("../Resources/player/player_moving_down.png");
//   this->playerMovingUp =
//       LoadTexture("../Resources/player/player_moving_up.png");
//   this->playerMovingRight =
//       LoadTexture("../Resources/player/player_moving_right.png");
//   this->playerMovingLeft =
//       LoadTexture("../Resources/player/player_moving_left.png");
// }

// Player::~Player() {}

// void Player::renderPlayer(Rectangle frameRec) {
//   Texture2D playerTexture;

//   Rectangle playerRec;
//   if (this->state == STATE_IDLE) {
//     playerTexture = playerIdle;
//     playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
//   } else if (this->state == STATE_MOVING_DOWN) {
//     playerTexture = playerMovingDown;
//     playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
//   } else if (this->state == STATE_MOVING_UP) {
//     playerTexture = playerMovingUp;
//     playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
//   } else if (this->state == STATE_MOVING_RIGHT) {
//     playerTexture = playerMovingRight;
//     playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
//   } else if (this->state == STATE_MOVING_LEFT) {
//     playerTexture = playerMovingLeft;
//     playerRec = {posX * scale, posY * scale, 16 * scale, 16 * scale};
//   }

//   DrawTexturePro(playerTexture, frameRec, playerRec, {8, 8}, 0, WHITE);
// }

// void Player::updatePlayer(Maze &maze, Camera2D &camera, Timer &inputTimer) {

//   resetState();
//   inputTimer.UpdateTimer();
//   if (inputTimer.timerDone()) {

//     if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) &&
//         (maze.getMaze()[getCellY() + 1][getCellX()] != 1)) {

//       setState(STATE_MOVING_DOWN);
//       moveDown();

//       camera.target = (Vector2){(posX + 16) * scale, (posY + 16) * scale};
//     }

//     if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) &&
//         (maze.getMaze()[getCellY() - 1][getCellX()] != 1)) {

//       setState(STATE_MOVING_UP);
//       moveUp();

//       // camera.target = (Vector2){posX + (16 * scale), posY + (16 * scale)};
//       camera.target = (Vector2){(posX + 16) * scale, (posY + 16) * scale};
//     }

//     if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) &&
//         (maze.getMaze()[getCellY()][getCellX() + 1] != 1)) {

//       setState(STATE_MOVING_RIGHT);
//       moveRight();
//       camera.target = (Vector2){(posX + 16) * scale, (posY + 16) * scale};
//     }

//     if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) &&
//         (maze.getMaze()[getCellY()][getCellX() - 1] != 1)) {

//       setState(STATE_MOVING_LEFT);
//       moveLeft();
//       camera.target = (Vector2){(posX + 16) * scale, (posY + 16) * scale};
//     }
//     inputTimer.startTimer(0.12);
//   }
// }

// void Player::resetState() {
//   if (IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_S) ||
//       IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_W) ||
//       IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_D) ||
//       IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_A)) {
//     setState(STATE_IDLE);
//   }
// }
// void Player::setState(int state) { this->state = state; }

// void Player::moveDown() { posY += speed; }
// void Player::moveUp() { posY -= speed; }
// void Player::moveLeft() { posX -= speed; }
// void Player::moveRight() { posX += speed; }

// float Player::getPosX() { return posX; }

// float Player::getPosY() { return posY; }

// int Player::getCellX() { return posX / 16; }
// int Player::getCellY() { return posY / 16; }

// void Player::setScale(float scale) { this->scale = scale; }

// bool Player::isCollidingWithWall(float x, float y, float width, float height,
//                                  Maze &maze) {
//   // Calculate the cells at each corner of the player’s bounding box
//   int leftX = static_cast<int>(x / 16);
//   int rightX = static_cast<int>((x + width - 1) / 16);
//   int topY = static_cast<int>(y / 16);
//   int bottomY = static_cast<int>((y + height - 1) / 16);

//   // Check each corner against the maze bounds
//   if (maze.getMaze()[topY][leftX] == 1 || maze.getMaze()[topY][rightX] == 1
//   ||
//       maze.getMaze()[bottomY][leftX] == 1 ||
//       maze.getMaze()[bottomY][rightX] == 1) {
//     return true;
//   }
//   return false;
// }
