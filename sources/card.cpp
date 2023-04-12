#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;


namespace ariel{

    int Card::number_of_cards = 0;

    // Constructor
    Card::Card(string typ , string val){
        this->card_type = typ;
        this->card_value = val;
    }

    int Card::calculate_card_value(){
        return 0;
    }


    // To string
    string Card::to_string(){
        return "Card";
    }

}