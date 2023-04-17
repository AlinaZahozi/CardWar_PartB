#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "player.hpp"
#include "card.hpp"
using namespace std;


namespace ariel{

    // Constructor
    Player::Player(string name){
        this->player_name = name;
        this->set_is_availible(true);
        this->num_of_taken_cards = 0;
        this->total_wins = 0;
        this->total_games_played = 0;
        srand((unsigned) time(NULL)); //Set seed
        this->identification_number = rand();
    }

    // Get Players name string
    string Player::get_player_name(){
        return this->player_name;
    }

    //Get players identification number
    int Player::get_identification_number(){
        return this->identification_number;
    }

    //Get if player is availible
    bool Player::get_is_availible(){
        return this->is_availible;
    }

    //Get the number of cards the player wins
    int Player::get_num_of_taken_cards(){
        return this->num_of_taken_cards;
    }

    //Get cards won string log
    string Player::get_cards_won(){
        return this->cards_won;
    }

    //Get the number of players wins during the game so far
    int Player::get_total_wins(){
        return this->total_wins;
    }

    //Get the numbers of the move played so far
    int Player::get_total_games_played(){
        return this->total_games_played;
    }

    // Set player name
    void Player::set_player_name(const string& name) {
        this->player_name = name;
    }

    //Set if player is availible
    void Player::set_is_availible(bool b){
        this->is_availible = b;
    }

    //move played++
    void Player::set_total_games_played(){
        this->total_games_played++ ;
    }

    //Add string to card won string log
    void Player::add_card_to_cards_won(const string& card){
        if(this->num_of_taken_cards != 1){
            this->cards_won.append(", ");
        }
        this->cards_won.append(card);
    }

    //Add win to player
    void Player::addWin(int number_of_cards){
        this->num_of_taken_cards +=number_of_cards;
        this->total_wins++;
    }

    //Prints the amount of cards left
    int Player::stacksize(){
        return this->cards.size();
    }

    //Prints the amount of cards this player has won
    int Player::cardesTaken(){
        return this->num_of_taken_cards;
    }

    //Push card to players card stack
    void Player::sPush(Card &pushcard){
        this->cards.push(pushcard);
    }

    //Pop card from players card stack    
    void Player::sPop(){
        this->cards.pop();
    }

    //Get top card in players card stack
    Card& Player::sTop(){
        return this->cards.top();
    }

}