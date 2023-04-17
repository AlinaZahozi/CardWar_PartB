#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
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
        bool set_winner;
        
        public:
            // Constructor
            Game(Player&,Player&);
            /*
            Game(const Game& other);
            Game& operator=(const Game& other);
            Game(Game&& other);
            Game& operator=(Game&& other) noexcept ;
            ~Game();*/

            // Getters 
            Player get_first_player();
            Player get_second_player();
            string get_log();
            string get_last_turn();
            int get_number_of_draws();
            bool print_winner;

            void set_last_turn(const string& move);

            void appendTolog(const string& appendString);
            void appendToLastTurn(const string& appendString);


            // Methods
            void dividecards();
            void playTurn();
            int playTurn(string);;
            void printLastTurn();
            void playAll();
            void printWiner();
            //void printWiner(int);
            void printLog();
            string draw_rate();
            void printStats();
    };

}