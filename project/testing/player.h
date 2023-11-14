#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include "observer.h"
#include "concretegame.h"

class quit_program{};

class Player: public Observer {
    ConcreteGame *subject;
    bool is_Human; // boolean to indicate human(1), computer(0)
    std::vector<std::string> hand;
    std::vector<std::string> discard;
    std::vector<std::string> legal_play;
    std::vector<int> scores; // record the historical scores

  public:
    Player(ConcreteGame *g, bool human);
    int getScore();
    std::vector<std::string> getHand();
    void printStatus();
    void doTurn(bool first_play, int play_num); // first_play indicates that if
                                  //it's the first player of a new round
    void notify();
    bool isHuman();
    void setComputer();
    void addScore(int s);
    int getTotScore();
    std::vector<std::string> getDiscard();
    void new_round(int play_num);
    ConcreteGame *getSubject(); // debug use
};

#endif // _PLAYER_H_
