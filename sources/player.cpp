#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "player.hpp"
#include "card.hpp"
using namespace std;


namespace ariel{

   // int Player::playerCount = 0;

    // Constructor
    Player::Player(string name) {
       // Player::playerCount++;
        this->player_name = name;
        cout << "players name: " << 
       // this->player_number = Player::playerCount;
        this->is_availible = true;
        this->num_of_taken_cards = 0;
        this->cards_won = "";
        this->total_wins = 0;
        this->total_games_played = 0;
        //cout << "dsvd" << to_string(cards.size());

        srand((unsigned) time(NULL));
        this->identification_number = rand();
    }

    // Getters 
    string Player::get_player_name(){
        return this->player_name;
    }

    int Player::get_identification_number(){
        return this->identification_number;
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

    int Player::get_total_games_played(){
        return this->total_games_played;
    }

    // Setter
    void Player::set_player_name(string name) {
        this->player_name = name;
    }

    void Player::set_is_availible(bool b){
        this->is_availible = b;
    }

    void Player::set_total_games_played(){
        this->total_games_played++ ;
    }

    void Player::add_card_to_cards_won(string card){
        if(this->num_of_taken_cards == 1){
            this->cards_won + card;
        }
        else{
            this->cards_won + ", " + card;
        }
    }

    void Player::addWin(){
        this->num_of_taken_cards++;
        this->total_wins++;
    }

    // To string
    /*
    string Player::to_string() {
        return "" + this->player_name;
    }*/

    int Player::stacksize(){
        return this->cards.size();
    }

    int Player::cardesTaken(){
        return this->num_of_taken_cards;
    }

    void Player::sPush(Card &pushcard){
        this->cards.push(pushcard);
    }
        
    void Player::sPop(){
        this->cards.pop();
    }

    Card& Player::sTop(){
        return this->cards.top();
    }

    int Player::sSize(){
        return this->cards.size();
    }

}