#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel{

    class Card {
        
    string card_type;
    string card_value;
  
    public:
        // Constructor
        Card(string,string);

        string get_card_type();

        string get_card_value();

        string to_string();
    };

}