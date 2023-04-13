#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "cardStack.hpp"
using namespace std;



int randomInt (){
  
// Seed the random number generator with the current time

  srand(static_cast<unsigned int>(time(nullptr)));

  
// Generate a random integer between 1 and 100
return rand() % 100 + 1;}

namespace ariel{

// Constructor
Game::Game(Player &p1 ,Player &p2){
    if(p1.get_is_availible() == true){
        if(p2.get_is_availible() == true){
            this->first_player = p1;
            this->second_player = p2;
            this->log = "";
            this->number_of_draws 0;
            
            for(int i = 52; i > 0 ; i--){
                Card c = cardsToDivide.cards.pop();
                srand(static_cast<unsigned int>(time(nullptr)));
                int ran = (rand() % 100) + 1;
                if(ran < 50 && first_player.stacksize() < 26){
                    first_player.cards.push(c);
                }
                else if(second_player.stacksize() < 26){
                    second_player.cards.push(c);
                }
                else{
                    first_player.cards.push(c);
                }
            }
        }
        else{
            cout << "" << p2.get_player_name() << "is not availible to play";
        }
    }
    else{
        cout << "" << p1.get_player_name() << "is not availible to play";
    }
}

// Getters 
Player Game::get_first_player(){
    return this->first_player;
}

Player Game::get_second_player(){
    return this->second_player;
}

string Game::get_log(){
    return this->log;
}

int Game::get_number_of_draws(){
    return this->number_of_draws;
}

// To string
string Game::to_string(){
    return "Game";
}


// Methods
void Game::playTurn(){
    cout << " ";
}

void Game::printLastTurn(){
    cout << " ";
}

void Game::playAll(){
    cout << " ";
}

void Game::printWiner(){
    cout << " ";   
}

void Game::printLog(){
    cout << " ";  
}

void Game::printStats(){
    cout << " ";    
}

void Game::add_to_log(string){
    cout << " ";   
}


}