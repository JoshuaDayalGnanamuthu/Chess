#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "rook.hpp"

std::vector<Position> Rook::validMoves(const board &chess_board){
    std::vector<Position> moveset = {};

    for ( int row = this->position.posY + 1; row < 8; row++ ) 
    {
        int col = this->position.posX;
        if ( chess_board[row][col] == " "){
            Position new_position = {row, col};
            moveset.push_back(new_position);
        }
        else 
        {
            std::string piece = chess_board[row][col];
            if (this->isWhite && piece.substr(0, 1) == "b")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            else if (!this->isWhite && piece.substr(0, 1) == "w")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            break;
        }
    }

    for ( int row = this->position.posY - 1; row >= 0; row-- ) 
    {
        int col = this->position.posX;
        if ( chess_board[row][col] == " "){
            Position new_position = {row, col};
            moveset.push_back(new_position);
        }
        else 
        {
            std::string piece = chess_board[row][col];
            if (this->isWhite && piece.substr(0, 1) == "b")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            else if (!this->isWhite && piece.substr(0, 1) == "w")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            break;
        }
    }

    for ( int col = this->position.posX + 1; col < 8; col++ ) 
    {
        int row = this->position.posY;
        if ( chess_board[row][col] == " "){
            Position new_position = {row, col};
            moveset.push_back(new_position);
        }
        else 
        {
            std::string piece = chess_board[row][col];
            if (this->isWhite && piece.substr(0, 1) == "b")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            else if (!this->isWhite && piece.substr(0, 1) == "w")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            break;
        }
    }

    for ( int col = this->position.posX - 1; col >= 0; col-- ) 
    {
        int row = this->position.posY;
        if ( chess_board[row][col] == " "){
            Position new_position = {row, col};
            moveset.push_back(new_position);
        }
        else 
        {
            std::string piece = chess_board[row][col];
            if (this->isWhite && piece.substr(0, 1) == "b")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            else if (!this->isWhite && piece.substr(0, 1) == "w")
            {
                Position new_position = {row, col};
                moveset.push_back(new_position);
            }
            break;
        }
    }
    
    return moveset;
}

