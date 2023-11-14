#include "game.h"

Game::Game() {}
Game::~Game() {}

void Game::attach(Observer *o) {
    observers.emplace_back(o);
}

void Game::detach(Observer *o) {
    for(auto it = observers.begin(); it != observers.end(); ++it) {
        if(*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Game::notifyObserver() {
    for(auto ob : observers) ob->notify();
}
