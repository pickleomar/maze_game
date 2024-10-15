#include "map.h"
#include <raylib.h>

void MapTile::DrawLeftWall(Texture2D wallsTexture) {
  DrawTextureRec(wallsTexture, leftWallTopREC, (Vector2){84, 100}, WHITE);
  DrawTextureRec(wallsTexture, leftWallCenterREC, (Vector2){84, 116}, WHITE);
  DrawTextureRec(wallsTexture, leftWallCenterREC, (Vector2){84, 132}, WHITE);
  DrawTextureRec(wallsTexture, leftWallBottomREC, (Vector2){84, 148}, WHITE);
}
