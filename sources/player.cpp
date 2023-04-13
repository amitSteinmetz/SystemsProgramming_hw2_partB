#include "player.hpp"
#include "card.hpp"
using namespace ariel;

Player::Player(string new_name) {
    name = new_name;
    cards_deck = {};
    amount_of_winning_cards = 0;  
    num_of_wins = 0;
}

int Player::stacksize()
{
    return cards_deck.size();
}

int Player::cardesTaken()
{
    return amount_of_winning_cards;
}

string Player::getName() 
{
    return name;
}

vector<Card> Player::getCardsDeck()
{
    return cards_deck;
}

Card Player::getCard()
{
    return cards_deck.back();
}

void Player::popCard()
{
    cards_deck.pop_back();
}

void Player::add_card_to_deck(Card card)
{
    cards_deck.push_back(card);
}

int Player::get_amount_of_winning_cards()
{
    return amount_of_winning_cards;
}

int Player::get_num_of_wins()
{
    return num_of_wins;
}

void Player::set_amount_of_winning_cards(int amount)
{
  amount_of_winning_cards = amount;
}

void Player::set_num_of_wins(int num)
{
    num_of_wins = num;
}

