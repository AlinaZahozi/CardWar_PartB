#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "cardStack.hpp"
using namespace std;


namespace ariel{

// Constructor
Game::Game(Player p1 ,Player p2){
    if(p1.get_is_availible() == true){
        if(p2.get_is_availible() == true){
            this->first_player = p1;
            this->second_player = p2;
            this->log = "";
            this->last_turn= "";
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

string Game::get_last_turn(){
    return this->last_turn;
}

int Game::get_number_of_draws(){
    return this->number_of_draws;
}

// Methods
void Game::playTurn(){
    if(first_player.stacksize() == 0 ||second_player.stacksize() == 0) throw string("Game is already over");
    Card c1;
    Card c2;
    if(first_player.cards.size() > 0){
        c1 = first_player.cards.pop();
    }
    if(second_player.cards.size() > 0){
        c2 = second_player.cards.pop();
    }
    if(c1.get_strength() == 14 && c2.get_strength() == 2){
        second_player.addWin();
    }
    else if(c1.get_strength() == 2 && c2.get_strength() == 14){
        first_player.addWin();
    }
    else{
        if(c1.get_strength() > c2.get_strength()){
            first_player.addWin();
        }
        else if(c1.get_strength() < c2.get_strength()){
            second_player.addWin();
        }
        else if(c1.get_strength() == c2.get_strength()){
            
            playdraw();
        }
    }
}

void Game::playdraw(){
    if(first_player.stacksize() == 0 ||second_player.stacksize() == 0){
        printWiner();
    }
    else{
        this->number_of_draws++;
        playTurn();
    }
}

void Game::printLastTurn(){
    cout << " ";
}

void Game::playAll(){
    if(first_player.stacksize() == 0 ||second_player.stacksize() == 0) throw string("Game is already over");
    for (int i = 26; i > 0 ;i--) {
        if(first_player.stacksize() == 0 ||second_player.stacksize() == 0){
            printWiner();
        }
        else{
            playTurn();
        }
    }
}

void Game::printWiner(){
    if(first_player.get_num_of_taken_cards() == second_player.get_num_of_taken_cards()){
        cout << "Its a draw!" << endl; 
    }
    else if(first_player.get_num_of_taken_cards() > second_player.get_num_of_taken_cards()){
        cout << "" << first_player.get_player_name() << " Wins!" << endl;
    }
    else{
        cout << "" << second_player.get_player_name() << " Wins!"<< endl; 
    }
}

void Game::printLog(){
    cout << this->get_log();
}

void Game::printStats(){
    cout << "Players name: " << this->first_player.get_player_name() << ", win rate: " << this->first_player.get_total_wins() << ", cards won: " << this->first_player.get_num_of_taken_cards()  << endl; 
    cout << "Players name: " << this->second_player.get_player_name() << ", win rate: " << this->second_player.get_total_wins() << ", cards won: " << this->second_player.get_num_of_taken_cards()  << endl; 
    cout << "Draw rate:" << this->get_number_of_draws() << ", amount of draws that happand:" << this->get_number_of_draws() << endl;    
}

void Game::add_to_log(string){
    cout << " ";   
}


}