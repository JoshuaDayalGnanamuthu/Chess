#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "knight.hpp"


std::vector<Position> Knight::validMoves(const board &chess_board){
    std::vector<Position> moveset = {};
            
    int row = this->position.posY;
    int col = this->position.posX;

    if (row + 2 < 8)
    {
        if (col + 1 < 8)
        {
            std::string piece = chess_board[row + 2][col + 1];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row + 2, col + 1};
                moveset.push_back(new_position);
            }
        }

        if (col - 1 >= 0) 
        {
            std::string piece = chess_board[row + 2][col - 1];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row + 2, col - 1};
                moveset.push_back(new_position);
            }
        }
    }

    if (row - 2 >= 0)
    {
        if (col + 1 < 8)
        {
            std::string piece = chess_board[row - 2][col + 1];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row - 2, col + 1};
                moveset.push_back(new_position);
            }
        }

        if (col - 1 >= 0) 
        {
            std::string piece = chess_board[row - 2][col - 1];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row - 2, col - 1};
                moveset.push_back(new_position);
            }
        }
    }

    if (col + 2 < 8)
    {
        if (row + 1 < 8)
        {
            std::string piece = chess_board[row + 1][col + 2];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row + 1, col + 2};
                moveset.push_back(new_position);
            }
        }

        if (row - 1 >= 0) 
        {
            std::string piece = chess_board[row - 1][col + 2];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row - 1, col + 2};
                moveset.push_back(new_position);
            }
        }
    }

    if (col - 2 >= 0)
    {
        if (row + 1 < 8)
        {
            std::string piece = chess_board[row + 1][col - 2];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row + 1, col - 2};
                moveset.push_back(new_position);
            }
        }

        if (row - 1 >= 0) 
        {
            std::string piece = chess_board[row - 1][col - 2];
            if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
            {
                Position new_position = {row - 1, col - 2};
                moveset.push_back(new_position);
            }
        }
    }
                
    return moveset;
}



        