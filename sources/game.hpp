#pragma once
#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"
#include "cardStack.hpp"
using namespace std;


namespace ariel{

    class Game {
        private:  
        Player first_player;
        Player second_player; 
        CardStack cardsToDivide;
        string log;
        int number_of_draws;
        
        public:
            // Constructor
            Game(Player,Player);

            // Getters 
            Player get_first_player();
            Player get_second_player();
            string get_log();
            int get_number_of_draws();
            

            // Setter
            void set_first_player(Player);
            void set_second_player(Player);
            

            // To string
            string to_string();

            // Methods
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            void add_to_log(string);
    };

}