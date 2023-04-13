#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;


namespace ariel{

    // Constructor
    Card::Card(string typ , string val){
        this->card_type = typ;
        this->card_value = val;
        this->strength = calc_strength(val);
    }

    //Get card type
    string Card::get_card_type(){
        return this->card_type ;
    }

    //Get card value
    string Card::get_card_value(){
        return this->card_value;
    }

    //Get card strength
    int Card::get_strength(){
        return this->strength;
    }

    //calculate card strength
    int Card::calc_strength(string value){
        int ans = 0;
        switch(value){
            case "ACE":
                ans = 14;
                break;
            case "TWO":
                ans = 2;
                break;
            case "THREE";
                ans = 3;
                break;
            case "FOUR";
                ans = 4;
                break;
            case "FIVE";
                ans = 5;
                break;
            case "SIX";
                ans = 6;
                break;
            case "SEVEN";
                ans = 7;
                break;
            case "EIGHT";
                ans = 8;
                break;
            case "NINE";
                ans = 9;
                break;
            case "TEN";
                ans = 10;
                break;
            case "JACK";
                ans = 11;
                break;
            case "QUEEN";
                ans = 12;
                break;
            case "KING";
                ans = 13;
                break;
            default:
                cout << "Error";
                break;
        }
        return ans;
    }

    // To string
    string Card::to_string(){
        return "Card type is: " + this->card_type + " and Card value is: " + this->card_value;
    }

}