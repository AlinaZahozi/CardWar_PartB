#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel{

    class Card {
        
    string card_type;
    string card_value;
    int strength;
  
    public:
        // Constructor
        Card(string,string);

        string get_card_type();

        string get_card_value();

        int get_strength();

        int calc_strength(string);

        string to_string();
    };

}