#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "piece.hpp"

class Rook: public Piece {
    public:

        Rook(std::string number, Position position, bool isWhite)
        : Piece("R", number, position, isWhite) {}

        std::vector<Position> validMoves(const board &chess_board);

};