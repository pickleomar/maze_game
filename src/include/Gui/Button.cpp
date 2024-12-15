/*
The Button Class mainly used to main the GUI and create Button using a Texture
*/

#include "Button.h"
#include "raylib.h"

// Empty Constructor
Button::Button() {}

// Initialize The Button using a Texture and scale
Button::Button(const char *filename, float scale) : scale(scale) {
  texture = LoadTexture(filename);
}

// Set The button position at the Screen
void Button::SetPosition(Vector2 position) {
  this->position = position;
  this->buttonBouds = {position.x, position.y, (float)texture.width * scale,
                       texture.height * scale / NUM_FRAMES};
}

// Set The button state (normal,hovered,pressed)
void Button::setState(int state) { this->state = state; }

// Change Button Scale
void Button::setScale(int scale) { this->scale = scale; }

// Draw the button to the Screen
void Button::drawbutton() {
  Rectangle sourceRec = {0, 0, (float)texture.width,
                         (float)texture.height / NUM_FRAMES};

  sourceRec.y = state * (float)texture.height / NUM_FRAMES;

  DrawTexturePro(texture, sourceRec,
                 {buttonBouds.x, buttonBouds.y, (float)texture.width * scale,
                  (float)texture.height / NUM_FRAMES * scale},
                 {0, 0}, 0, WHITE);
}

// Return A rectangle showing all cordinates of the button on the screen
Rectangle Button::getBounds() { return buttonBouds; }

// Check if the Button pressed
bool Button::isPressed() { return buttonAction; }

// Check if the Button Hovered
bool Button::isHovered() { return buttonHover; }

// Update Button state with the User interaction
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
