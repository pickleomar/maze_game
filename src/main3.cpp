#include "raylib.h"
#include <vector>

#define TILE_SIZE 40 // Tile size in pixels

struct Player {
  float x, y;
  float width, height;
  float speed;

  Player(float startX, float startY, float w, float h, float s)
      : x(startX), y(startY), width(w), height(h), speed(s) {}

  Rectangle GetRect() const { return Rectangle{x, y, width, height}; }
};

class Maze {
public:
  int width, height;
  std::vector<std::vector<int>> mazeData;

  Maze(int w, int h) : width(w), height(h) {
    mazeData.resize(height, std::vector<int>(width, 1)); // Initialize all walls
  }

  void GenerateMaze() {
    // Randomly generate a maze here; 0 = path, 1 = wall
    for (int y = 1; y < height - 1; y++) {
      for (int x = 1; x < width - 1; x++) {
        mazeData[y][x] = (x % 2 == 1 && y % 2 == 1) ? 0 : 1;
      }
    }
  }

  void DrawMaze() const {
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        if (mazeData[y][x] == 1) {
          DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE,
                        DARKGRAY);
        }
      }
    }
  }
};

bool CheckCollisionWithDirection(const Player &player, const Maze &maze,
                                 float newX, float newY) {
  Rectangle playerRect = {newX, newY, player.width, player.height};

  int leftTile = std::max(0, static_cast<int>(newX) / TILE_SIZE);
  int rightTile = std::min(maze.width - 1,
                           static_cast<int>(newX + player.width) / TILE_SIZE);
  int topTile = std::max(0, static_cast<int>(newY) / TILE_SIZE);
  int bottomTile = std::min(maze.height - 1,
                            static_cast<int>(newY + player.height) / TILE_SIZE);

  for (int y = topTile; y <= bottomTile; ++y) {
    for (int x = leftTile; x <= rightTile; ++x) {
      if (maze.mazeData[y][x] == 1) { // Wall tile
        Rectangle wallRect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE,
                              TILE_SIZE};
        if (CheckCollisionRecs(playerRect, wallRect)) {
          return true; // Collision detected
        }
      }
    }
  }

  return false; // No collision
}

void MovePlayer(Player &player, const Maze &maze) {
  float newX = player.x;
  float newY = player.y;

  // Check each direction separately
  if (IsKeyDown(KEY_W)) { // Up
    float nextY = player.y - player.speed;
    if (!CheckCollisionWithDirection(player, maze, player.x, nextY)) {
      player.y = nextY;
    }
  }

  if (IsKeyDown(KEY_S)) { // Down
    float nextY = player.y + player.speed;
    if (!CheckCollisionWithDirection(player, maze, player.x, nextY)) {
      player.y = nextY;
    }
  }

  if (IsKeyDown(KEY_A)) { // Left
    float nextX = player.x - player.speed;
    if (!CheckCollisionWithDirection(player, maze, nextX, player.y)) {
      player.x = nextX;
    }
  }

  if (IsKeyDown(KEY_D)) { // Right
    float nextX = player.x + player.speed;
    if (!CheckCollisionWithDirection(player, maze, nextX, player.y)) {
      player.x = nextX;
    }
  }
}

int main() {
  InitWindow(800, 600, "Maze Game with Directional Collision System");

  Maze maze(20, 15); // Create a 20x15 maze
  maze.GenerateMaze();

  Player player(60, 60, TILE_SIZE - 10, TILE_SIZE - 10, 4.0f); // Create player

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    MovePlayer(player, maze); // Update player movement based on collisions

    BeginDrawing();
    ClearBackground(RAYWHITE);

    maze.DrawMaze();                          // Draw the maze
    DrawRectangleRec(player.GetRect(), BLUE); // Draw the player

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
