
#include "Engine.h"
#include "raylib.h"
using namespace Engine;

Game::Game() { this->onMount(); }
Game::~Game() { this->onDestroy(); }

void Game::onMount() { return; }
void Game::onDestroy() { return; }
void Game::OnUpdate() { return; }
