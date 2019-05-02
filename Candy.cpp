// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// pjoyjr

// Candyland
// This program simulates the game of candyland by randomly
// generating numbers 1-10 to draw cards based on which player
// is up. the first player to tile 50 wins and each player cannot
// be on the same space at the same time.
// By: Paul Joy

#include <iostream>
#include <stdlib.h>
#include <ctime>

#define GAME_LENGTH 50

void advancePlayerA(int* ptrPlayerA);
void advancePlayerB(int* ptrPlayerB);
void printPosition(int* ptrPlayerA, int* ptrPlayerB);

void advancePlayerA(int* ptrPlayerA)
{
    int ranNum;
    ranNum = rand() % 10 + 1; //creates a random number from 1-10
    int moved;
    if(ranNum < 5) // 40% chance of moving 1 forward
    {
        moved = 1;
    }
    if(ranNum == 5 || ranNum == 6) // 20% chance of moving 2 forward
    {
        moved = 2;
    }
    if(ranNum == 7) // 10% chance of moving 3 forward
    {
        moved = 3;
    }
    if(ranNum == 8) // 10% chance of moving 5 forward
    {
        moved = 5;
    }
    if(ranNum == 9) // 10% chance of moving 3 backwards
    {
        moved = -3;
    }
    if(ranNum == 10) // 10% chance of moving 5 backwards
    {
        moved = -5;
    }
    //std::cout << "Player 1 Position " << *ptrPlayerA << std::endl;
    *ptrPlayerA = *ptrPlayerA + moved; //increment their position by turn
   // std::cout << "Player 1 new Position " << *ptrPlayerA << std::endl;

}

void advancePlayerB(int* ptrPlayerB)
{
    int ranNum;
    int moved;
    ranNum = rand() % 10 + 1; //creates a random number 1-10
    if(ranNum < 4) // 30% chance of moving 1 forward
    {
        moved = 1;
    }
    if(ranNum == 4) //10% chance of moving 2 forward
    {
        moved = 2;
    }
    if(ranNum == 5 || ranNum ==6) // 20% chance of moving 3 forward
    {
        moved = 3;
    }
    if(ranNum == 7) // 10% chance of moving 5 forward
    {
        moved = 5;
    }
    if(ranNum == 8 || ranNum == 9) // 20% chance of moving 3 backwards
    {
        moved = -3;
    }
    if(ranNum == 10) // 10% chance of moving 5 backwards
    {
        moved = -5;
    }
    //std::cout << "Player 2 Position " << *ptrPlayerB << std::endl;
    *ptrPlayerB = *ptrPlayerB + moved; // increment their position by turn
   // std::cout << "Player 2 new Position " << *ptrPlayerB << std::endl;

}
void printPosition(int* ptrPlayerA, int* ptrPlayerB)
{
    int winner = 0; //for checking winner
    if(*ptrPlayerA >= 50) //dont allow player to have more than 50
    {
        *ptrPlayerA = 50;
        std::cout << "\n You reached Candy Castle first! Congratulations " << std::endl;
        winner = 1; //we have a winner
    }
    if(*ptrPlayerB >= 50) //dont allow player to have more than 50
    {
        *ptrPlayerB = 50;
        std::cout << "\n Your friend reached Candy Castle first! Better luck next time" << std::endl;
        winner = 1; //we have a winner
    }
    if(*ptrPlayerA == *ptrPlayerB) //if same spot, move player A back 1
    {
        *ptrPlayerA= *ptrPlayerA - 1;
    }
    if(*ptrPlayerA < 0) //if negative spot, restart at 0
    {
        *ptrPlayerA = 0;
    }
    if(*ptrPlayerB < 0) //if negative spot, restart at 0
    {
        *ptrPlayerB = 0;
    }
    if(*ptrPlayerA == 0 && *ptrPlayerB == 0) //if both at zero, player B moves to spot 1
    {
        *ptrPlayerB = 1;
    }
    char gameboard [GAME_LENGTH]; //size of board
    if(winner == 0) //if somebody hasnt won print board
    {
        for(int i=0; i<GAME_LENGTH; i++)
        {
            gameboard[i] = ' '; //set all spaces to spaces
        }
        gameboard[*ptrPlayerA] = 'A'; //add player a to board
        gameboard[*ptrPlayerB] = 'B'; //add player b to board
        for(int j=0; j<GAME_LENGTH; j++)
        {
            std::cout << gameboard[j]; //prints board
        }
        std::cout << "|" <<std::endl; //end of board
    }
}
int main()
{

    int pAPosition = 0, pBPosition = 0;
    int * ptrA, * ptrB;
    ptrA = &pAPosition; //ptr for player a
    ptrB = &pBPosition; //ptr for player b
    srand(time(NULL)); //needed for a real random generator
    std::cout <<"Welcome to CSCI 240's Candy Land Game! " << std::endl;
    while(*ptrA != 50 && *ptrB != 50) //if neither player has reached the 50th tile
    {
        advancePlayerA(ptrA); //move player A
        advancePlayerB(ptrB); //move player B
        printPosition(ptrA, ptrB); //print board
        //std::cout <<"ptrA: "<< *ptrA << " \t ptrB: " << *ptrB << std::endl;
    }
	return 0;
}
