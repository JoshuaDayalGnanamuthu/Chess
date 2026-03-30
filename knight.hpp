#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "piece.hpp"


class Knight: public Piece {
    public:
        
        Knight(std::string number, Position position, bool isWhite) 
        : Piece("N", number, position, isWhite) {}

        std::vector<Position> validMoves(const board &chess_board);
   
};