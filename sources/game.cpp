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

/*
// Copy constructor
Game::Game(const Game& other):
first_player(other.first_player),
second_player(other.second_player),
log(new string(*other.log)),
last_turn(new string(*other.last_turn)),
number_of_draws(other.number_of_draws){};


// Copy assignment operator
Game& Game::operator=(const Game& other) {
    if(this != &other) {
        first_player = other.first_player;
        second_player = other.second_player;
        *log = *other.log;
        *last_turn = *other.last_turn;
        number_of_draws = other.number_of_draws;
    }
    return *this;
}

// Move constructor
Game::Game(Game&& other):
    first_player(move(other.first_player)),
    second_player(move(other.second_player)),
    log(other.log),
    last_turn(other.last_turn),
    number_of_draws(other.number_of_draws){
    other.log = nullptr;
    other.last_turn = nullptr;
}

Game& Game::operator=(Game&& other) noexcept{
    if(this != &other) {
        // Release the resources held by the current object
        delete log;
        delete last_turn;
        // Move the resources from the other object to the current object
        first_player = other.first_player;
        second_player = other.second_player;
        //deck = std::move(other.deck);
        //middle_cards = std::move(other.middle_cards);
        //first_player_cards = std::move(other.first_player_cards);
        //second_player_cards = std::move(other.second_player_cards);
        number_of_draws = other.number_of_draws;
        log = other.log;
        last_turn = other.last_turn;

        // Reset the other object
        other.log = nullptr;
        other.last_turn = nullptr;
    }
    return *this;
}

Game::~Game(){
    delete this->log;
    delete this->last_turn;
}

*/

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
    //cout << "" << "strength1 = " << card_to_string(strength1) << endl;
    int strength2 = c2.get_strength();
    //cout << "" << "strength2 = " << card_to_string(strength2) << endl;
    if(strength1 == 14 && strength2 == 2){
        cout << "22222222222222222222" << endl;
        second_player.addWin();
        second_player.add_card_to_cards_won(card1);
        second_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". " + second_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        return 2;
    }
    else if(strength1 == 2 && strength2 == 14){
        cout << "3333333333333333" << endl;
        first_player.addWin();
        first_player.add_card_to_cards_won(card1);
        first_player.add_card_to_cards_won(card2);
        last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". " + first_player.get_player_name() + " wins.\n");
        appendToLastTurn(last_move);
        appendTolog(last_move);
        return 1;
    }
    else{
        cout << "44444444444444444" << endl;
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
        cout << "55555555555555555" << endl;
        second_player.addWin();
        second_player.add_card_to_cards_won(card1);
        second_player.add_card_to_cards_won(card2);
        cout << "a" << endl;
        last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". " + second_player.get_player_name() + " wins.\n");
        cout << "b" << endl;
        appendToLastTurn(last_move);
        cout << "c" << endl;
        appendTolog(last_move);
        cout << "d" << endl;
        return 2;
        }
        else if(strength1 == strength2){
            cout << "6666666666666666666" << endl;
            this->number_of_draws++;
            if(first_player.stacksize() == 0 ||second_player.stacksize() == 0){
                printWiner();
                return 3;
            }
            else{
                last_move.append(first_player.get_player_name() + " played " + c1.card_to_string() + ", " + second_player.get_player_name() + " played " + c2.card_to_string() + ". Draw." );
                int winner = playTurn(last_move);
                cout << "winner : "<< to_string(winner) << endl;
                cout << "rfgrwe4gt" << endl;
                if( winner == 1){
                    cout << "here\n" ;
                    first_player.addWin();
                    cout << " or here\n" ;
                    first_player.add_card_to_cards_won(card1);
                    first_player.add_card_to_cards_won(card2);
                    cout << "7777777777777777" << endl;
                    return 1;
                }
                else if( winner == 2){
                    cout << "here\n" ;
                    second_player.addWin();
                    cout << " or here\n" ;
                    cout << to_string(second_player.get_num_of_taken_cards()) << endl;
                    cout << c1.card_to_string() << endl;
                    second_player.add_card_to_cards_won(card1);
                    second_player.add_card_to_cards_won(card2);
                    cout << "8888888888888888" << endl;
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
    //cout << this->last_turn;
    cout << "last_turn" << endl;
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