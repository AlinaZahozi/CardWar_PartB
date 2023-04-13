#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
//# include <unistd.h>
#include <string>
#include "player.hpp"
#include "card.hpp"
#include "cardStack.hpp"
using namespace std;


namespace ariel{

    class Game {
        private:  
        Player &first_player;
        Player &second_player; 
        CardStack cardsToDivide;
        string log;
        string last_turn;
        int number_of_draws;
        
        public:
            // Constructor
            Game(Player&,Player&);

            // Getters 
            Player get_first_player();
            Player get_second_player();
            string get_log();
            string get_last_turn();
            int get_number_of_draws();


            // Methods
            void dividecards();
            void playTurn();
            void playdraw();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            void add_to_log(string);
    };

}