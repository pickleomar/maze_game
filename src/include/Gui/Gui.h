#pragma once
#include <raylib.h>

class Button {
public:
  Button(const char *imag, Vector2 position, float scale);
  ~Button();
  void Draw();
  bool isPressed(Vector2 mousePos, bool mousePressed);

private:
  Texture2D texture;
  Vector2 position;
  float scale;
};
