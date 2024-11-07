#include "Gui.h"
#include "raylib.h"
#include <stdbool.h>

Button::Button(const char *filename, float scale, Vector2 position)
    : scale(scale), position(position) {
  texture = LoadTexture(filename);
  this->buttonBouds = {position.x, position.y, (float)texture.width * scale,
                       texture.height * scale / NUM_FRAMES};
}

// Button::~Button() { UnloadTexture(texture); }

void Button::setState(int state) { this->state = state; }

void Button::drawbutton() {
  Rectangle sourceRec = {0, 0, (float)texture.width,
                         (float)texture.height / NUM_FRAMES};

  sourceRec.y = state * (float)texture.height / NUM_FRAMES;

  DrawTexturePro(texture, sourceRec,
                 {buttonBouds.x, buttonBouds.y, (float)texture.width * scale,
                  (float)texture.height / NUM_FRAMES * scale},
                 {0, 0}, 0, WHITE);
}

Rectangle Button::getBounds() { return buttonBouds; }

bool Button::isPressed() { return buttonAction; }

void Button::checkState(Vector2 mousePos) {
  buttonAction = false;
  if (CheckCollisionPointRec(mousePos, buttonBouds)) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      setState(BTN_PRESSED);
    } else {
      setState(BTN_HOVERED);
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
      buttonAction = true;
    }
  } else {
    setState(BTN_NORMAL);
  }
}
