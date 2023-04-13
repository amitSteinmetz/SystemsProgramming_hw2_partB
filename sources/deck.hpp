#pragma once
#include "card.hpp"
#include <cstdlib>
#include <vector>

class Deck
{
    /* Attributes */
    std::vector<ariel::Card> deck;
    int size;

    /* Ctors */
    public:
    Deck();

    /* Functions: */
    void shuffle();
    ariel::Card dealCard();
};