#include <Engine.h>
#include <cstring>
#include <raylib.h>
#include <stack>
#include <utility>

#define left 1
#define right 2
#define top 3
#define bottom 4

#define high 1
#define low 0

struct cell {
  int left_wall;
  int right_wall;
  int top_wall;
  int bottom_wall;
  int visited;
};

std::stack<std::pair<int, int>> stack_cell;

struct maze_context {
  int width;
  int height;
  struct cell *c;
  int visit_count;
};

void init_maze_context(struct maze_context *m, int width, int height) {
  m->visit_count = 0;
  m->c = (struct cell *)malloc(sizeof(struct cell) * height * width);
  m->width = width;
  m->height = height;

  struct cell *m1;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      m1 = &m->c[(y * width) + x];
      m1->left_wall = 1;
      m1->right_wall = 1;
      m1->top_wall = 1;
      m1->bottom_wall = 1;
      m1->visited = 0;
    }
  }
}

void free_maze_context(struct maze_context *m) {
  free(m->c);
  free(m);
}

int get_leftwall_code(struct maze_context *maze, int y, int x) {

  struct cell *c = maze->c;
  int w = maze->width;

  struct cell *m;
  struct cell *m1;
  m = &c[(y * w) + x];
  uint8_t l = 0;
  uint8_t r = m->top_wall;
  uint8_t t = 0;
  uint8_t b = m->left_wall;

  if (x != 0) {
    m1 = &c[(y * w) + (x - 1)];
    l = m1->top_wall;
  }

  if (y != 0) {
    m1 = &c[((y - 1) * w) + x];
    t = m1->left_wall;
  }

  // TBLR

  int cc = r | l << 1 | b << 2 | t << 3;
  return cc;
}

int get_bottomwall_code(struct maze_context *maze, int y, int x) {

  struct cell *c = maze->c;
  int w = maze->width;

  struct cell *m;
  struct cell *m1;
  m = &c[(y * w) + x];
  uint8_t l = 0;
  uint8_t r = m->bottom_wall;
  uint8_t t = m->left_wall;
  uint8_t b = 0;

  if (x != 0) {
    m1 = &c[(y * w) + (x - 1)];
    l = m1->bottom_wall;
  }

  // TBLR

  int cc = r | l << 1 | b << 2 | t << 3;
  return cc;
}

int get_rightwall_code(struct maze_context *maze, int y, int x) {
  struct cell *c = maze->c;
  int w = maze->width;

  struct cell *m;
  struct cell *m1;
  m = &c[(y * w) + x];
  uint8_t l = m->top_wall;
  uint8_t r = 0;
  uint8_t t = 0;
  uint8_t b = m->right_wall;

  if (y != 0) {
    m1 = &c[((y - 1) * w) + x];
    t = m1->right_wall;
  }

  // TBLR

  int cc = r | l << 1 | b << 2 | t << 3;
  return cc;
}

int get_brcorner_code(struct maze_context *maze) {

  struct cell *c = maze->c;
  int h = maze->height;
  int w = maze->width;

  struct cell *m;
  struct cell *m1;
  m = &c[((h - 1) * w) + (w - 1)];
  uint8_t l = m->bottom_wall;
  uint8_t r = 0;
  uint8_t t = m->right_wall;
  uint8_t b = 0;

  // TBLR

  int cc = r | l << 1 | b << 2 | t << 3;
  return cc;
}

void draw_maze(struct maze_context *maze, int y_pos, int x_pos) {
  // \033[<y>;<x>H

  int h = maze->h;
  int w = maze->w;
  struct cell *c = maze->c;

  struct cell *m;
  struct cell *m_top;
  struct cell *m_bottom;
  int x_gap = 4;
  int y_gap = 2;

  // draw the correct left edge of a cell. will do most cells except for the
  // right most wall of the maze and the bottom most wall of the maze
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int cc = get_leftwall_code(maze, y, x);
      // printf("\033[%d;%dH%s", (y * y_gap) + y_pos, (x * x_gap) + x_pos,
      //        corner[cc]); // using ANSI escape code \033[<y>;<x>H to position
      //                     // the edges on the screen
      DrawRectangle((x * x_gap) + x_pos, (y * y_gap) + y_pos, 10, 10, WHITE);
    }
  }

  // draw the correct bottom edge of the bottom most cells
  for (int x = 0; x < w; x++) {
    int cc = get_bottomwall_code(maze, (h - 1), x);
    printf("\033[%d;%dH%s", ((h - 1) * y_gap) + y_pos + 2, (x * x_gap) + x_pos,
           corner[cc]);
  }

  // draw the correct right edge of the right most cells
  for (int y = 0; y < h; y++) {
    int cc = get_rightwall_code(maze, y, (w - 1));
    printf("\033[%d;%dH%s", (y * y_gap) + y_pos, ((w - 1) * x_gap) + x_pos + 4,
           corner[cc]);
  }

  // draw the correct bottom right edge of the maze
  int cc1 = get_brcorner_code(maze);
  printf("\033[%d;%dH%s", ((h - 1) * y_gap) + y_pos + 2,
         ((w - 1) * x_gap) + x_pos + 4, corner[cc1]);

  // draw the walls
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      m = &c[(y * w) + x];
      //////
      if (m->top_wall) {
        printf("\033[%d;%dH───", (y * y_gap) + y_pos, (x * x_gap) + x_pos + 1);
      } else {
        printf("\033[%d;%dH   ", (y * y_gap) + y_pos, (x * x_gap) + x_pos + 1);
      }

      if (m->bottom_wall) {
        printf("\033[%d;%dH───", (y * y_gap) + y_pos + 2,
               (x * x_gap) + x_pos + 1);
      } else {
        printf("\033[%d;%dH   ", (y * y_gap) + y_pos + 2,
               (x * x_gap) + x_pos + 1);
      }

      if (m->left_wall) {
        printf("\033[%d;%dH│", (y * y_gap) + y_pos + 1, (x * x_gap) + x_pos);
      } else {
        printf("\033[%d;%dH ", (y * y_gap) + y_pos + 1, (x * x_gap) + x_pos);
      }

      if (m->right_wall) {
        printf("\033[%d;%dH│", (y * y_gap) + y_pos + 1,
               (x * x_gap) + x_pos + 4);
      } else {
        printf("\033[%d;%dH ", (y * y_gap) + y_pos + 1,
               (x * x_gap) + x_pos + 4);
      }
      //////
    }
  }

  printf("\033[2B\n"); // push cursor 1 line and then do a new line
}

int main() {

  Engine::Window window(1280, 720, "Window");
  window.init();
  while (!WindowShouldClose()) { // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawFPS(0, 0);
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  return 0;
}
