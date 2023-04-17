# HW2-2023---CardWar---Part B

![image](https://user-images.githubusercontent.com/93255163/228441584-40837ede-7f09-4b26-8802-d7a2bc079c03.png)

**Introduction:**

In this assignment we will implement card game War for two players and test it by using doctest (testing framework for unit tests).

**Game rules:**

* There is a normal deck of cards with 52 cards at the beginning of the game the deck is shuffled (randomly) and divided equally between the two players.
* On each turn the players draw one card from the top of their pile and the player with the highest card takes both cards to him (2 Ace wins).
* If the players have drawn two identical cards then they place one card face down and a lesser card on top of it.
* The high card player takes all six cards.
* If there is a tie again, continue with a closed card followed by an open card until one of the players wins. 
* The turn continues until one of the players takes the pot or runs out of cards.
* If you run out of cards while breaking a tie, each player takes the cards he threw (divide the pot half and half).
* The game continues until the players run out of cards and the winner is the player who took the most cards.

**In order to fulfill the assignment, I used sources of information on the Internet which can be seen in the following links:**

*Shuffle algorithm: https://en.cppreference.com/w/cpp/algorithm/random_shuffle

*Random device: https://en.cppreference.com/w/cpp/numeric/random/random_device

*Mersenne Twister algorithm: https://en.wikipedia.org/wiki/Mersenne_Twister

*std::mt19937 class: https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine

*C++ Reference: https://en.cppreference.com/w/

*Stack Overflow: https://stackoverflow.com/

*GeeksforGeeks: https://www.geeksforgeeks.org/

*Topcoder: https://www.topcoder.com/
