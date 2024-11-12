#include "Button.h"
#include "raylib.h"

Button::Button() {}

Button::Button(const char *filename, float scale) : scale(scale) {
  texture = LoadTexture(filename);
}

void Button::SetPosition(Vector2 position) {
  this->position = position;
  this->buttonBouds = {position.x, position.y, (float)texture.width * scale,
                       texture.height * scale / NUM_FRAMES};
}

void Button::setState(int state) { this->state = state; }
void Button::setScale(int scale) { this->scale = scale; }

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
bool Button::isHovered() { return buttonHover; }

void Button::update(Vector2 mousePos) {
  buttonAction = false;
  if (CheckCollisionPointRec(mousePos, buttonBouds)) {
    buttonHover = true;
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
    buttonHover = false;
  }
}
