#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;


namespace ariel{

    // Constructor
    Card::Card(string typ , string val){
        this->card_type = typ;
        this->card_value = val;
    }

    string Card::get_card_type(){
        return card_type;
    }

    string Card::get_card_value(){
        return card_value;
    }

    // To string
    string Card::to_string(){
        return "Card";
    }

}