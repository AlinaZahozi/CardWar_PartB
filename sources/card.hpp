#pragma once
#include <iostream>
#include <string>
#include <algorithm> //for capitalize method
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

        //Get card type
        string get_card_type();

        //Get card value
        string get_card_value();

        //Get card strength
        int get_strength();

        //calculate card strength
        int calc_strength(const string&);

        // To string
        string card_to_string();

        //Converts the string to the required form, i.e. the first letter is uppercase and the rest are lowercase.
        string capitalize(const string& str);
    };

}