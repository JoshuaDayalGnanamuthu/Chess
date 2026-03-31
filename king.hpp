#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "piece.hpp"


class King: public Piece {
    public:
        bool hasMoved = false;
        
        King(std::string number, Position position, bool isWhite) 
        : Piece("K", number, position, isWhite) {}

        std::vector<Position> validMoves(const board &chess_board);
        bool isLegal(const Position &position);
   
};