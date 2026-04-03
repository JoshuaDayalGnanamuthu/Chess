#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "king.hpp"

std::vector<Position> King::validMoves(const board &chess_board){
    std::vector<Position> moveset = {};

    int row = this->position.posY;
    int col = this->position.posX;

    if (row - 1 >= 0 && col - 1 >= 0)
    {
        std::string piece = chess_board[row - 1][col - 1];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row - 1, col - 1};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }

    if (row - 1 >= 0)
    {
        std::string piece = chess_board[row - 1][col];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row - 1, col};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }

    if (row - 1 >= 0 && col + 1 <= 7)
    {
        std::string piece = chess_board[row - 1][col + 1];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row - 1, col + 1};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }

    if (col - 1 >= 0)
    {
        std::string piece = chess_board[row][col - 1];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row, col - 1};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }

    if (col + 1 <= 7)
    {
        std::string piece = chess_board[row][col + 1];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row, col + 1};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }

    if (row + 1 <= 7 && col - 1 >= 0)
    {
        std::string piece = chess_board[row + 1][col - 1];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row + 1, col - 1};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }

    if (row + 1 <= 7)
    {
        std::string piece = chess_board[row + 1][col];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row + 1, col};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }

    if (row + 1 <= 7 && col + 1 <= 7)
    {
        std::string piece = chess_board[row + 1][col + 1];
        if (piece == " " || (this->isWhite && piece.substr(0,1) == "b") || (!this->isWhite && piece.substr(0,1) == "w"))
        {
            Position new_position = {row + 1, col + 1};
            if (isLegal(new_position)) 
            {
                moveset.push_back(new_position);
            }
        }
    }
    
    return moveset;
}