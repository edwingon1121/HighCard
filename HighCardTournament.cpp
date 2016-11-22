//  Edwin Gonzalez
//  ITP 165, Spring 2016
//  Homework 07
//  edwingon@usc.edu
//
//  hw07.cpp
//  hw07
//
//  Created by Edwin Gonzalez on 3/5/16.
//  Copyright © 2016 Edwin Gonzalez. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Card
{
    int cardRank=2;
    std::string cardSuits;
};

//Function: cardToString
//Purpose: To convert struct solely into a string.
//Parameters: A type Card which holds a int and a string.
//Returns: A string containing the number and type of suit

std::string cardToString (Card& hand)
{
    std::string retValue;
    if (hand.cardRank==2)
    {
        retValue= "2 of " + hand.cardSuits;
    }
    else if (hand.cardRank==3)
    {
        retValue= "3 of " + hand.cardSuits;
    }
    else if (hand.cardRank==4)
    {
        retValue= "4 of " + hand.cardSuits;
    }
    else if (hand.cardRank==5)
    {
        retValue= "5 of " + hand.cardSuits;
    }
    else if (hand.cardRank==6)
    {
        retValue= "6 of " + hand.cardSuits;
    }
    else if (hand.cardRank==7)
    {
        retValue= "7 of " + hand.cardSuits;
    }
    else if (hand.cardRank==8)
    {
        retValue= "8 of " + hand.cardSuits;
    }
    else if (hand.cardRank==9)
    {
        retValue= "9 of " + hand.cardSuits;
    }
    else if (hand.cardRank==10)
    {
        retValue= "10 of " + hand.cardSuits;
    }
    else if (hand.cardRank==11)
    {
        retValue= "Jack of " + hand.cardSuits;
    }
    else if (hand.cardRank==12)
    {
        retValue= "Queen of " + hand.cardSuits;
    }
    else if (hand.cardRank==13)
    {
        retValue= "King of " + hand.cardSuits;
    }
    else if (hand.cardRank==14)
    {
        retValue= "Ace of " + hand.cardSuits;
    }
    
    return retValue;
}

//Function: makeCard
//Purpose: Creates a variable of type card
//Parameters:Takes in an int and string
//Returns: A card with a suit and rank.
Card makeCard (int rank, std::string suit)
{
    Card finalCard;
    finalCard.cardRank=rank;
    finalCard.cardSuits=suit;
    
    return finalCard;
}

//Function: cardToString
//Purpose: Makes a rank with the range of 2-14
//Parameters: None
//Returns:A randomized rank between 2-14.
int getRandRank ()
{
    return std::rand() % 13 + 2;
}

//Function: getRandSuit
//Purpose: Creates a randomized suit
//Parameters: None
//Returns: A randomized suit
std::string getRandSuit ()
{
    int randsuit=0;
    randsuit=rand() %4;
    std::string suit;
    
    if (randsuit==0)
    {
        suit="Hearts";
    }
    else if (randsuit==1)
    {
        suit="Diamonds";
    }
    else if (randsuit==2)
    {
        suit="Clubs";
    }
    else if (randsuit==3)
    {
        suit="Spades";
    }

    return suit;
}

//Function: isEqual
//Purpose:To check if player's 1 cards is equal to player's 2 card
//Parameters:Both player's card
//Returns: A boolean value
bool isEqual(Card card1, Card card2)
{
    bool same=false;
    if (card1.cardRank==card2.cardRank)
    {
        same=true;
    }
    return same;
}

//Function: isGreater
//Purpose:To check if player's 1 card is greater than player's 2 card
//Parameters:Both players' card
//Returns: A boolean value
bool isGreater(Card card1, Card card2)
{
    bool same=false;
    if (card1.cardRank>card2.cardRank)
    {
        same=true;
    }
    return same;
}

//Function: isLess
//Purpose: To check if player's 1 card is less than player's 2 card
//Parameters: Both players' card
//Returns: A boolean value
bool isLess(Card card1, Card card2)
{
    bool same=false;
    if (card1.cardRank<card2.cardRank)
    {
        same=true;
    }
    return same;
}

int main ()
{
    std::string player1;
    std::string player2;
    
    std::cout<<"Enter player 1 name: ";
    std::cin>>player1;
    std::cout<<"Enter player 2 name: ";
    std::cin>>player2;
    
    std::cout<<"\nWelcome to the World Champion High-Card Tournament Finals!"<<std::endl;
    std::cout<<"Today's Match is "<< player1<<" against "<<player2<< "!"<<std::endl;
    
    int count1=0;
    int count2=0;
    int round=1;

    Card card1;
    Card card2;
    
    std::srand(std::time(0));
    
    bool tryagain=true;
    while (tryagain)
    {
     
        std::cout<<"\nThis is the "<<round <<" round!"<<std::endl;
        std::cout<<"\nThe results are in...."<<std::endl;
        
        //Creating the randomized rank and suits
    card1=makeCard(getRandRank(), getRandSuit());
    card2=makeCard(getRandRank(), getRandSuit());
        
        //Converting cards to string
        std::string display1=cardToString (card1);
        std::string display2=cardToString (card2);
    
        //Check to see if the two card are of equal value
    if (isEqual(card1, card2))
    {
        std::cout<<player1<< " drew a "<<display1<<" equals "<<player2<< "'s  "<<display2<<"!"<<std::endl;
        std::cout<<player1<< " : " <<count1<< ", "<<player2<<" : "<<count2<<std::endl;
        std::cout<<"It's a tie!"<<std::endl;
    }
        //check to see if card 1 is greater than card 2
    else if (isGreater(card1, card2))
    {
        std::cout<<player1<< " drew a "<<display1<<" beating "<<player2<< "'s "<<display2<<"!"<<std::endl;
        count1++;
        std::cout<<player1<< " : " <<count1<< ", "<<player2<<" : "<<count2<<std::endl;
        std::cout<<player1<<" wins this round!"<<std::endl;
    }
        //check to see if card 1 is less than card 2
    else if (isLess(card1, card2))
    {
        std::cout<<player1<< " drew a "<<display1<<" and loses to "<<player2<< "'s "<<display2<<"!"<<std::endl;
        count2++;
        std::cout<<player1<< " : " <<count1<< ", "<<player2<<" : "<<count2<<std::endl;
        std::cout<<player2<<" wins this round!"<<std::endl;
    }
        

        std::string goAgain;
        std::cout<<"Should they play again?"<<std::endl;
        std::cin>>goAgain;
        
        //If user wants to go another round
        if (goAgain=="y"|| goAgain=="yes")
        {
            //Program will continue.
            round++;
        }
        
        //If the user wishes to end the competiton 
        else
        {
            tryagain=false;
            
            if (count1>count2)
            {
                std::cout<<"\n"<<player1<<" wins it all!"<<std::endl;
            }
            else if (count1<count2)
            {
                std::cout<<"\n"<<player2<<" wins it all!"<<std::endl;
            }
            else if (count1==count2)
            {
                std::cout<<"\nIt ends in a draw!"<<std::endl;
            }
            
            std::cout<<"\nWell that's all folks! We cheered, we cried, we saw it all! This is Edwin Gonzalez signing out!"<<std::endl;
        }
    }
    return 0;
}
