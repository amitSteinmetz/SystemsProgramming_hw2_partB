#pragma once
#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"

class Game
{
    /* Attributes */
    Player *p1;
    Player *p2;
    Deck start_deck;
    vector<string> turns;
    int num_of_draws;
    // In order to calculate accurate the draw rate, we count all moves (can be more moves than turns) 
    int moves;
    
    /* Ctors*/
    public:
    Game(Player &new_player1, Player &new_player2);

    /* Functions */
    void playTurn();
    void printLastTurn();
    void playAll(); 
    void printWiner();
    void printLog();
    void printStats(); 
};
