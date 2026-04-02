#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

struct Position {
    int posY = -1;
    int posX = -1;

    bool operator==(const Position &other) const {
        return posY == other.posY && posX == other.posX;
    }
};
typedef std::vector<std::vector<std::string>> board;
typedef std::map<std::string, Position> Positions;

class Piece;
typedef std::map<std::string, std::unique_ptr<Piece>> PieceMap;

class Piece {
    public:
        bool isWhite;
        std::string type;
        std::string number;
        std::string piece;
        Position position;
        bool hasMoved = false;

        Piece(std::string type, std::string number, Position position, bool isWhite);
        bool isCheck(const board &chess_board, const PieceMap &pieces, bool isWhite) const;
        virtual std::vector<Position> validMoves(const board &chess_board) = 0;
        virtual ~Piece() = default;

    protected:
        bool canMoveTo(const std::string &target_piece) const;
        static const std::map<std::string, Position> default_piece_positions;
};
