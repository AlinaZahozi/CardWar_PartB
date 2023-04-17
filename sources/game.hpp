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
        Player &first_player;
        Player &second_player; 
        CardStack cardsToDivide;
        string log;
        string last_turn;
        int number_of_draws;
        bool set_winner;
        bool print_winner;
        
        public:
            // Constructor
            Game(Player&,Player&);

            // Get first player
            Player get_first_player();

            // Get second player
            Player get_second_player();

            // Get log - game history
            string get_log();

            //Get last turn - last turn history
            string get_last_turn();

            //Get the number of draws so far
            int get_number_of_draws();

            //set last turn
            void set_last_turn(const string& move);

            //Append the last turn to game history log
            void appendTolog(const string& appendString);

            //Append the last turn to last turn game history
            void appendToLastTurn(const string& appendString);

            //Divides the cards between the 2 players
            void dividecards();

            //Play a turn in the game
            void playTurn();

            //Play a turn in the game and reterns an flag output
            int playTurn(string);

            //Prints the last turn game history
            void printLastTurn();

            //Runs turns in the game until there is a winner
            void playAll();

            //Prints the winner at the end of the game
            void printWiner();
            
            //Prints the game history so far
            void printLog();

            //Calculates the draw rate and displays as a string
            string draw_rate();

            //Prints basic statistics for each player 
            void printStats();
    };

}