#include "deck.hpp"
#include "card.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace ariel;

Deck::Deck()
{     
    // Push into the deck 52 cards, 13 cards from every type
    for (int type_num = Type::CLUBS; type_num <= Type::SPADES; ++type_num) {
        for (int val_num = Value::ACE; val_num <= Value::KING; ++val_num) {
            deck.push_back(ariel::Card(static_cast<Type>(type_num), static_cast<Value>(val_num)));
        }
    }
    size = 52;
}

void Deck::shuffle()
{
    // shuffle the vector using std::shuffle  - this implementaion based on chatGPT. 
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

ariel::Card Deck::dealCard()
{
    // Take a card from the deck that represented by vector. 
    ariel::Card one_card = deck.back();
    // This is actually remove the card from the deck.
    deck.pop_back();

    return one_card;
}

