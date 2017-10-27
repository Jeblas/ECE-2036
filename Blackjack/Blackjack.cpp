#include "Blackjack.h"
#include <iostream>

Hit_or_Stand Blackjack::queryPlayer()
{
    while(1)
    {
        std::string userInput;
        std::cout << "What whould you like to do? Enter (h)it or (s)tand: ";
        std::cin >> userInput;
        
        if (userInput == "h")
        {
            return HIT;
        } else if (userInput == "s" ) {
            return STAND;
        } else {
            std::cout << "Not a valid input." << std::endl;
        }
    }
}

double Blackjack::play(double bet)
{
    // playerBet += bet
    playerBet = bet;

    // Deal initial cards
    ++playerHand;
    ++playerHand;
    ++dealerHand;
    ++dealerHand;

    //show initial cards
    std::cout << "Dealer's first card is: ";
    dealerHand.printFirstCard();
    std::cout << "Player's Hand is: ";
    playerHand.printHand();

    // Check for Blackjack
    if (playerHand == 21 && !(dealerHand == 21))
    {
        std::cout << "Player has blackjack! Player wins!"<< std::endl;
        playerMoney += playerBet * 1.5;
        std::cout << "Player has " << playerMoney << " dollars" << std::endl;
        playerBet = 0;
        return playerMoney;
    }

    playerChoice = queryPlayer();
    while (playerChoice == HIT && playerHand < 21)
    {
        ++playerHand;
        std::cout << "Player's Hand is: ";
        playerHand.printHand();
        playerChoice = queryPlayer();
    }

    // show dealerHand
    std::cout << "Dealer's hand is: ";
    dealerHand.printHand();

    while (dealerHand < 17)
    {
        ++dealerHand;
        std::cout << "Dealer's hand is: ";
        dealerHand.printHand();

    }

    // Find outcome
    //blackjack
    if (playerHand == 21)
    {
        if(dealerHand == 21)
        {
            //tie and push
            std::cout << "Player and dealer have blackjack. Bet is pushed." << std::endl;
            std::cout << "Player has " << playerMoney << " dollars" << std::endl;
            playerBet = 0;
            return playerMoney;
        } else {
            std::cout << "Player has blackjack! Player wins!" << std::endl;
            playerMoney += playerBet * 1.5;
            std::cout << "Player has " << playerMoney << " dollars" << std::endl;
            playerBet = 0;
            return playerMoney;
        }

    }

    if (playerHand > 21)
    {

        std::cout << "Player's hand is bust."<< std::endl;
        playerMoney -= bet;
        std::cout << "Player has " << playerMoney << " dollars" << std::endl;
        playerBet = 0;
        return playerMoney;
    }

    if (dealerHand > 21)
    {
        std::cout << "Dealers's hand is bust. Player wins!" << std::endl;
        playerMoney += bet;
        std::cout << "Player has " << playerMoney << " dollars" << std::endl;
        playerBet = 0;
        return playerMoney;
    }

    if (playerHand < dealerHand)
    {
        std::cout << "Dealer wins." << std::endl;
        playerMoney -= bet;
        std::cout << "Player has " << playerMoney << " dollars" << std::endl;
        playerBet = 0;
        return playerMoney;
    }

    if (playerHand > dealerHand)
    {
        std::cout << "Player wins!" << std::endl;
        playerMoney += bet;
        std::cout << "Player has " << playerMoney << " dollars" << std::endl;
        playerBet = 0;
        return playerMoney;
    }

    if (playerHand == dealerHand)
    {
        // tie game pushes
        std::cout << "Player and dealer have equal hands. Bet is pushed." << std::endl;
        std::cout << "Player has " << playerMoney << " dollars" << std::endl;
        playerBet = 0;
        return playerMoney;
    } else {
        return playerMoney;
    }
}
