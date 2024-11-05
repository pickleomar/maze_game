#pragma once

#include <string>
using string = std::string;

class Window {
public:
  // Init window int height= 0 and width=0
  Window(string window_title);
  // Init window with all params
  Window(int window_width, int window_height, string window_title);
  ~Window();
  int getWindowHeight();
  int getWindowWidth();
  bool windowCloseConfirmation = false;
  bool ShouldClose(void);
  void SetConfigFlags(unsigned int flags);
  void SetExitKey(int key);
  int windowHeight(void);
  int windowWidth(void);

private:
  string __win_title;
  int __win_width = 0;
  int __win_height = 0;

  void init(void);
};
