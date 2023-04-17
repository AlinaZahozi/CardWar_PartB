#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stack>
using namespace std;

#include "card.hpp"
#include "cardStack.hpp"

namespace ariel{

    class Player {

    private:  
        string player_name;
        int identification_number;
        bool is_availible;
        int num_of_taken_cards;
        string cards_won;
        int total_wins;
        int total_games_played;
        stack<Card> cards;

    public: 
        // Constructor
        Player(string);

        // Get Players name string
        string get_player_name();

        //Get players identification number
        int get_identification_number();

        //Get if player is availible
        bool get_is_availible();

        //Get the number of cards the player wins
        int get_num_of_taken_cards();

        //Get cards won string log
        string get_cards_won();

        //Get the number of players wins during the game so far
        int get_total_wins();

        //Get the numbers of the move played so far
        int get_total_games_played();

        // Set player name
        void set_player_name(const string&);

        //Set if player is availible
        void set_is_availible(bool);

        //move played++
        void set_total_games_played();

        //Add string to card won string log
        void add_card_to_cards_won(const string&);

        //Add win to player
        void addWin(int);

        //Prints the amount of cards left
        int stacksize();

        //Prints the amount of cards this player has won
        int cardesTaken();

        //Push card to players card stack
        void sPush(Card &pushcard);

        //Pop card from players card stack
        void sPop();

        //Get top card in players card stack
        Card& sTop();
    };

}