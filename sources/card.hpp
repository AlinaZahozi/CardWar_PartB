#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel{

    class Card {
        
    string card_type;
    string card_value;
  
    public:
        static int number_of_cards;
        // Constructor
        Card(string,string);

        // Getters 
        int get_number_of_cards(){
            return number_of_cards;
        }

        string get_card_type(){
            return card_type;
        }

        string get_card_value(){
            return card_value;
        }

        int calculate_card_value();


        // To string
        string to_string();
    };

}