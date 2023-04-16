#pragma once
#include <iostream>
#include <string>
#include <algorithm>
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

        string get_card_type();

        string get_card_value();

        int get_strength();

        int calc_strength(const string&);

        string card_to_string();

        string capitalize(const string& str);
    };

}