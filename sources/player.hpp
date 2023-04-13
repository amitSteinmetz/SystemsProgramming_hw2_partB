#pragma once
#include "card.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace ariel;

class Player
{   
    /* Attributes */
    string name;
    int amount_of_winning_cards;
    int num_of_wins;  
    vector<Card> cards_deck;

    /* Ctors */
    public:
    Player(string new_name);

    /* Functions */
    int stacksize(); 
    int cardesTaken(); 
    int get_amount_of_winning_cards();
    int get_num_of_wins();
    string getName();
    void set_amount_of_winning_cards(int amount);
    void set_num_of_wins(int num);
    void add_card_to_deck(Card card);
    void popCard();
    vector<Card> getCardsDeck();
    Card getCard();
};

