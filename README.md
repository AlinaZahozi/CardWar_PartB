# HW2-2023---CardWar---Part B

![image](https://user-images.githubusercontent.com/93255163/228441584-40837ede-7f09-4b26-8802-d7a2bc079c03.png)

**Introduction:**

In this assignment we will implement card game War for two players and test it by using doctest (testing framework for unit tests).

**Game rules:**

There is a normal deck of cards with 52 cards at the beginning of the game the deck is shuffled (randomly) and divided equally between the two players. On each turn the players draw one card from the top of their pile and the player with the highest card takes both cards to him (2 Ace wins). If the players have drawn two identical cards then they place one card face down and a lesser card on top of it. The high card player takes all six cards. If there is a tie again, continue with a closed card followed by an open card until one of the players wins. The turn continues until one of the players takes the pot or runs out of cards. If you run out of cards while breaking a tie, each player takes the cards he threw (divide the pot half and half). The game continues until the players run out of cards and the winner is the player who took the most cards.

In order to write the tests in this part of the assignment, I used several websites, below are the links:
1.https://blog.jetbrains.com/rscpp/2019/07/10/better-ways-testing-with-doctest/

2. https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md

And of course also the examples explained in the lecture
