#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "piece.hpp"

class Bishop: public Piece {
    public:
        
        Bishop(std::string number, Position position, bool isWhite) 
        : Piece("B", number, position, isWhite) {}

        std::vector<Position> validMoves(const board &chess_board);

};