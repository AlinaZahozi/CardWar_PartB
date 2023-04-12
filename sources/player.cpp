#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"
using namespace std;


namespace ariel{

    // Constructor
    Player::Player(string name) {
        
    }

    // Getters 
    string Player::get_player_name(){
        return this->player_name;
    }

    int Player::get_player_number(){
         return this->player_number;
    }

    stack<Card> Player::get_cards(){
        return this->cards;
    }

    bool Player::get_is_availible(){
        return this->is_availible;
    }

    int Player::get_num_of_taken_cards(){
        return this->num_of_taken_cards;
    }

    string Player::get_cards_won(){
        return this->cards_won;
    }

    int Player::get_total_wins(){
        return this->total_wins;
    }

    // Setter
    void Player::set_player_name(string name) {
        cout << " ";
    }

    void Player::set_is_availible(bool b){
        cout << " ";
    }

    // To string
    string Player::to_string() {
        return "Player ";
    }

    int Player::stacksize(){
        return 0;
    }

    int Player::cardesTaken(){
        return 0;
    }

}