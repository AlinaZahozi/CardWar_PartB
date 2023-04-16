#include <iostream>
#include <string>
#include <algorithm>
#include "card.hpp"
using namespace std;


namespace ariel{

    // Constructor
    Card::Card(string typ , string val){
        this->card_type = typ;
        this->card_value = val;
        this->card = capitalize(val) + " of " + capitalize(typ);
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
    int Card::calc_strength(const string& v){
        int ans = 0;
        if(v.compare("ACE") == 0) ans = 14;
        else if(v.compare("TWO") == 0) ans = 2;
        else if(v.compare("THREE") == 0) ans = 3;
        else if(v.compare("FOUR") == 0) ans = 4;
        else if(v.compare("FIVE") == 0) ans = 5;
        else if(v.compare("SIX") == 0) ans = 6;
        else if(v.compare("SEVEN") == 0) ans = 7;
        else if(v.compare("EIGHT") == 0) ans = 8;
        else if(v.compare("NINE") == 0) ans = 9;
        else if(v.compare("TEN") == 0) ans = 10;
        else if(v.compare("JACK") == 0) ans = 11;
        else if(v.compare("QUEEN") == 0) ans = 12;
        else if(v.compare("KING") == 0) ans = 13;
        else{cout << "Error";}
        return ans;
    }

    // To string
    string Card::card_to_string(){
        return this->card;
    }


    /*string Card::capitalize(const string& str){
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](char c) {return tolower(c);});    
    result[0] = std::toupper(result[0]); 
    return result;
    }*/

    string Card::capitalize(const string& str){
        string ans;
        copy_if(str.begin(), str.end(), back_inserter(ans), [](char c) {return isalpha(c);});
        transform(ans.begin(), ans.end(), ans.begin(), [](char c) {return tolower(c);});
        if (!ans.empty()) {
            ans[0] = toupper(ans[0]);
        }
        return ans;
    }

}