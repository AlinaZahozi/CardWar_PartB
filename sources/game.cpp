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
            this->set_winner = false;
            this->print_winner = false;
            this->number_of_draws = 0;
            cardsToDivide.shuffle();
            dividecards();
            cout << endl << "The game has started...\n" ;
            cout << "Players: " << first_player.get_player_name() << " Vs. " << second_player.get_player_name() << "\n\n";
        }
        else{
            cout << p2.get_player_name() << "is not availible to play";
        }
    }
    else{
        cout << p1.get_player_name() << "is not availible to play";
    }
}


void Game::dividecards(){
    for(int i = 26; i > 0 ; i--){
        first_player.sPush(cardsToDivide.cards.top());
        cardsToDivide.cards.pop();
        second_player.sPush(cardsToDivide.cards.top());
        cardsToDivide.cards.pop();
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
    //if(!(this->set_winner)){
    if(set_winner) throw string("Game is already over!\n");
    int flag = this->playTurn("\n");
    if(flag == 0) throw string("Error");
    printLastTurn();
    cout << "=========================================================================================================================================\n";
}

// Methods
int Game::playTurn(string move){
    //cout << "p1.stacksize():" << to_string(this->first_player.stacksize()) << "  p1.cardesTaken():" << to_string(this->first_player.cardesTaken()) << "  p2.stacksize():" << to_string(this->second_player.stacksize()) << "  p2.cardesTaken():" << to_string(this->second_player.cardesTaken()) << endl;
    try{
    string last_move = move;
    if(first_player.get_player_name().compare(second_player.get_player_name()) == 0){
        if(first_player.get_identification_number() == second_player.get_identification_number()) throw string("You have entered the same player. Please try again with another player!\n"); 
    }
    if(first_player.get_total_games_played() == 26) throw string("Game is already over!\n");
    if(set_winner) return 1;
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
        second_player.addWin(2);
        second_player.add_card_to_cards_won(card1);
        second_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + second_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        if(first_player.stacksize() == 0 || second_player.stacksize() == 0) this->set_winner = true;
        return 2;
    }
    else if(strength1 == 2 && strength2 == 14){
        first_player.addWin(2);
        first_player.add_card_to_cards_won(card1);
        first_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + first_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        if(first_player.stacksize() == 0 || second_player.stacksize() == 0) this->set_winner = true;
        return 1;
    }
    else{
        if(strength1 > strength2){
        first_player.addWin(2);
        first_player.add_card_to_cards_won(card1);
        first_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + first_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        if(first_player.stacksize() == 0 || second_player.stacksize() == 0) this->set_winner = true;
        return 1;
        }
        else if(strength1 < strength2){
        second_player.addWin(2);
        second_player.add_card_to_cards_won(card1);
        second_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + second_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        if(first_player.stacksize() == 0 || second_player.stacksize() == 0) this->set_winner = true;
        return 2;
        }
        else if(strength1 == strength2){
            this->number_of_draws++;
            if(first_player.stacksize() == 0 || second_player.stacksize() == 0){
                this->set_winner = true;
                return 1;
            }
            else{
                last_move.append(first_player.get_player_name() + " played " + card1+ ", " + second_player.get_player_name() + " played " + card2 + ". Draw. " );
                    Card& face_down1 = first_player.sTop();
                    Card& face_down2 = second_player.sTop();
                    string card_dowm1 = face_down1.card_to_string();
                    string card_down2 = face_down2.card_to_string();
                    first_player.sPop();
                    second_player.sPop();
                int winner = playTurn(last_move);
                if( winner == 1){
                    first_player.addWin(4);
                    first_player.add_card_to_cards_won(card_dowm1);
                    first_player.add_card_to_cards_won(card_down2);
                    first_player.add_card_to_cards_won(card1);
                    first_player.add_card_to_cards_won(card2);
                    if(first_player.stacksize() == 0 || second_player.stacksize() == 0) this->set_winner = true;
                    return 1;
                }
                else if( winner == 2){
                    second_player.addWin(4);
                    second_player.add_card_to_cards_won(card_dowm1);
                    second_player.add_card_to_cards_won(card_down2);
                    second_player.add_card_to_cards_won(card1);
                    second_player.add_card_to_cards_won(card2);
                    if(first_player.stacksize() == 0 || second_player.stacksize() == 0) this->set_winner = true;
                    return 2;
                }
                else return 0;
            }
        }
    }
    }catch(string message){
        cout << "Error: " << message << endl;
    }
    return 0;
}

void Game::printLastTurn(){
    if(this->last_turn.compare("") != 0) {
        cout << "Move #" + to_string(this->first_player.get_total_games_played()) + "  " +this->last_turn + "\n";
    }
    if(set_winner && this->print_winner == false){
        cout << "=========================================================================================================================================\n";
        printWiner();
        this->print_winner = true;
    }
}

void Game::playAll(){
    if(this->set_winner) cout << "Game is already over!\n";
    bool flag = false;
    for (int i = 26; flag == false && i > 0 ;i--) {
        if(this->set_winner){
            flag = true;
        }
        else{
            playTurn();
        }
    }
}

/*
void Game::printWiner(int winner){
    if(winner == 1){
        cout << "GAME OVER - " << first_player.get_player_name() << " Wins!" << endl;
    }
    else{
        cout << "GAME OVER - " << second_player.get_player_name() << " Wins!"<< endl; 
    }
    cout << "=========================================================================================================================================\n";
    first_player.set_is_availible(true);
    second_player.set_is_availible(true);
}*/

void Game::printWiner(){
    if(first_player.get_num_of_taken_cards() == second_player.get_num_of_taken_cards()){
        cout << "GAME OVER - Congratulations its a draw!" << endl; 
    }
    else if(first_player.get_num_of_taken_cards() > second_player.get_num_of_taken_cards()){
        cout << "GAME OVER - " << first_player.get_player_name() << " Wins!" << endl;
    }
    else{
        cout << "GAME OVER - " << second_player.get_player_name() << " Wins!"<< endl; 
    }
    cout << "=========================================================================================================================================\n";
    first_player.set_is_availible(true);
    second_player.set_is_availible(true);
}


void Game::printLog(){
    cout << "Game history: \n";
   cout << get_log();
}

string Game::draw_rate(){
    int ans = (this->get_number_of_draws() * 100) / this->first_player.get_total_games_played();
    return to_string(ans);
}

void Game::printStats(){
    cout << "\nPlayers state:\n\nPlayer #1 - name: " << this->first_player.get_player_name() << ", win rate: " << this->first_player.get_total_wins() << "% , cards won: " << this->first_player.get_cards_won() << "." << endl; 
    cout << "Player #2 - name: " << this->second_player.get_player_name() << ", win rate: " << this->second_player.get_total_wins() << ", cards won: " << this->second_player.get_cards_won() << "." << endl; 
    cout << "Draw rate:" << this->draw_rate() << "% , amount of draws that happand:" << this->get_number_of_draws() << ".\n\n";    
}

void Game::appendTolog(const string& appendString){
    this->log.append(appendString);
}

void Game::appendToLastTurn(const string& appendString){
    this->last_turn.append(appendString);

}

}