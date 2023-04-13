#include "card.hpp"
#include <string>
using namespace ariel;

Card::Card(Type type, Value value)
{
    this->type = type;
    this->value = value;
}

std::string Card::toString()
{
    std::string val_str;
    switch (value) {
        case ACE: val_str = "Ace"; break;
        case TWO: val_str  = "2"; break;
        case THREE: val_str  = "3"; break;
        case FOUR: val_str  = "4"; break;
        case FIVE: val_str  = "5"; break;
        case SIX: val_str  = "6"; break;
        case SEVEN: val_str  = "7"; break;
        case EIGHT: val_str  = "8"; break;
        case NINE: val_str  = "9"; break;
        case TEN: val_str  = "10"; break;
        case JACK: val_str  = "Jack"; break;
        case QUEEN: val_str  = "Queen"; break;
        case KING: val_str  = "King"; break;
    }
    std::string type_str;
    switch (type) {
        case CLUBS: type_str = "Clubs"; break;
        case DIAMONDS: type_str = "Diamonds"; break;
        case HEARTS: type_str = "Hearts"; break;
        case SPADES: type_str= "Spades"; break;
    }
    return val_str + " of " + type_str;
}

int Card::getValue()
{
    return value;
}
