#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "pawn.hpp"

std::vector<Position> Pawn::validMoves(const board &chess_board){
    std::vector<Position> moveset = {};
    if (this->isWhite) {
        for ( int col_diff = -1 ; col_diff <= 1; col_diff++ ) 
        {
            if ( (this->position.posY - 1 < 0) || (this->position.posX + col_diff < 0) || (this->position.posX + col_diff > 7))
            {
                continue;
            }
            else if (col_diff == 0)
            {
                if (chess_board[this->position.posY - 1][this->position.posX] == " ") 
                {
                    Position new_position = {this->position.posY - 1, this->position.posX};
                    moveset.push_back(new_position);
                    if (!this->hasMoved && chess_board[this->position.posY - 2][this->position.posX] == " ") 
                    {
                        Position new_position = {this->position.posY - 2, this->position.posX};
                        moveset.push_back(new_position);
                    }
                }
            }
            else 
            {
                std::string piece = chess_board[this->position.posY - 1][this->position.posX + col_diff];
                if (piece.substr(0, 1) == "b") {
                    Position new_position = {this->position.posY - 1, this->position.posX + col_diff};
                    moveset.push_back(new_position);
                }
            }
        }
    }
    else 
    {
        for ( int col_diff = -1 ; col_diff <= 1; col_diff++ ) 
        {
            if ( (this->position.posY + 1 > 7) || (this->position.posX + col_diff < 0) || (this->position.posX + col_diff > 7))
            {
                continue;
            }
            else if (col_diff == 0)
            {
                if (chess_board[this->position.posY + 1][this->position.posX] == " ") 
                {
                    Position new_position = {this->position.posY + 1, this->position.posX};
                    moveset.push_back(new_position);
                    if (!this->hasMoved && chess_board[this->position.posY + 2][this->position.posX] == " ") 
                    {
                        Position new_position = {this->position.posY + 2, this->position.posX};
                        moveset.push_back(new_position);
                    }
                }
            }
            else 
            {
                std::string piece = chess_board[this->position.posY + 1][this->position.posX + col_diff];
                if (piece.substr(0, 1) == "w") {
                    Position new_position = {this->position.posY + 1, this->position.posX + col_diff};
                    moveset.push_back(new_position);
                }
            }
        }
    }
    return moveset;
}

