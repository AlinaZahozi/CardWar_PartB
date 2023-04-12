#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std;

#include "card.hpp"

namespace ariel{

    class Player {
    private:  
        string player_name;
        int player_number;
        bool is_availible;
        stack<Card> cards;
        int num_of_taken_cards;
        string cards_won;
        int total_wins;


    public: 
    
        // Constructor
        Player(){}
        Player(string);

        // Getters 
        string get_player_name();
        int get_player_number();
        bool get_is_availible();
        stack<Card> get_cards();
        int get_num_of_taken_cards();
        string get_cards_won();
        int get_total_wins();

        // Setters
        void set_player_name(string);
        void set_is_availible(bool);

        // To string
        string to_string();

        // Methods
        int stacksize();
        int cardesTaken();
    };

}