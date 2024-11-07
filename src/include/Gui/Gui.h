#pragma once
#include <raylib.h>

#define NUM_FRAMES 3

#define BTN_NORMAL 0
#define BTN_HOVERED 1
#define BTN_PRESSED 2

class Button {
public:
  Button(const char *filename, float scale, Vector2 position);
  // ~Button();
  void drawbutton();
  void setState(int state);
  Rectangle getBounds();
  bool isPressed();
  void checkState(Vector2 mousePos);
  Texture2D texture;

private:
  Rectangle buttonBouds;
  Vector2 position;
  float scale;
  int state = BTN_NORMAL;
  bool buttonAction = false;
};
