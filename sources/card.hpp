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
       // Card(const Card& other);
        //~Card();
       // Card& operator=(const Card& other);

        string get_card_type() const;

        string get_card_value() const;

        int get_strength() const;

        int calc_strength(string) const;

        string to_string() const;
    };

}