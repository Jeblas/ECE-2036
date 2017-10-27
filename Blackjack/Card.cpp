#include "Card.h"
#include <stdlib.h>
#include <time.h>

const std::string types[] = {"Ace", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card()
{
    //srand(time());
    int temp = rand() % 13;

    typeString = types[temp];

    if (temp == 0)
    {
        initial_value = 11;
    } else if (temp > 9)
    {
        initial_value = 10;
    } else {
        initial_value = temp + 1;
    }
}

std::string Card::getType() const
{
    return typeString;
}

int Card::getValue() const
{
    return initial_value;
}
