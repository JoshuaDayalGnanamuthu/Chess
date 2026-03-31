#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "piece.hpp"


class Queen: public Piece {
    public:
        
        Queen(std::string number, Position position, bool isWhite) 
        : Piece("Q", number, position, isWhite) {}

        std::vector<Position> validMoves(const board &chess_board);
   
};