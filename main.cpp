#include <iostream>
#include <string>
#include "ignore.h"
// Design a board which updates with each move
// player 1 choice use O update the index of string based on number chosen
// player 2 choice use X
// boardGame() function should keep executing until all boxes are filled or there is a vertical, diagonal or horizontal match of 3 pairs
// possible matching pairs horizontal: 012, 345, 678, vertical: 036, 147, 258, diagonal: 048, 246
// ask to try again

bool triplePairFound(std::string gB){
    // horizonal pairs
    if (gB[0] != ' ' && gB[0] == gB[1] && gB[1] == gB[2]){
        return true;
    }
    else if (gB[3] != ' ' && gB[3] == gB[4] && gB[4] == gB[5])
    {
        return true;
    }
    else if (gB[6] != ' ' && gB[6] == gB[7] && gB[7] == gB[8])
    {
        return true;
    }
    // vertical pairs
    else if (gB[0] != ' ' && gB[0] == gB[3] && gB[3] == gB[6])
    {
        return true;
    }
    else if (gB[1] != ' ' && gB[1] == gB[4] && gB[4] == gB[7])
    {
        return true;
    }
    else if (gB[2] != ' ' && gB[2] == gB[5] && gB[5] == gB[8])
    {
        return true;
    }
    // diagonal pairs
    else if (gB[0] != ' ' && gB[0] == gB[4] && gB[4] == gB[8])
    {
        return true;
    }
    else if (gB[2] != ' ' && gB[2] == gB[4] && gB[4] == gB[6])
    {
        return true;
    }
    else{
        return false;
    }
    
    
}

// function to print the tic tac toe board
void printBoard(std::string board){

    std::cout << "+---+---+---+\n";
    std::cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |\n";
    std::cout << "+---+---+---+\n";
    std::cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |\n";
    std::cout << "+---+---+---+\n";
    std::cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |\n";
    std::cout << "+---+---+---+\n";

}

void boardGame(){
    // board displayed before the game starts 
    std::cout << "Tic-Tac-Toe game place at any of the 9 given squares \n";
    std::string demoBoard{"012345678"};

    printBoard(demoBoard);

    // track number of moves
    int moveNum{0};
    
    // game board with 9 empty characters
    std::string gameBoard(9,' ');
    while (!triplePairFound(gameBoard)){
        
        // value initialised at 9 so the loop runs since the value is greater than valid number of squares
        unsigned int playerOneChoice{9};
        // keep asking for input until an unnoccupied place is called
        while (playerOneChoice >= 9 || gameBoard[playerOneChoice] != ' '){
            std::cout << "Player #1 choose a square: ";
            std::cin >> playerOneChoice;
            // handle if the input is 
            if (extractionFailed()){
                std::cout << "Invalid input please try again\n";
                // unsigned int value resets to 0 by default if extraction fails
                playerOneChoice = 9;
                continue;
            }
            ignoreLine();
            if (playerOneChoice >= 9){
                std::cout << "Please choose a number between(0-8)\n";
                continue;
            }
            if (gameBoard [playerOneChoice] != ' '){
                std::cout << "place is already occupied choose another square!\n";
            }
        }
        // update the square chosen by the player 1
        gameBoard[playerOneChoice] = 'O';
        // print the game board
        printBoard(gameBoard);
        ++moveNum;
        
        // check if there is any pairs after player 1's move
        if (triplePairFound(gameBoard)){
            std::cout << "Congratulations! Player #1 wins!\n";
            std::cout << "Thank you for playing!\n";
            break;
        } 

        // player 1 will always get 5 moves so we check if it reaches past 9 moves
        if (moveNum >= 9){
            std::cout << "All squares are occupied, It is a draw!\n";
            break;
        } 

        unsigned int playerTwoChoice{9};
        while (playerTwoChoice >= 9 || gameBoard[playerTwoChoice] != ' '){
            std::cout << "Player #2 choose a square: ";
            std::cin >> playerTwoChoice;
            if (extractionFailed()){
                std::cout << "Invalid input please try again\n";\
                playerTwoChoice = 9;
                continue;
            }
            ignoreLine();
            if (playerTwoChoice >= 9){
                std::cout << "Please choose a number between(0-8)\n";
                continue;
            }
            if (gameBoard[playerTwoChoice] != ' '){
                std::cout << "place is already occupied choose another square!\n";
            }
        }
        // update the square chosen by the player 2
        gameBoard[playerTwoChoice] = 'X';
        //print the gameBoard
        printBoard(gameBoard);
        ++moveNum;
        // check of there is any pairs after player 2's move
        if (triplePairFound(gameBoard)){
            std::cout << "Congratulations! Player #2 wins!\n";
            break;
        }
    }  
}

// give choice to play again
bool playAgain(){
    char input{};
    while (input != 'y' && input != 'n'){
        std::cout << "Play the game again(y/n): ";
        std::cin >> input;
        ignoreLine();
    }

    if (input == 'y') return true;
    else return false;
    
}

int main(){
    do{
        boardGame();
    }while (playAgain());
    
    return 0;
}
