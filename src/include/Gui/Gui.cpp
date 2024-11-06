#include "Gui.h"
#include "raylib.h"
#include <stdbool.h>

Button::Button(const char *imag, Vector2 position, float scale) {
  texture = LoadTexture(imag);
  this->position = position;
  this->scale = scale;
}

Button::~Button() { UnloadTexture(texture); }

void Button::Draw() { DrawTextureEx(texture, position, 0, scale, RAYWHITE); }

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {

  Rectangle rec = {position.x, position.y, float(texture.width),
                   float(texture.height)};

  if (CheckCollisionPointRec(mousePos, rec) && mousePressed) {
    return true;
  } else {
    return false;
  };

  return 0;
}
