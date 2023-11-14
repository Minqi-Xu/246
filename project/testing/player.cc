#include "player.h"
#include <iostream>
#include <algorithm>

Player::Player(ConcreteGame *g, bool human) :
    subject{g}, is_Human{human}
{
    subject->attach(this);
}

int Player::getScore() {
    int ans = 0;
    for(int i = 0; i < discard.size(); ++i) {
        if(((discard.at(i))[0]) <= '9' && ((discard.at(i))[0]) >= 2) {
            ans = ans + (((discard.at(i))[0]) - '0');
        } else if(((discard.at(i))[0]) == 'T') {
            ans += 10;
        } else if(((discard.at(i))[0]) == 'A') {
            ++ans;
        } else if(((discard.at(i))[0]) == 'J') {
            ans += 11;
        } else if(((discard.at(i))[0]) == 'Q') {
            ans += 12;
        } else { ans += 13; }
    }
    return ans;
}

std::vector<std::string> Player::getHand() {
    return hand;
}

void Player::printStatus() {
    std::cout << "Your hand:";
    for(int i = 0; i < hand.size(); ++i) {
        std::cout << " " << hand.at(i);
    }
    std::cout << std::endl << "Legal plays:";
    for(int i = 0; i < legal_play.size(); ++i) {
        std::cout << " " << legal_play.at(i);
    }
    std::cout << std::endl;
}

void Player::doTurn(bool first_play, int play_num) {
    std::string command = "", card = "";
//    std::cout << "doTurn debug 1" << std::endl;
    if(first_play) {
//        std::cout << "doTurn debug 2" << std::endl;
//        std::cout << "address of g: " << subject << std::endl;
        subject->printTable();
        std::cout << "Your hand:";
//        std::cout << "doTurn debug 3" << std::endl;
        for(int i = 0; i < hand.size(); ++i) {
            std::cout << " " << hand.at(i);
        }
        std::cout << std::endl << "Legal plays: 7S"<< std::endl;
        if(!is_Human) {
            std::cout << "Player" << play_num + 1 << " plays 7S" << std::endl;
            subject->putTable("7S");
            hand.erase(std::find(begin(hand), end(hand), "7S"));
        } else {
            while(true){
                std::cin >> command;
                if(command == "quit") {
                    throw quit_program{};
                } else if(command == "deck") {
                    subject->printDeck();
                } else if(command == "ragequit") {
                    this->setComputer();
                    std::cout << "Player " << play_num + 1 << " ragequits. A computer will now take over." << std::endl;
                    std::cout << "Player" << play_num + 1 << " plays 7S." << std::endl;
                    subject->putTable("7S");
                    hand.erase(std::find(begin(hand), end(hand), "7S"));
                } else if(command == "play") {
                    std::cin >> card;
                    if(card == "7S") {
                        std::cout << "Player" << play_num + 1 << " plays 7S." << std::endl;
                        subject->putTable("7S");
                        hand.erase(std::find(begin(hand), end(hand), card));
                        break;
                    } else {
                        std::cout << "This is not a legal play." << std::endl;
                        continue;
                    }
                } else if(command == "discard") {
                    std::cin >> card;
                    std::cout << "You have a legal play. You may not discard." << std::endl;
                    continue;
                } else {
                    std::cerr << "Invalid command!" << std::endl;
                    continue;
                }
            }
        }
    return;
    }

    subject->printTable();
    this->printStatus();
    if(!is_Human) {
        if(legal_play.size() != 0) {
            std::cout << "Player" << play_num + 1 << " plays " << legal_play.at(0) << "." << std::endl;
//            std::cout << "Debug message : position 1" << std::endl;
            subject->putTable(legal_play.at(0));
//            std::cout << "Debug message : position 2" << std::endl;
            hand.erase(std::find(begin(hand), end(hand), legal_play.at(0)));
//            std::cout << "Debug message : position 3" << std::endl;
        } else {
            std::cout << "Player " << play_num + 1 << " discards " << hand.at(0) << "." << std::endl;
//            std::cout << "Debug message : position 11" << std::endl;
            discard.emplace_back(hand.at(0));
//            std::cout << "Debug message : position 12" << std::endl;
            hand.erase(hand.begin());
//            std::cout << "Debug message : position 13" << std::endl;
        }
    } else {
        while(true) {
            std::cin >> command;
            if(command == "quit") {
                throw quit_program{};
            } else if(command == "deck") {
                subject->printDeck();
            } else if(command == "ragequit") {
                this->setComputer();
                std::cout << "Player " << play_num + 1 << " ragequits. A computer will now take over." << std::endl;
                if(legal_play.size() != 0) {
                    std::cout << "Player" << play_num + 1 << " plays " << legal_play.at(0) << "." << std::endl;
                    subject->putTable(legal_play.at(0));
                    hand.erase(std::find(begin(hand), end(hand), legal_play.at(0)));
                    break;
                } else {
                    std::cout << "Player " << play_num + 1 << " discards " << hand.at(0) << "." << std::endl;
                    discard.emplace_back(hand.at(0));
                    hand.erase(hand.begin());
                    break;
                }
            } else if(command == "play") {
                std::cin >> card;
                if(std::find(begin(legal_play), end(legal_play), card) == end(legal_play)) {
                    std::cout << "This is not a legal play." << std::endl;
                    continue;
                } else {
                    std::cout << "Player" << play_num + 1 << " plays " << card << "." <<std::endl;
                    subject->putTable(card);
                    hand.erase(std::find(begin(hand), end(hand), card));
                }
                break;
            } else if(command == "discard") {
                std::cin >> card;
                if(legal_play.size() > 0) {
                    std::cout << "You have a legal play. You may not discard." << std::endl;
                    continue;
                } else {
                    if(std::find(begin(hand), end(hand), card) == end(hand)) {
                        std::cerr << "Invalid card choice, no such card found." << std::endl;
                        continue;
                    } else {
                        std::cout << "Player " << play_num + 1 << " discards " << card << "." << std::endl;
                        discard.emplace_back(card);
                        hand.erase(std::find(begin(hand), end(hand), card));
                    }
                }
                break;
            } else {
                    std::cerr << "Invalid command!" << std::endl;
                    continue;
            }
        }
    }
}

void Player::notify() {
//    std::cout << "DEBUG MESSAGE: notify start" << std::endl;
    legal_play.clear();
    std::vector<std::vector<std::string>> current_table = subject->getTable();
    for(int i = 0; i < 3; ++i) {
        if((current_table.at(i)).size() == 0) {
            for(auto it = hand.begin(); it != hand.end(); ++it) {
                if(*it == "7C" && i == 0) legal_play.emplace_back("7C");
                if(*it == "7D" && i == 1) legal_play.emplace_back("7D");
                if(*it == "7H" && i == 2) legal_play.emplace_back("7H");
                if(*it == "7S" && i == 3) legal_play.emplace_back("7S");
            }
        } else {
            char legal1, legal2;
            if(subject->getMin(i) == '2') {
                legal1 = 'A';
            } else if (subject->getMin(i) == 'A') {
                legal1 = 'A';
            } else {
                legal1 = subject->getMin(i) - 1;
            }
            switch(subject->getMax(i)) {
                case '7':
                    legal2 = '8';
                    break;
                case '8':
                    legal2 = '9';
                    break;
                case '9':
                    legal2 = 'T';
                    break;
                case 'T':
                    legal2 = 'J';
                    break;
                case 'J':
                    legal2 = 'Q';
                    break;
                case 'Q':
                    legal2 = 'K';
                    break;
                default:
                    legal2 = 'K';
                    break;
            }
            if(i == 0) {
                for(auto it = hand.begin(); it != hand.end(); ++it) {
                    if(((*it)[0] == legal1||(*it)[0] == legal2) && (*it)[1] == 'C')
                        legal_play.emplace_back(*it);
                }
            } else if(i == 1) {
                for(auto it = hand.begin(); it != hand.end(); ++it) {
                    if(((*it)[0] == legal1||(*it)[0] == legal2) && (*it)[1] == 'D')
                        legal_play.emplace_back(*it);
                }
            } else if(i == 2) {
                for(auto it = hand.begin(); it != hand.end(); ++it) {
                    if(((*it)[0] == legal1||(*it)[0] == legal2) && (*it)[1] == 'H')
                        legal_play.emplace_back(*it);
                }
            } else {
                for(auto it = hand.begin(); it != hand.end(); ++it) {
                    if(((*it)[0] == legal1||(*it)[0] == legal2) && (*it)[1] == 'S')
                        legal_play.emplace_back(*it);
                }
            }
        }
    }
//    std::cout << "DEBUG MESSAGE: notify end" << std::endl;
}

bool Player::isHuman() {
    return is_Human;
}

void Player::setComputer() {
    is_Human = false;
}

void Player::addScore(int s) {
    scores.emplace_back(s);
}

int Player::getTotScore() {
    int ans = 0;
    for(auto i : scores) {
        ans += i;
    }
    return ans;
}

std::vector<std::string> Player::getDiscard() {
    return discard;
}

void Player::new_round(int play_num) {
    discard.clear();
    legal_play.clear();
    hand.clear();
    for(int i = play_num * 13; i < (play_num + 1) * 13; ++i)
        hand.emplace_back((subject->getDeck()).at(i));
}

ConcreteGame* Player::getSubject() {
    return subject;
}
