#include <iostream>
#include <cstdlib>
#include <ctime>
//# include <unistd.h>
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
           // this->first_player = p1;
           // this->second_player = p2;
            first_player.set_is_availible(false);
            second_player.set_is_availible(false);
            this->log = "";
            this->last_turn = "";
            this->number_of_draws = 0;
            dividecards();
        }
        else{
            cout << "" << p2.get_player_name() << "is not availible to play";
        }
    }
    else{
        cout << "" << p1.get_player_name() << "is not availible to play";
    }
}

void Game::dividecards(){
    cout << to_string(cardsToDivide.cards.size()) << endl;
    for(int i = 52,j = 20; i > 0 ; i--){
        //srand((unsigned) time(NULL));
        srand((unsigned)j);
        Card &c = cardsToDivide.cards.top();
        cardsToDivide.cards.pop();
        int sum = i+j;
        int ran = ((rand()) % j++) + 1 + rand()%(sum); // Get a random number
        cout << "rand:" << to_string(ran) << endl;
        if((ran%2) == 0 && first_player.stacksize() < 26){
            first_player.sPush(c);
            //cout << "" << first_player.stacksize() << endl;
        }
        else if(second_player.stacksize() < 26){
            second_player.sPush(c);
            //cout << "" << second_player.stacksize() << endl;
            //cout << "" << second_player.stacksize() << endl;
        }
        else{
            first_player.sPush(c);
            //cout << "" << first_player.stacksize() << endl;
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

string Game::get_log(){
    return this->log;
}

string Game::get_last_turn(){
    return this->last_turn;
}

int Game::get_number_of_draws(){
    return this->number_of_draws;
}

void Game::set_last_turn(string move){
    this->last_turn = move;
}

void Game::playTurn(){
   int flag =  this->playTurn("");
    if(flag == 0) throw string("Error");
}

// Methods
int Game::playTurn(string move){
    string last_move = move;
    if(first_player.get_player_name().compare(second_player.get_player_name()) == 0){
        if(first_player.get_identification_number() == second_player.get_identification_number()) throw string("You have entered the same player. Please enter another player"); 
    }
    if(first_player.stacksize() == 0 ||second_player.stacksize() == 0) throw string("Game is already over");
    first_player.set_total_games_played();
    second_player.set_total_games_played();
    Card& c1 = first_player.sTop();
    Card& c2 = second_player.sTop();
    first_player.sPop();
    second_player.sPop();
    //int strength1 = first_player.sTop().get_strength();
    int strength1 = c1.get_strength();
    //cout << "" << "strength1 = " << to_string(strength1) << endl;
    //int strength2 = second_player.sTop().get_strength();
    int strength2 = c2.get_strength();
    //cout << "" << "strength2 = " << to_string(strength2) << endl;

    //first_player.sPop();
    //second_player.sPop();

    if(strength1 == 14 && strength2 == 2){
        second_player.addWin();
        //second_player.add_card_to_cards_won(first_player.sTop(. ).to_string());
        //second_player.add_card_to_cards_won(second_player.sTop().to_string());
        second_player.add_card_to_cards_won(c1.to_string());
        second_player.add_card_to_cards_won(c2.to_string());
        //last_move.append(first_player.get_player_name() << " played " << c1.to_string() << ", " << second_player.get_player_name() << " played " + c2.to_string() << ". " << second_player.get_player_name() << " wins.\n");

        this->set_last_turn(last_move);
        this->log.append(last_move);
        return 2;
    }
    else if(strength1 == 2 && strength2 == 14){
        first_player.addWin();
        //first_player.add_card_to_cards_won(first_player.sTop().to_string());
        //first_player.add_card_to_cards_won(second_player.sTop().to_string());
        first_player.add_card_to_cards_won(c1.to_string());
        first_player.add_card_to_cards_won(c2.to_string());
        //last_move.append(first_player.get_player_name() + " played " + c1.to_string() + ", " + second_player.get_player_name() + " played " + c2.to_string() + ". " + first_player.get_player_name() + " wins.\n");

        this->set_last_turn(last_move);
        this->log.append(last_move);
        return 1;
    }
    else{
        if(strength1 > strength2){
        first_player.addWin();
        //first_player.add_card_to_cards_won(first_player.sTop().to_string());
        //first_player.add_card_to_cards_won(second_player.sTop().to_string());
        first_player.add_card_to_cards_won(c1.to_string());
        first_player.add_card_to_cards_won(c2.to_string());
        //last_move.(first_player.get_player_name() + " played " + c1.to_string() + ", " + second_player.get_player_name() + " played " + c2.to_string() + ". " + first_player.get_player_name() + " wins.\n");

        this->set_last_turn(last_move);
        this->log.append(last_move);
        return 1;
        }
        else if(strength1 < strength2){
        second_player.addWin();
        //second_player.add_card_to_cards_won(first_player.sTop(. ).to_string());
        //second_player.add_card_to_cards_won(second_player.sTop().to_string());
        second_player.add_card_to_cards_won(c1.to_string());
        second_player.add_card_to_cards_won(c2.to_string());
        //last_move.appendappend(first_player.get_player_name() + " played " + c1.to_string() + ", " + second_player.get_player_name() + " played " + c2.to_string() + ". " + second_player.get_player_name() + " wins.\n");

        this->set_last_turn(last_move);
        this->log.append(last_move);
        return 2;
        }
        else if(strength1 == strength2){
            this->number_of_draws++;
            if(first_player.stacksize() == 0 ||second_player.stacksize() == 0){
                printWiner();
            }
            else{
                //last_move.append(first_player.get_player_name() + " played " + c1.to_string() + ", " + second_player.get_player_name() + " played " + c2.to_string() + ". Draw. " );
                int winner = playTurn(last_move);
                if( winner == 1){
                    first_player.addWin();
                    //first_player.add_card_to_cards_won(first_player.sTop().to_string());
                    //first_player.add_card_to_cards_won(second_player.sTop().to_string());
                    first_player.add_card_to_cards_won(c1.to_string());
                    first_player.add_card_to_cards_won(c2.to_string());
                }
                else if( winner == 2){
                    second_player.addWin();
                    //first_player.add_card_to_cards_won(first_player.sTop().to_string());
                    //first_player.add_card_to_cards_won(second_player.sTop().to_string());
                    second_player.add_card_to_cards_won(c1.to_string());
                    second_player.add_card_to_cards_won(c2.to_string());
                }
                else return 0;
            }
        }
    }
    return 0;
}

/*
void Game::playdraw(){
    if(first_player.stacksize() == 0 ||second_player.stacksize() == 0){
        printWiner();
    }
    else{
        this->number_of_draws++;
        playTurn();
    }
}*/

void Game::printLastTurn(){
    cout << this->last_turn;
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

string Game::draw_rate(){
    int ans = (this->get_number_of_draws() * 100) / this->first_player.get_total_games_played();
    return to_string(ans);
}

void Game::printStats(){
    cout << "Players name: " << this->first_player.get_player_name() << ", win rate: " << this->first_player.get_total_wins() << "% , cards won: " << this->first_player.get_cards_won() << endl; 
    cout << "Players name: " << this->second_player.get_player_name() << ", win rate: " << this->second_player.get_total_wins() << ", cards won: " << this->second_player.get_cards_won()  << endl; 
    cout << "Draw rate:" << this->draw_rate() << "% , amount of draws that happand:" << this->get_number_of_draws() << endl;    
}

void Game::add_to_log(string){
    cout << " ";   

}


}