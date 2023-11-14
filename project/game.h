#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "observer.h"

class Game {
    std::vector<Observer*> observers;

  public:
    Game();
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObserver();
    virtual ~Game() = 0;
};

#endif // _GAME_H_
