#pragma once
#include <string>

using namespace std;

namespace ariel
{
    enum Type {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };

    enum Value {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    class Card
    {
        /* Attributes */
        Type type;
        Value value;

        /* Ctors */
        public:
        Card(Type type, Value value);

        /* Functions */
        string toString();
        int getValue();
    };
}