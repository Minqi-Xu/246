#ifndef _CONCRETEGAME_H_
#define _CONCRETEGAME_H_
#include <string>
#include <vector>
#include "game.h"

class ConcreteGame: public Game {
    std::vector<std::string> deck;
    std::vector<std::vector<std::string>> table;

  public:
    ConcreteGame();
    ~ConcreteGame();
    virtual std::vector<std::string> getDeck();
    virtual std::vector<std::vector<std::string>> getTable();
    virtual void setDeck(unsigned user_seed);
    virtual char getMin(int suit);
    virtual char getMax(int suit);
    virtual void printTable();
    virtual int getTableNum(); // get the tot number of cards on table
    virtual void putTable(std::string card);
    virtual void printDeck();
};

#endif // _CONCRETEGAME_H_
