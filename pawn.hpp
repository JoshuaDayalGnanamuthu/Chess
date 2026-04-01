#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "piece.hpp"


class Pawn: public Piece {
    public:
        
        Pawn(std::string number, Position position, bool isWhite) 
        : Piece("P", number, position, isWhite) {}

        std::vector<Position> validMoves(const board &chess_board);
   
};