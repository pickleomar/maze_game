#include "map.h"
#include <raylib.h>

void MapTile::DrawLeftWall(Texture2D wallsTexture, float posX, float posY) {
  DrawTextureRec(wallsTexture, leftWallTopREC, (Vector2){posX, posY}, WHITE);
  DrawTextureRec(wallsTexture, leftWallCenterREC, (Vector2){posX, posY + 16},
                 WHITE);
  DrawTextureRec(wallsTexture, leftWallCenterREC, (Vector2){posX, posY + 32},
                 WHITE);
  DrawTextureRec(wallsTexture, leftWallBottomREC, (Vector2){posX, posY + 48},
                 WHITE);
}

void MapTile::DrawRightWall(Texture2D wallsTexture, float posX, float posY) {
  DrawTextureRec(wallsTexture, rightWallTopREC, (Vector2){posX, posY}, WHITE);
  DrawTextureRec(wallsTexture, rightWallCenterREC, (Vector2){posX, posY + 16},
                 WHITE);
  // DrawTextureRec(wallsTexture, rightWallCenterREC, (Vector2){posX, posY +
  // 32},
  //                WHITE);
  DrawTextureRec(wallsTexture, rightWallBottomREC, (Vector2){posX, posY + 32},
                 WHITE);
}

void MapTile::DrawCenterWall(Texture2D wallsTexture, Texture2D floorTexture,
                             float posX, float posY) {

  DrawTextureRec(wallsTexture, topWallREC, (Vector2){posX, posY}, WHITE);
  DrawTextureRec(floorTexture, floorCenterREC, (Vector2){posX, posY + 32},
                 WHITE);
  DrawTextureRec(floorTexture, floorCenterREC, (Vector2){posX + 16, posY + 32},
                 WHITE);
  DrawTextureRec(wallsTexture, topWallREC, (Vector2){posX, posY + 48}, WHITE);
}

void MapTile::DrawTopRightCorner(Texture2D wallsTexture, float posX,
                                 float posY) {

  DrawTextureRec(wallsTexture, topWallREC, (Vector2){posX, posY}, WHITE);
  DrawTextureRec(wallsTexture, rightWallTopREC, (Vector2){posX + 32, posY},
                 WHITE);
  DrawTextureRec(wallsTexture, rightWallCenterREC,
                 (Vector2){posX + 32, posY + 16}, WHITE);
  DrawTextureRec(wallsTexture, rightWallCenterREC,
                 (Vector2){posX + 32, posY + 32}, WHITE);
  DrawTextureRec(wallsTexture, rightWallBottomREC,
                 (Vector2){posX + 32, posY + 48}, WHITE);
}

void MapTile::DrawBottomRightCorner(Texture2D wallsTexture, float posX,
                                    float posY) {

  DrawTextureRec(wallsTexture, topWallREC, (Vector2){posX, posY + 48}, WHITE);
  DrawTextureRec(wallsTexture, rightWallTopREC, (Vector2){posX + 32, posY},
                 WHITE);
  DrawTextureRec(wallsTexture, rightWallCenterREC,
                 (Vector2){posX + 32, posY + 16}, WHITE);
  DrawTextureRec(wallsTexture, rightWallCenterREC,
                 (Vector2){posX + 32, posY + 32}, WHITE);
  DrawTextureRec(wallsTexture, rightWallBottomREC,
                 (Vector2){posX + 32, posY + 48}, WHITE);
}

void MapTile::DrawtopWall(Texture2D wallsTexture, float posX, float posY) {
  DrawTextureRec(wallsTexture, topWallREC, (Vector2){posX, posY}, WHITE);
}

void MapTile::DrawRightCenterWall(Texture2D wallsTexture, float posX,
                                  float posY) {
  DrawTextureRec(wallsTexture, rightWallCenterREC, (Vector2){posX, posY},
                 WHITE);
}
