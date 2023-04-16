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
Game::Game(Player& p1 ,Player& p2):
    first_player(p1),
    second_player(p2)
    {
    if(p1.get_is_availible() == true){
        if(p2.get_is_availible() == true){
            first_player.set_is_availible(false);
            second_player.set_is_availible(false);
            this->number_of_draws = 0;
            dividecards();
        }
        else{
            cout << " " << p2.get_player_name() << "is not availible to play";
        }
    }
    else{
        cout << " " << p1.get_player_name() << "is not availible to play";
    }
}

void Game::dividecards(){
    cout << to_string(cardsToDivide.cards.size()) << endl;
    for(int i = 52,j = 20; i > 0 ; i--){
        srand((unsigned)j);
        Card &c = cardsToDivide.cards.top();
        cardsToDivide.cards.pop();
        int sum = i+j;
        int ran = ((rand()) % j++) + 1 + rand()%(sum); // Get a random number
        cout << "rand:" << to_string(ran) << endl;
        if((ran%2) == 0 && first_player.stacksize() < 26){
            first_player.sPush(c);
        }
        else if(second_player.stacksize() < 26){
            second_player.sPush(c);
        }
        else{
            first_player.sPush(c);
        } 
    }
}

// Getters 
Player Game::get_first_player(){
    return this->first_player;
}

Player Game::get_second_player(){
    return this->second_player;
}

int Game::get_number_of_draws(){
    return this->number_of_draws;
}

string Game::get_log(){
    return this->log;
}
            
string Game::get_last_turn(){
    return this->last_turn;
}

void Game::set_last_turn(const string& move){
    this->last_turn = move;
}

void Game::playTurn(){
    set_last_turn("");
    int flag =  this->playTurn("");
    if(flag == 0) throw string("Error");
    printLastTurn();
}

// Methods
int Game::playTurn(string move){
    try{
    string last_move = move;
    if(first_player.get_player_name().compare(second_player.get_player_name()) == 0){
        if(first_player.get_identification_number() == second_player.get_identification_number()) throw string("You have entered the same player. Please enter another player"); 
    }
    if(first_player.stacksize() == 0 ||second_player.stacksize() == 0) throw string("Game is already over");
    first_player.set_total_games_played();
    second_player.set_total_games_played();
    Card& c1 = first_player.sTop();
    Card& c2 = second_player.sTop();
    string card1 = c1.card_to_string();
    string card2 = c2.card_to_string();
    first_player.sPop();
    second_player.sPop();
    int strength1 = c1.get_strength();
    int strength2 = c2.get_strength();
    if(strength1 == 14 && strength2 == 2){
        second_player.addWin();
        second_player.add_card_to_cards_won(card1);
        second_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". " + second_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        return 2;
    }
    else if(strength1 == 2 && strength2 == 14){
        first_player.addWin();
        first_player.add_card_to_cards_won(card1);
        first_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". " + first_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        return 1;
    }
    else{
        if(strength1 > strength2){
        first_player.addWin();
        first_player.add_card_to_cards_won(card1);
        first_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". " + first_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        return 1;
        }
        else if(strength1 < strength2){
        second_player.addWin();
        second_player.add_card_to_cards_won(card1);
        second_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". " + second_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        return 2;
        }
        else if(strength1 == strength2){
            this->number_of_draws++;
            if(first_player.stacksize() == 0 ||second_player.stacksize() == 0){
                printWiner();
                return 3;
            }
            else{
                last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". Draw." );
                int winner = playTurn(last_move);
                if( winner == 1){
                    first_player.addWin();
                    first_player.add_card_to_cards_won(card1);
                    first_player.add_card_to_cards_won(card2);
                    return 1;
                }
                else if( winner == 2){
                    second_player.addWin();
                    second_player.add_card_to_cards_won(card1);
                    second_player.add_card_to_cards_won(card2);
                    return 2;
                }
                else return 0;
            }
        }
    }
    }catch(string message){
        cout << "error: " << message << endl;
    }
    return 0;
}

void Game::printLastTurn(){
    cout << this->last_turn;
}

void Game::playAll(){
    if(first_player.stacksize() == 0 ||second_player.stacksize() == 0) throw string("Game is already over");
    bool flag = false;
    for (int i = 26; flag == false && i > 0 ;i--) {
        if(first_player.stacksize() == 0 ||second_player.stacksize() == 0){
            printWiner();
            flag = true;
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
    first_player.set_is_availible(true);
    second_player.set_is_availible(true);
}


void Game::printLog(){
   cout << get_log();
}

string Game::draw_rate(){
    int ans = (this->get_number_of_draws() * 100) / this->first_player.get_total_games_played();
    return to_string(ans);
}

void Game::printStats(){
    cout << "Players name: " << this->first_player.get_player_name() << ", win rate: " << this->first_player.get_total_wins() << "% , cards won: " << this->first_player.get_cards_won() << endl; 
    cout << "Players name: " << this->second_player.get_player_name() << ", win rate: " << this->second_player.get_total_wins() << ", cards won: " << this->second_player.get_cards_won()  << endl; 
    cout << "Draw rate:" << this->draw_rate() << "% , amount of draws that happand:" << this->get_number_of_draws() << endl;    
}

void Game::appendTolog(const string& appendString){
    this->log.append(appendString);
}

void Game::appendToLastTurn(const string& appendString){
    this->last_turn.append(appendString);

}

}