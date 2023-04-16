#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <random>
#include <algorithm>
#include "card.hpp"
using namespace std;

namespace ariel{

    class CardStack {
    public: 
        stack<Card> cards;  

        Card heartsACE;
        Card heartsTWO;
        Card heartsTHREE;
        Card heartsFOUR;
        Card heartsFIVE;
        Card heartsSIX;
        Card heartsSEVEN;
        Card heartsEIGHT;
        Card heartsNINE;
        Card heartsTEN;
        Card heartsJACK;
        Card heartsQUEEN;
        Card heartsKING;

        Card diamondsACE;
        Card diamondsTWO;
        Card diamondsTHREE;
        Card diamondsFOUR;
        Card diamondsFIVE;
        Card diamondsSIX;
        Card diamondsSEVEN;
        Card diamondsEIGHT;
        Card diamondsNINE;
        Card diamondsTEN;
        Card diamondsJACK;
        Card diamondsQUEEN;
        Card diamondsKING;

        Card clubsACE;
        Card clubsTWO;
        Card clubsTHREE;
        Card clubsFOUR;
        Card clubsFIVE;
        Card clubsSIX;
        Card clubsSEVEN;
        Card clubsEIGHT;
        Card clubsNINE;
        Card clubsTEN;
        Card clubsJACK;
        Card clubsQUEEN;
        Card clubsKING;

        Card spadesACE;
        Card spadesTWO;
        Card spadesTHREE;
        Card spadesFOUR;
        Card spadesFIVE;
        Card spadesSIX;
        Card spadesSEVEN;
        Card spadesEIGHT;
        Card spadesNINE;
        Card spadesTEN;
        Card spadesJACK;
        Card spadesQUEEN;
        Card spadesKING;

        // Constructor
        CardStack();

        void shuffle();
    };

}