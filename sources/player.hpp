#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std;

#include "card.hpp"
#include "cardStack.hpp"

namespace ariel{

    class Player {
    private:  
        string player_name;
       // int player_number;
        bool is_availible;
        int num_of_taken_cards;
        string cards_won;
        int total_wins;
        int total_games_played;
        stack<Card> cards;

    public: 
       // static int playerCount;

        // Constructor
        Player(string);

        // Getters 
        string get_player_name();
       // int get_player_number();
        bool get_is_availible();
        int get_num_of_taken_cards();
        string get_cards_won();
        int get_total_wins();
        int get_total_games_played();

        // Setters
        void set_player_name(string);
        void set_is_availible(bool);
        void set_total_games_played(int);
        void addWin();

        // To string
       // string to_string();

        // Methods
        int stacksize();
        int cardesTaken();
        void sPush(Card &pushcard);
        void sPop();
        Card& sTop();
        int sSize();
    };

}