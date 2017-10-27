#include "Hand.h"

Hand::Hand(std::string tHand_Holder)
    : hand_holder(tHand_Holder), number_of_cards(0), number_of_aces(0),
    value(0)
{
    //cards = new Card*[10];
}

// Deconstructor
// TODO implement
Hand::~Hand()
{
    for (int i = 0; i < number_of_cards; i++)
      delete cards[i];
    //delete *this;
}

Hand & Hand::operator++()
{
    if (number_of_cards < 11)
    {
        cards[number_of_cards] = new Card();
        if (cards[number_of_cards]->getValue() == 11)
        {
            ++number_of_aces;
        }
        ++number_of_cards;
        updateValue();
    }

    return *this;
}

void Hand::updateValue()
{
    value = 0;

    // Value with non Aces
    for (int i = 0; i < number_of_cards; i++)
    {
        // Exclude Aces
        if (cards[i]->getValue() != 11)
        {
            value += cards[i]->getValue();
        }
    }

    // Value with Aces that performs optimal value calculation
    for (int i = 0; i < number_of_aces; i++)
    {
        if ( value + 11 + (number_of_aces - 1 - i) <= 21)
        {
            value += 11;
        } else {
            ++value;
        }
    }

}

void Hand::printHand()
{
    for (int i = 0; i < number_of_cards; i++)
    {
        std::cout << cards[i]->getType() << " ";
    }
    std::cout << "\n" << hand_holder << " hand value is  " << value << std::endl;

}

void Hand::printFirstCard()
{
    std::cout << cards[0]->getType() << std::endl;
}

// TODO implement overloaded operators
bool Hand::operator>(const Hand & rhs) const
{
    if (value > rhs.value)
        return true;
    return false;
}

bool Hand::operator>(int rhs) const
{
    if(value > rhs)
        return true;
    return false;
}

bool Hand::operator<(const Hand & rhs) const
{
    if (value < rhs.value)
        return true;
    return false;
}

bool Hand::operator<(int rhs) const
{
    if (value < rhs)
        return true;
    return false;
}

bool Hand::operator==(const Hand & rhs) const
{
    if (value == rhs.value)
        return true;
    return false;
}

bool Hand::operator==(int rhs) const
{
    if (value == rhs)
        return true;
    return false;
}
