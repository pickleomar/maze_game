#include "maze.h"
#include "Map/map.h"
#include <algorithm>
#include <raylib.h>
#include <vector>

// Offsets for moving in each direction
int offsetX[4] = {0, 1, 0, -1};
int offsetY[4] = {-1, 0, 1, 0};

// Function to get a random unvisited neighbor of the current cell
int GetRandomUnvisitedNeighbor(Cell maze[WIDTH][HEIGHT], int x, int y,
                               std::mt19937 &rng) {
  std::vector<int> neighbors;

  // Check all four possible neighbors
  for (int i = 0; i < 4; i++) {
    int nx = x + offsetX[i];
    int ny = y + offsetY[i];

    if (nx >= 0 && ny >= 0 && nx < WIDTH && ny < HEIGHT &&
        !maze[nx][ny].visited) {
      neighbors.push_back(i); // Add valid direction to neighbors list
    }
  }

  // Return a random valid direction, or -1 if no neighbors available
  if (!neighbors.empty()) {
    std::shuffle(neighbors.begin(), neighbors.end(),
                 rng); // Randomize neighbor selection
    return neighbors[0];
  }
  return -1; // No unvisited neighbors
}

// Function to remove walls between two cells
void RemoveWalls(Cell &current, Cell &next, int direction) {
  if (direction == TOP) {
    current.walls[TOP] = false;
    next.walls[BOTTOM] = false;
  } else if (direction == RIGHT) {
    current.walls[RIGHT] = false;
    next.walls[LEFT] = false;
  } else if (direction == BOTTOM) {
    current.walls[BOTTOM] = false;
    next.walls[TOP] = false;
  } else if (direction == LEFT) {
    current.walls[LEFT] = false;
    next.walls[RIGHT] = false;
  }
}

// Function to generate the maze using DFS with backtracking
void GenerateMaze(Cell maze[WIDTH][HEIGHT], std::mt19937 &rng) {
  std::stack<Cell *> cellStack;
  Cell *current = &maze[0][0];
  current->visited = true;

  while (true) {
    int x = current->x;
    int y = current->y;

    int direction = GetRandomUnvisitedNeighbor(maze, x, y, rng);

    if (direction != -1) {
      // Move to the chosen neighbor
      int nx = x + offsetX[direction];
      int ny = y + offsetY[direction];
      Cell *next = &maze[nx][ny];

      // Remove walls between current and next cell
      RemoveWalls(*current, *next, direction);

      // Mark the neighbor as visited and push the current cell onto the stack
      next->visited = true;
      cellStack.push(current);

      // Move to the next cell
      current = next;
    } else if (!cellStack.empty()) {
      // Backtrack if no unvisited neighbors
      current = cellStack.top();
      cellStack.pop();
    } else {
      // All cells visited, generation is complete
      break;
    }
  }
}

// Function to draw the maze
void DrawMaze(Cell maze[WIDTH][HEIGHT], Texture2D wallsTexture) {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      int px = 50 + x * CELL_SIZE;
      int py = 50 + y * CELL_SIZE;

      if (maze[x][y].walls[TOP])
        DrawLine(px, py, px + CELL_SIZE, py, BLACK); // Top wall

      if (maze[x][y].walls[RIGHT])
        DrawLine(px + CELL_SIZE, py, px + CELL_SIZE, py + CELL_SIZE,
                 BLACK); // Right wall

      if (maze[x][y].walls[BOTTOM])
        DrawLine(px, py + CELL_SIZE, px + CELL_SIZE, py + CELL_SIZE,
                 BLACK); // Bottom wall

      if (maze[x][y].walls[LEFT])
        DrawLine(px, py, px, py + CELL_SIZE, BLACK); // Left wall
    }
  }
}
