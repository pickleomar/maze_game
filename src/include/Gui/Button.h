#pragma once
#include <raylib.h>

#define NUM_FRAMES 3

#define BTN_NORMAL 0
#define BTN_HOVERED 1
#define BTN_PRESSED 2

class Button {
public:
  Button();
  Button(const char *filename, float scale);
  // ~Button();
  void drawbutton();
  void setState(int state);
  void setScale(int scale);
  Rectangle getBounds();
  bool isPressed();
  bool isHovered();
  void update(Vector2 mousePos);
  void SetPosition(Vector2 position);
  Vector2 position;
  Texture2D texture;

private:
  Rectangle buttonBouds;
  float scale;
  int state = BTN_NORMAL;
  bool buttonAction = false;
  bool buttonHover = false;
};
