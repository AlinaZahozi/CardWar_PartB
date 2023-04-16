#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel{

    class Card {
        
    string card_type;
    string card_value;
    string card;
    int strength;
  
    public:
        // Constructor
        Card(string,string);
       // Card(const Card& other);
        //~Card();
       // Card& operator=(const Card& other);

        string get_card_type();

        string get_card_value();

        int get_strength();

        int calc_strength(const string&);

        string card_to_string();
    };

}