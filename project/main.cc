#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include "concretegame.h"
#include "player.h"
#include "game.h"
#include "concretegame.h"
#include "observer.h"

int my_min(int x, int y) {  // min function, returns the minimum int
    if(x < y) return x;
    return y;
}

int main( int argc, char * argv[]) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    if ( argc > 1 ) {
		try {
			seed = std::stoi( std::string{ argv[1] } );
		} catch( std::invalid_argument & e ) {
			std::cerr << e.what() << std::endl;
			return 1;
		} catch( std::out_of_range & e ) {
			std::cerr << e.what() << std::endl;
			return -1;
		} // catch
	}

//	    std::cout << "DEBUG 1" << std::endl;

	ConcreteGame g;
	char ch;
	Player p[4] = { Player{&g, true}, Player{&g, true}, Player{&g, true}, Player{&g, true}};
    int play_num;

//    	std::cout << "DEBUG 2" << std::endl;

    for(int i = 0; i < 4; ++i) {    // set human or computer
        std::cout << "Is Player"<< i + 1 << " a human (h) or a computer (c)?" << std::endl;
        std::cin >> ch;
        if(ch == 'h') {
            continue;
        } else if (ch == 'c') {
            p[i].setComputer();
        } else {
            std::cerr << "Invalid choice for the type of the player! " << std::endl;
            return 1;
        }
//        std::cout << "address of g : " << p[i].getSubject() << std::endl;
    }

//    std::cout << "DEBUG 3" << std::endl;

    bool end_flag = true;
    while(end_flag) {   // each time of loop corresponds to a round
        int turn_num = 0;
        g.setDeck(seed);    // reset table and shuffle
//  	std::cout << "DEBUG 4" << std::endl;
  	for(int i = 0; i < 4; ++i)  {// reset each player
            p[i].new_round(i);
//            std::cout << "address of g : " << p[i].getSubject() << std::endl;
  	}
//	std::cout << "DEBUG 5" << std::endl;
        std::cout << "A new round begins. It's Player";
//	std::cout << "DEBUG 6" << std::endl;
        for(int j = 0; j < 4; ++j) {
//        std::cout << "DEBUG 7" << std::endl;
            for(auto it : p[j].getHand()) {
//        std::cout << "DEBUG 8" << std::endl;
                if(it == "7S") {
//                    std::cout << "DEBUG 9" << std::endl;
                    std::cout << j + 1 << "'s turn to play." << std::endl;
                    play_num = j;
                }
            }
        }
//	std::cout << "DEBUG 10" << std::endl;
//        g.printTable();
//        std::cout << "address of g : " << &g << std::endl;
        try {
//            std::cout << "address of g : " << p[play_num].getSubject() << std::endl;
//            std::cout << "play_num : " << play_num << std::endl;
            p[play_num].doTurn(true, play_num);
        } catch(quit_program) {
            return 0;
        }
//        std::cout << "DEBUG 11" << std::endl;
//        p[play_num].printStatus();
        g.notifyObserver();
//        std::cout << "DEBUG 12" << std::endl;
        ++turn_num;
        while(turn_num < 52) {
            ++turn_num;
            play_num = (play_num + 1) % 4;
            try {
                p[play_num].doTurn(false, play_num);
            } catch(quit_program) {
                return 0;
            }
//            p[play_num].printStatus();
            g.notifyObserver();
        }
        for(int i = 0; i < 4; ++i) { // conclusion of each round
            p[i].addScore(p[i].getScore());
            if(p[i].getTotScore() >= 80) {
                end_flag = false;
            }
            std::cout << "Player" << i + 1 << "'s discards:";
            for(auto it : p[i].getDiscard()) std::cout << " " << it;
            std::cout << std::endl << "Player" << i + 1 << "'s score:";
            int sc = p[i].getTotScore() - p[i].getScore();
            std::cout << " " << sc << " + " << p[i].getScore() << " = " << p[i].getTotScore();
            std::cout << std::endl;
        }
        if(!end_flag) {     // find the winner of the game
            int min_score = 999999;
            for(int i = 0; i < 4; ++i) {
                min_score = my_min(min_score, p[i].getTotScore());
            }
            for(int i = 0; i < 4; ++i) {
                if(p[i].getTotScore() == min_score)
                    std::cout << "Player" << i + 1 << " wins!" << std::endl;
            }
        }
    }

}
