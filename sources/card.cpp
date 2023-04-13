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

    //Get card type
    string Card::get_card_type(){
        return this->card_type ;
    }

    //Get card value
    string Card::get_card_value(){
        return this->card_value;
    }

    // To string
    string Card::to_string(){
        return "Card type is: " + this->card_type + " and Card value is: " + this->card_value;
    }

}