#include "concretegame.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <memory>

std::string ori[52] = { "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC",
"JC", "QC", "KC", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD",
"QD", "KD", "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH",
"KH", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS"
};

ConcreteGame::ConcreteGame() {
    for(int i = 0; i < 52; ++i) {
        deck.emplace_back(ori[i]);
    }
    table.emplace_back();
    table.emplace_back();
    table.emplace_back();
    table.emplace_back();

}

ConcreteGame::~ConcreteGame() {
    for(int i = 0 ; i < 4; ++i) {
 //       delete table.at(i);
    }
}

std::vector<std::string> ConcreteGame::getDeck() {
    return deck;
}

std::vector<std::vector<std::string>> ConcreteGame::getTable() {
    return table;
}

void ConcreteGame::setDeck(unsigned user_seed) {
    std::default_random_engine rng{user_seed};
    std::shuffle(deck.begin(), deck.end(), rng);
    for(int i = 0; i < 4; ++i) {
        table.at(i).clear();
        table.at(i).resize(0);
    }
}

char ConcreteGame::getMin(int suit) {
    if(table.at(suit).size() == 0)  return 0;
    return (table.at(suit).at(0))[0];
}

char ConcreteGame::getMax(int suit) {
    if(table.at(suit).size() == 0)  return 0;
    return (table.at(suit).at(table.at(suit).size()-1))[0];
}

void ConcreteGame::printTable() {
//    std::cout << "printTable debug 1" << std::endl;
    std::cout << "Cards on the table:" << std::endl;
    std::cout << "Clubs:";
    for(auto it = (table.at(0)).begin() ; it != (table.at(0)).end(); ++it)
        std::cout << " " << (*it)[0];
    std::cout << std::endl;
    std::cout << "Diamonds:";
    for(auto it = (table.at(1)).begin() ; it != (table.at(1)).end(); ++it)
        std::cout << " " << (*it)[0];
    std::cout << std::endl;
    std::cout << "Hearts:";
    for(auto it = (table.at(2)).begin() ; it != (table.at(2)).end(); ++it)
        std::cout << " " << (*it)[0];
    std::cout << std::endl;
    std::cout << "Spades:";
    for(auto it = (table.at(3)).begin() ; it != (table.at(3)).end(); ++it)
        std::cout << " " << (*it)[0];
    std::cout << std::endl;
}

int ConcreteGame::getTableNum() {
    int num = 0;
    for(int i = 0; i < 4; ++i) {
        num += table.at(i).size();
    }
    return num;
}

void ConcreteGame::putTable(std::string card) {
//    std::cout << "Debug message putTable 1" << std::endl;
    switch(card[1]) {
        case 'C':
            if(card[0] == 'A')
                table.at(0).insert(table.at(0).begin(), card);
            else if(card[0] < '7' && card[0] >= '2')
                table.at(0).insert(table.at(0).begin(), card);
            else
                table.at(0).emplace_back(card);
            break;
        case 'D':
            if(card[0] == 'A')
                table.at(1).insert(table.at(1).begin(), card);
            else if(card[0] < '7' && card[0] >= '2')
                table.at(1).insert(table.at(1).begin(), card);
            else
                table.at(1).emplace_back(card);
            break;
        case 'H':
            if(card[0] == 'A')
                table.at(2).insert(table.at(2).begin(), card);
            else if(card[0] < '7' && card[0] >= '2')
                table.at(2).insert(table.at(2).begin(), card);
            else
                table.at(2).emplace_back(card);
            break;
        case 'S':
            if(card[0] == 'A')
                table.at(3).insert(table.at(3).begin(), card);
            else if(card[0] < '7' && card[0] >= '2')
                table.at(3).insert(table.at(3).begin(), card);
            else
                table.at(3).emplace_back(card);
            break;
        default:
            break;
    }
//    std::cout << "Debug message putTable 2" << std::endl;
}

void ConcreteGame::printDeck() {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 13; ++j) {
            std::cout << deck.at(i*13 + j) << " ";
        }
        std::cout << std::endl;
    }
}
