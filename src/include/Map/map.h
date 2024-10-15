#pragma once
#include <raylib.h>

#define BLOCK_SIZE 16

#define topWallREC                                                             \
  {0 * BLOCK_SIZE, 1 * BLOCK_SIZE, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE}

#define bottomWallREC                                                          \
  {0 * BLOCK_SIZE, 1 * BLOCK_SIZE, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE}

// //////////////////////////////////////////////
#define leftWallTopREC {2 * BLOCK_SIZE, 0 * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE}

#define leftWallCenterREC                                                      \
  {2 * BLOCK_SIZE, 1 * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE}

#define leftWallBottomREC                                                      \
  {2 * BLOCK_SIZE, 2 * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE}
// //////////////////////////////////////////////

#define rightWallREC {4 * BLOCK_SIZE, 0 * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE}

// Floor

#define floorTopLeftREC                                                        \
  {4 * BLOCK_SIZE, 0 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorTopRightREC                                                       \
  {6 * BLOCK_SIZE, 0 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorBottomLeftREC                                                     \
  {4 * BLOCK_SIZE, 2 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorBottomRightREC                                                    \
  {6 * BLOCK_SIZE, 2 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorTopCenterREC                                                      \
  {5 * BLOCK_SIZE, 0 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorRightCenterREC                                                    \
  {4 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorLeftCenterREC                                                     \
  {6 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorBottomCenterREC                                                   \
  {5 * BLOCK_SIZE, 2 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

#define floorCenterREC                                                         \
  {5 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE}

class MapTile {
public:
  void DrawLeftWall(Texture2D wallsTexture);
};
