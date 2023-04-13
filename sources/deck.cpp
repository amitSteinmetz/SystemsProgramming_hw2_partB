#include "deck.hpp"
#include "card.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace ariel;

Deck::Deck()
{     
    int i = 0;
    for (int type_num = Type::CLUBS; type_num <= Type::SPADES; ++type_num) {
        for (int val_num = Value::ACE; val_num <= Value::KING; ++val_num) {
            deck.push_back(ariel::Card(static_cast<Type>(type_num), static_cast<Value>(val_num)));
        }
    }
    size = 52;
}

void Deck::shuffle()
{
    // shuffle the vector using std::shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

ariel::Card Deck::dealCard()
{
    ariel::Card one_card = deck.back();
    deck.pop_back();

    return one_card;
}

