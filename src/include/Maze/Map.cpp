#include "Map.h"
#include "Maze/Maze.h"
#include "Player/Player.h"
#include "raylib.h"

void Map::update() {
  // if (IsKeyPressed(KEY_M)) {
  //   showMap = true;
  // }
}

void Map::renderMap(Maze &maze, Player &player) {
  if (showMap) {
    // DrawRectangleRec({200, 80, 1270, 720}, GRAY);

    //   for (int y = 0; y < maze.getMaze().size(); ++y) {
    //     for (int x = 0; x < maze.getMaze()[0].size(); ++x) {
    //       if (maze.getMaze()[y][x] == 1) {

    //         DrawRectangleRec({(1270 / maze.getMaze()[0].size() * float(x)),
    //                           (720 / maze.getMaze().size() * float(y)),
    //                           (float)1270 / maze.getMaze()[0].size(),
    //                           (float)720 / maze.getMaze().size()},
    //                          BLACK);
    //       } else {

    //         DrawRectangleRec({(1270 / maze.getMaze()[0].size() * float(x)),
    //                           (720 / maze.getMaze().size() * float(y)),
    //                           (float)1270 / maze.getMaze()[0].size(),
    //                           (float)720 / maze.getMaze().size()},
    //                          WHITE);
    //       }
    //     }
    //   }

    //   DrawRectangleRec(
    //       {((float)player.getCellX() * (float)1270 /
    //       maze.getMaze()[0].size()),
    //        ((float)player.getCellY() * (float)720 / maze.getMaze().size()),
    //        (float)1270 / maze.getMaze()[0].size(),
    //        (float)720 / maze.getMaze().size()},
    //       BLUE);
    // }
  }
}
