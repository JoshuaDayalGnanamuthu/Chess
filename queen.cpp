#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "queen.hpp"


std::vector<Position> Queen::validMoves(const board &chess_board){
    std::vector<Position> moveset = {};
    bool topLeft = true;
    bool topRight = true;
    bool bottomLeft = true;
    bool bottomRight = true;

    for ( int i = 1; i < 8; i ++)
    {
        if (topRight) 
        {
            int row = this->position.posY - i;
            int col = this->position.posX + i;
            if (row < 0 || col > 7) {
                topRight = false;
            }
            else
            {
                std::string piece = chess_board[row][col];
                if (piece == " ")
                {
                    Position new_position = {row, col};
                    moveset.push_back(new_position);
                }
                else 
                {
                    if ((this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row, col};
                        moveset.push_back(new_position);
                    }
                    topRight = false;
                }
            }
        }

        if (topLeft) 
        {
            int row = this->position.posY - i;
            int col = this->position.posX - i;
            if (row < 0 || col < 0) {
                topLeft = false;
            }
            else
            {
                std::string piece = chess_board[row][col];
                if (piece == " ")
                {
                    Position new_position = {row, col};
                    moveset.push_back(new_position);
                }
                else 
                {
                    if ((this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row, col};
                        moveset.push_back(new_position);
                    }
                    topLeft = false;
                }
            }
        }

        if (bottomRight) 
        {
            int row = this->position.posY + i;
            int col = this->position.posX + i;
            if (row > 7 || col > 7) {
                bottomRight = false;
            }
            else
            {
                std::string piece = chess_board[row][col];
                if (piece == " ")
                {
                    Position new_position = {row, col};
                    moveset.push_back(new_position);
                }
                else 
                {
                    if ((this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row, col};
                        moveset.push_back(new_position);
                    }
                    bottomRight = false;
                }
            }
        }

        if (bottomLeft) 
        {
            int row = this->position.posY + i;
            int col = this->position.posX - i;
            if (row > 7 || col < 0) {
                bottomLeft = false;
            }
            else
            {
                std::string piece = chess_board[row][col];
                if (piece == " ")
                {
                    Position new_position = {row, col};
                    moveset.push_back(new_position);
                }
                else 
                {
                    if ((this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row, col};
                        moveset.push_back(new_position);
                    }
                    bottomLeft = false;
                }
            }
        }
    }

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

        