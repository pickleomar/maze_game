#pragma once
#ifndef MAZE_H
#define MAZE_H

#include "raylib.h"
#include <random>
#include <stack>

// Constants
const int CELL_SIZE = 64;
const int WIDTH = 10;  // Number of cells horizontally
const int HEIGHT = 10; // Number of cells vertically

// Enum for movement directions
enum Direction { TOP, RIGHT, BOTTOM, LEFT };

// Cell structure representing each cell in the maze
struct Cell {
  int x, y;             // Cell coordinates
  bool visited = false; // Flag to track if cell has been visited
  bool walls[4] = {true, true, true,
                   true}; // Walls for top, right, bottom, left
};

// Function declarations

/**
 * Get a random unvisited neighboring cell.
 * @param maze - 2D array of cells.
 * @param x - Current cell x coordinate.
 * @param y - Current cell y coordinate.
 * @param rng - Random number generator.
 * @return An integer representing the direction to the unvisited neighbor, or
 * -1 if none.
 */
int GetRandomUnvisitedNeighbor(Cell maze[WIDTH][HEIGHT], int x, int y,
                               std::mt19937 &rng);

/**
 * Remove the walls between two neighboring cells.
 * @param current - The current cell.
 * @param next - The neighboring cell.
 * @param direction - The direction of the neighboring cell.
 */
void RemoveWalls(Cell &current, Cell &next, int direction);

/**
 * Generate the maze using Depth-First Search (DFS) with backtracking.
 * @param maze - 2D array of cells to generate the maze in.
 * @param rng - Random number generator for randomizing the maze.
 */
void GenerateMaze(Cell maze[WIDTH][HEIGHT], std::mt19937 &rng);

/**
 * Draw the maze to the screen using Raylib.
 * @param maze - 2D array of cells to draw.
 */
void DrawMaze(Cell maze[WIDTH][HEIGHT], Texture2D wallsTexture);

#endif // MAZE_H
