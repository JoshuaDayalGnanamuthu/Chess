#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "bishop.hpp"


std::vector<Position> Bishop::validMoves(const board &chess_board){
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

    return moveset;
}
