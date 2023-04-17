#include <iostream>
#include <string>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "cardStack.hpp"
using namespace std;


namespace ariel{

// Constructor
Game::Game(Player& p1 ,Player& p2): //Boot list
    first_player(p1),
    second_player(p2){
    if(p1.get_is_availible() == true){ // Check if first player is availible to play
        if(p2.get_is_availible() == true){ // Check if second player is availible to play
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

//Divides the cards between the 2 players - 26 cards for each
void Game::dividecards(){
    for(int i = 26; i > 0 ; i--){
        first_player.sPush(cardsToDivide.cards.top());
        cardsToDivide.cards.pop();
        second_player.sPush(cardsToDivide.cards.top());
        cardsToDivide.cards.pop();
    }
}

// Get first player
Player Game::get_first_player(){
    return this->first_player;
}

// Get second player
Player Game::get_second_player(){
    return this->second_player;
}

// Get the number of draws so far
int Game::get_number_of_draws(){
    return this->number_of_draws;
}

// Get log - game history
string Game::get_log(){
    return this->log;
}

// Get last turn - last turn history          
string Game::get_last_turn(){
    return this->last_turn;
}

// Set last turn
void Game::set_last_turn(const string& move){
    this->last_turn = move;
}

//Play a turn in the game
void Game::playTurn(){
    set_last_turn("");
    if(set_winner) throw string("Game is already over!\n");
    int flag = this->playTurn("\n");
    if(flag == 0) throw string("Error");
    printLastTurn();
    cout << "=========================================================================================================================================\n";
}

//Play a turn in the game and reterns an flag output
int Game::playTurn(string move){
    try{
        string last_move = move;

        if(first_player.get_player_name().compare(second_player.get_player_name()) == 0){ //Checks that the same player has not been entered by mistake
            if(first_player.get_identification_number() == second_player.get_identification_number()) throw string("You have entered the same player. Please try again with another player!\n"); 
        }

        if(set_winner) return 3; // Checks if there is already a winner

        first_player.set_total_games_played(); //move++
        second_player.set_total_games_played(); //move++

        Card& c1 = first_player.sTop(); //Get the top card
        Card& c2 = second_player.sTop(); //Get the top card

        string card1 = c1.card_to_string(); //Card to sttring
        string card2 = c2.card_to_string(); //Card to sttring

        first_player.sPop(); //Remove the top card from the deck of cards
        second_player.sPop(); //Remove the top card from the deck of cards

        int strength1 = c1.get_strength(); //Checks the value of the card
        int strength2 = c2.get_strength(); //Checks the value of the card

        if(strength1 == 14 && strength2 == 2){ //if first card is ACE and second card is TWO - player 2 wins the turn

            second_player.addWin(2); //Add win to player 2
            second_player.add_card_to_cards_won(card1); //Add first card to cards_won log
            second_player.add_card_to_cards_won(card2); //Add second card to cards_won log

            last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + second_player.get_player_name() + " wins.\n");
            appendToLastTurn(last_move); //Append last turn to last turn log
            appendTolog(last_move); //Append last turn to game log

            if(first_player.stacksize() == 0) this->set_winner = true; //Set winner if there no more cards
            return 2; //return flag - mean that player 2 wins.
        }
        else if(strength1 == 2 && strength2 == 14){ //if first card is TWO and second card is ACE - player 1 wins the turn

            first_player.addWin(2); //Add win to player 1
            first_player.add_card_to_cards_won(card1); //Add first card to cards_won log
            first_player.add_card_to_cards_won(card2); //Add second card to cards_won log

            last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + first_player.get_player_name() + " wins.\n");
            appendToLastTurn(last_move); //Append last turn to last turn log
            appendTolog(last_move); //Append last turn to game log

            if(first_player.stacksize() == 0) this->set_winner = true; //Set winner if there no more cards
            return 1; //return flag - mean that player 1 wins.
        }
        else{
            if(strength1 > strength2){ //If the value of the first card is bigger then the value of the second card

            first_player.addWin(2); //Add win to player 1
            first_player.add_card_to_cards_won(card1); //Add first card to cards_won log
            first_player.add_card_to_cards_won(card2); //Add second card to cards_won log

            last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + first_player.get_player_name() + " wins.\n");
            appendToLastTurn(last_move); //Append last turn to last turn log
            appendTolog(last_move); //Append last turn to game log

            if(first_player.stacksize() == 0) this->set_winner = true; //Set winner if there no more cards
            return 1; //return flag - mean that player 1 wins.
            }
            else if(strength1 < strength2){ //If the value of the first card is smaller then the value of the second card

            second_player.addWin(2); //Add win to player 2
            second_player.add_card_to_cards_won(card1); //Add first card to cards_won log
            second_player.add_card_to_cards_won(card2); //Add second card to cards_won log

            last_move.append(first_player.get_player_name() + " played " + card1 + ", " + second_player.get_player_name() + " played " + card2 + ". " + second_player.get_player_name() + " wins.\n");
            appendToLastTurn(last_move); //Append last turn to last turn log
            appendTolog(last_move); //Append last turn to game log

            if(first_player.stacksize() == 0) this->set_winner = true; //Set winner if there no more cards
            return 2; //return flag - mean that player 2 wins.
            }
            else if(strength1 == strength2){ // If the value of the first card is equal to the value of the second card
                this->number_of_draws++; //draw++
                if(first_player.stacksize() == 0){ //Set winner if there no more cards
                    this->set_winner = true;
                    return 3; //return flag - mean that its a draw.
                }
                else{
                    last_move.append(first_player.get_player_name() + " played " + card1+ ", " + second_player.get_player_name() + " played " + card2 + ". Draw. " );
                    Card& face_down1 = first_player.sTop(); //Get the top card
                    Card& face_down2 = second_player.sTop(); //Get the top card
                    string card_dowm1 = face_down1.card_to_string(); //Card to sttring
                    string card_down2 = face_down2.card_to_string(); //Card to sttring
                    first_player.sPop(); //Remove the top card from the deck of cards
                    second_player.sPop(); //Remove the top card from the deck of cards
                    int winner = playTurn(last_move); //play turn

                    if( winner == 1){ // if first player win
                        first_player.addWin(4); //Add win to player 1
                        first_player.add_card_to_cards_won(card_dowm1); //Add first face down card to cards_won log
                        first_player.add_card_to_cards_won(card_down2); //Add second face down card to cards_won log
                        first_player.add_card_to_cards_won(card1); //Add first card to cards_won log
                        first_player.add_card_to_cards_won(card2); //Add second card to cards_won log
                        if(first_player.stacksize() == 0) this->set_winner = true; //Set winner if there no more cards
                        return 1; //return flag - mean that player 1 wins.
                    }
                    else if( winner == 2){ // if second player win
                        second_player.addWin(4); //Add win to player 2
                        second_player.add_card_to_cards_won(card_dowm1); //Add first face down card to cards_won log
                        second_player.add_card_to_cards_won(card_down2); //Add second face down card to cards_won log
                        second_player.add_card_to_cards_won(card1); //Add first card to cards_won log
                        second_player.add_card_to_cards_won(card2); //Add second card to cards_won log
                        if(first_player.stacksize() == 0) this->set_winner = true; //Set winner if there no more cards
                        return 2; //return flag - mean that player 2 wins.
                    }
                    else return 3; //return flag - mean that its a draw again.
                }
            }
        }
    }catch(string message){
        cout << "Error: " << message << endl;
    } return 0;
}

//Prints the last turn game history
void Game::printLastTurn(){
    if(this->last_turn.compare("") != 0) { //Dont print it if its empty
        cout << "Move #" + to_string(this->first_player.get_total_games_played()) + "  " +this->last_turn + "\n";
    }
    if(set_winner && this->print_winner == false){ //if the game is over
        cout << "=========================================================================================================================================\n";
        printWiner();
        this->print_winner = true;
    }
}

//Runs turns in the game until there is a winner
void Game::playAll(){
    if(this->set_winner) cout << "Game is already over!\n";
    else{
        bool flag = false; //flag to stop playing
        for (int i = 26; flag == false && i > 0 ;i--) {
            playTurn();
            if(this->set_winner){
                flag = true;
            }
        }
    }
}

//Prints the winner at the end of the game
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

//Prints the game history so far
void Game::printLog(){
    cout << "Game history: \n";
   cout << get_log();
}

//Calculates the draw rate and displays as a string
string Game::draw_rate(){
    int ans = (this->get_number_of_draws() * 100) / this->first_player.get_total_games_played();
    return to_string(ans);
}

//Prints basic statistics for each player 
void Game::printStats(){
    cout << "\nPlayers state:\n\nPlayer #1 - name: " << this->first_player.get_player_name() << ", win rate: " << this->first_player.get_total_wins() << "% , cards won: " << this->first_player.get_cards_won() << "." << endl; 
    cout << "Player #2 - name: " << this->second_player.get_player_name() << ", win rate: " << this->second_player.get_total_wins() << "% , cards won: " << this->second_player.get_cards_won() << "." << endl; 
    cout << "Draw rate:" << this->draw_rate() << "% , amount of draws that happand:" << this->get_number_of_draws() << ".\n\n";    
}

//Append the last turn to game history log
void Game::appendTolog(const string& appendString){
    this->log.append(appendString);
}

//Append the last turn to last turn game history
void Game::appendToLastTurn(const string& appendString){
    this->last_turn.append(appendString);
}

}