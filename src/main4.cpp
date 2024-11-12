#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

struct Cell {
  bool isWall; // true if wall, false if path
  bool visited;
};

class Maze {
public:
  Maze(int width, int height);
  void generateMaze();
  void displayMaze(); // For testing output in the console

private:
  int width, height;
  std::vector<std::vector<Cell>> grid;
  std::vector<std::pair<int, int>> frontier;

  void addFrontier(int x, int y);
  bool isInBounds(int x, int y);
  void markCellAsPath(int x, int y);
};

Maze::Maze(int width, int height) : width(width), height(height) {
  grid.resize(height, std::vector<Cell>(width, {true, false}));
  srand(static_cast<unsigned>(time(0))); // Seed the random number generator
}

bool Maze::isInBounds(int x, int y) {
  return x >= 0 && x < width && y >= 0 && y < height;
}

void Maze::addFrontier(int x, int y) {
  if (isInBounds(x, y) && grid[y][x].isWall && !grid[y][x].visited) {
    frontier.push_back({x, y});
    grid[y][x].visited = true; // Mark as visited to avoid adding again
  }
}

void Maze::markCellAsPath(int x, int y) {
  if (isInBounds(x, y)) {
    grid[y][x].isWall = false;
    grid[y][x].visited = true;

    // Add neighbors to the frontier list
    addFrontier(x + 2, y);
    addFrontier(x - 2, y);
    addFrontier(x, y + 2);
    addFrontier(x, y - 2);
  }
}

void Maze::generateMaze() {
  int startX = (rand() % (width / 2)) * 2;  // Start on an even index for x
  int startY = (rand() % (height / 2)) * 2; // Start on an even index for y
  markCellAsPath(startX, startY);

  while (!frontier.empty()) {
    // Pick a random cell from the frontier
    int randIndex = rand() % frontier.size();
    int x = frontier[randIndex].first;
    int y = frontier[randIndex].second;

    // Remove this cell from the frontier
    frontier.erase(frontier.begin() + randIndex);

    // Find unvisited neighbors
    std::vector<std::pair<int, int>> neighbors;
    if (isInBounds(x + 2, y) && !grid[y][x + 2].isWall)
      neighbors.push_back({x + 2, y});
    if (isInBounds(x - 2, y) && !grid[y][x - 2].isWall)
      neighbors.push_back({x - 2, y});
    if (isInBounds(x, y + 2) && !grid[y + 2][x].isWall)
      neighbors.push_back({x, y + 2});
    if (isInBounds(x, y - 2) && !grid[y - 2][x].isWall)
      neighbors.push_back({x, y - 2});

    if (!neighbors.empty()) {
      // Connect this cell to a random neighbor by removing the wall in between
      auto [nx, ny] = neighbors[rand() % neighbors.size()];
      int wallX = (x + nx) / 2;
      int wallY = (y + ny) / 2;

      grid[wallY][wallX].isWall = false; // Remove the wall
      markCellAsPath(x, y);              // Mark the current cell as a path
    }
  }
}

void Maze::displayMaze() {
  for (const auto &row : grid) {
    for (const auto &cell : row) {
      std::cout << (cell.isWall ? "# " : "  ");
    }
    std::cout << '\n';
  }
}

int main() {
  Maze maze(21, 21); // Example size, should be odd for proper maze generation
  maze.generateMaze();
  maze.displayMaze(); // For testing output
  return 0;
}
