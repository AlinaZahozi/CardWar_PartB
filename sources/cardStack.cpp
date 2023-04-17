#include <iostream>
#include <string>
#include <vector> //for shuffle method
#include <random> //for shuffle method
#include <algorithm> //for shuffle method
#include "card.hpp"
#include "cardStack.hpp"
using namespace std;


namespace ariel{

    // Constructor
    CardStack::CardStack(): //Boot list
    heartsACE("HEARTS","ACE"),
    heartsTWO("HEARTS","TWO"),
    heartsTHREE("HEARTS","THREE"),
    heartsFOUR("HEARTS","FOUR"),
    heartsFIVE("HEARTS","FIVE"),
    heartsSIX("HEARTS","SIX"),
    heartsSEVEN("HEARTS","SEVEN"),
    heartsEIGHT("HEARTS","EIGHT"),
    heartsNINE("HEARTS","NINE"),
    heartsTEN("HEARTS","TEN"),
    heartsJACK("HEARTS","JACK"),
    heartsQUEEN("HEARTS","QUEEN"),
    heartsKING("HEARTS","KING"),

    diamondsACE("DIAMONDS","ACE"),
    diamondsTWO("DIAMONDS","TWO"),
    diamondsTHREE("DIAMONDS","THREE"),
    diamondsFOUR("DIAMONDS","FOUR"),
    diamondsFIVE("DIAMONDS","FIVE"),
    diamondsSIX("DIAMONDS","SIX"),
    diamondsSEVEN("DIAMONDS","SEVEN"),
    diamondsEIGHT("DIAMONDS","EIGHT"),
    diamondsNINE("DIAMONDS","NINE"),
    diamondsTEN("DIAMONDS","TEN"),
    diamondsJACK("DIAMONDS","JACK"),
    diamondsQUEEN("DIAMONDS","QUEEN"),
    diamondsKING("DIAMONDS","KING"),

    clubsACE("CLUBS","ACE"),
    clubsTWO("CLUBS","TWO"),
    clubsTHREE("CLUBS","THREE"),
    clubsFOUR("CLUBS","FOUR"),
    clubsFIVE("CLUBS","FIVE"),
    clubsSIX("CLUBS","SIX"),
    clubsSEVEN("CLUBS","SEVEN"),
    clubsEIGHT("CLUBS","EIGHT"),
    clubsNINE("CLUBS","NINE"),
    clubsTEN("CLUBS","TEN"),
    clubsJACK("CLUBS","JACK"),
    clubsQUEEN("CLUBS","QUEEN"),
    clubsKING("CLUBS","KING"),

    spadesACE("SPADES","ACE"),
    spadesTWO("SPADES","TWO"),
    spadesTHREE("SPADES","THREE"),
    spadesFOUR("SPADES","FOUR"),
    spadesFIVE("SPADES","FIVE"),
    spadesSIX("SPADES","SIX"),
    spadesSEVEN("SPADES","SEVEN"),
    spadesEIGHT("SPADES","EIGHT"),
    spadesNINE("SPADES","NINE"),
    spadesTEN("SPADES","TEN"),
    spadesJACK("SPADES","JACK"),
    spadesQUEEN("SPADES","QUEEN"),
    spadesKING("SPADES","KING")
    {
       this->cards.push(heartsACE);
       this->cards.push(heartsTWO);
       this->cards.push(heartsTHREE);
       this->cards.push(heartsFOUR);
       this->cards.push(heartsFIVE);
       this->cards.push(heartsSIX);
       this->cards.push(heartsSEVEN);
       this->cards.push(heartsEIGHT);
       this->cards.push(heartsNINE);
       this->cards.push(heartsTEN);
       this->cards.push(heartsJACK);
       this->cards.push(heartsQUEEN);
       this->cards.push(heartsKING);

       this->cards.push(diamondsACE);
       this->cards.push(diamondsTWO);
       this->cards.push(diamondsTHREE);
       this->cards.push(diamondsFOUR);
       this->cards.push(diamondsFIVE);
       this->cards.push(diamondsSIX);
       this->cards.push(diamondsSEVEN);
       this->cards.push(diamondsEIGHT);
       this->cards.push(diamondsNINE);
       this->cards.push(diamondsTEN);
       this->cards.push(diamondsJACK);
       this->cards.push(diamondsQUEEN);
       this->cards.push(diamondsKING);

       this->cards.push(clubsACE);
       this->cards.push(clubsTWO);
       this->cards.push(clubsTHREE);
       this->cards.push(clubsFOUR);
       this->cards.push(clubsFIVE);
       this->cards.push(clubsSIX);
       this->cards.push(clubsSEVEN);
       this->cards.push(clubsEIGHT);
       this->cards.push(clubsNINE);
       this->cards.push(clubsTEN);
       this->cards.push(clubsJACK);
       this->cards.push(clubsQUEEN);
       this->cards.push(clubsKING);

       this->cards.push(spadesACE);
       this->cards.push(spadesTWO);
       this->cards.push(spadesTHREE);
       this->cards.push(spadesFOUR);
       this->cards.push(spadesFIVE);
       this->cards.push(spadesSIX);
       this->cards.push(spadesSEVEN);
       this->cards.push(spadesEIGHT);
       this->cards.push(spadesNINE);
       this->cards.push(spadesTEN);
       this->cards.push(spadesJACK);
       this->cards.push(spadesQUEEN);
       this->cards.push(spadesKING);
    }

    //Shuffles the cards independently and randomly
    void CardStack::shuffle(){
        vector <Card> cards_vec;
        while(!(this->cards.empty())){
            cards_vec.push_back(this->cards.top()); //adding the top card of cards to a cards_vec.
            this->cards.pop();
        } 
        mt19937 rng(random_device{}()); // Initializing a pseudorandom number.
        std::shuffle(cards_vec.begin(), cards_vec.end(), rng); //Shuffle a cards_vec using the pseudorandom number and shuffle algorithm.
        for (const auto& card : cards_vec) {
            this->cards.push(card); //Pushing the cards back to the cards stack.
        }
    }
}