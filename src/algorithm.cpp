#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stack>
#include <utility>

struct Position {
  int x;
  int y;
};

struct Directions {
  bool north;
  bool south;
  bool east;
  bool west;
};

Directions check_Direction(std::pair<int, int> maze_size,
                           Position player_Position) {
  Directions posible_Direction;

  posible_Direction.east =
      player_Position.x < (maze_size.first - 1) && player_Position.x >= 0;
  posible_Direction.west =
      player_Position.x <= (maze_size.first - 1) && player_Position.x > 0;
  posible_Direction.north =
      player_Position.y <= (maze_size.second - 1) && player_Position.y > 0;
  posible_Direction.south =
      player_Position.y < (maze_size.second - 1) && player_Position.y >= 0;

  return posible_Direction;
}

void move_Player(Directions direction, Position &player_Position,
                 std::pair<int, int> maze_size, int visited_Cells[]) {
  while (1) {
    int num = rand() % 4;
    if (num == 0 && direction.north) {
      if (visited_Cells[maze_size.first * (player_Position.y + 1) +
                        player_Position.x] == 1) {
        continue;
      } else {
        std::cout << "move to the north\n";
        player_Position.y -= 1;
        std::cout << "New Cordinates X =" << player_Position.x
                  << ", Y = " << player_Position.y << "\n";
        visited_Cells[maze_size.first * player_Position.y + player_Position.x] =
            1;
        break;
      }
    } else if (num == 1 && direction.east) {
      if (visited_Cells[maze_size.first * player_Position.y +
                        player_Position.x + 1] == 1) {
        continue;
      };
      std::cout << "move to the east\n";
      player_Position.x += 1;

      std::cout << "New Cordinates X =" << player_Position.x
                << ", Y = " << player_Position.y << "\n";
      visited_Cells[maze_size.first * player_Position.y + player_Position.x] =
          1;
      break;
    } else if (num == 2 && direction.south) {
      if (visited_Cells[maze_size.first * (player_Position.y - 1) +
                        player_Position.x] == 1) {
        continue;
      };
      std::cout << "move to the south\n";
      player_Position.y += 1;

      std::cout << "New Cordinates X =" << player_Position.x
                << ", Y = " << player_Position.y << "\n";
      visited_Cells[maze_size.first * player_Position.y + player_Position.x] =
          1;
      break;
    } else if (num == 3 && direction.west) {
      if (visited_Cells[maze_size.first * player_Position.y +
                        player_Position.x - 1] == 1) {
        continue;
      };
      std::cout << "move to the west\n";
      player_Position.x -= 1;
      std::cout << "New Cordinates X =" << player_Position.x
                << ", Y = " << player_Position.y << "\n";
      visited_Cells[maze_size.first * player_Position.y + player_Position.x] =
          1;
      break;
    } else {
      continue;
    }
  }
}

int main() {
  srand(time(0));

  Position player_Position = {0, 0};
  std::stack<std::pair<int, int>> stack;
  Directions posible_Direction;

  // Maze Size
  std::pair<int, int> maze_size = {4, 4};

  int *visited_Cells;

  visited_Cells = new int[maze_size.first * maze_size.second];
  memset(visited_Cells, 0, maze_size.first * maze_size.second);

  visited_Cells[maze_size.first * player_Position.y + player_Position.x] = 1;
  stack.push({player_Position.x, player_Position.y});
  // std::cout << "Enter Player Cordinates  : ";
  // std::cin >> player_Position.x >> player_Position.y;

  while (1) {
    posible_Direction = check_Direction(maze_size, player_Position);

    // if (posible_Direction.east && posible_Direction.west) {
    //   std::cout << "Player can move East and West \n";
    // } else if (posible_Direction.east) {
    //   std::cout << "Player can move East \n";
    // } else if (posible_Direction.west) {
    //   std::cout << "Player can move  West \n";
    // }

    // if (posible_Direction.north && posible_Direction.south) {
    //   std::cout << "Player can move North and South \n";
    // } else if (posible_Direction.north) {
    //   std::cout << "Player can move  North \n";
    // } else if (posible_Direction.south) {
    //   std::cout << "Player can move South \n";
    // }

    move_Player(posible_Direction, player_Position, maze_size, visited_Cells);
    // std::cout << rand() % 4 << std::endl;
    //
    for (int i = 0; i <= (maze_size.first * maze_size.second) - 1; i++) {
      if ((i + 1) % maze_size.first == 0)
        std::cout << "CellId=" << i << ": Visited=" << visited_Cells[i]
                  << " \n ";
      else
        std::cout << "CellId=" << i << ": Visited=" << visited_Cells[i] << "\t";
    }

    std::cin.get();
  }
  return 0;
}
