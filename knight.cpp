#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef std::vector<std::vector<std::string>> board;
typedef struct {
    int posY = -1;
    int posX = -1;
} Position;

class Knight {
    public:
        std::string piece;
        std::string type = "N";
        std::string number;
        Position position; 
        bool isWhite;

        Knight(std::string number, bool isWhite = true) 
        {
            this->isWhite = isWhite;
            this->number = number;
            this->piece = ((this->isWhite) ? "w" : "b") + this->type + this->number;
            this->position = piece_positions.at(this->piece);
        }

        std::vector<Position> validMoves(const board &chess_board){
            std::vector<Position> moveset = {};
            
            int row = this->position.posY;
            int col = this->position.posX;

            if (row + 2 < 8)
            {
                if (col + 1 < 8)
                {
                    std::string piece = chess_board[row + 2][col + 1];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row + 2, col + 1};
                        moveset.push_back(new_position);
                    }
                }

                if (col - 1 >= 0) 
                {
                    std::string piece = chess_board[row + 2][col - 1];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row + 2, col - 1};
                        moveset.push_back(new_position);
                    }
                }
            }

            if (row - 2 >= 0)
            {
                if (col + 1 < 8)
                {
                    std::string piece = chess_board[row - 2][col + 1];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row - 2, col + 1};
                        moveset.push_back(new_position);
                    }
                }

                if (col - 1 >= 0) 
                {
                    std::string piece = chess_board[row - 2][col - 1];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row - 2, col - 1};
                        moveset.push_back(new_position);
                    }
                }
            }

            if (col + 2 < 8)
            {
                if (row + 1 < 8)
                {
                    std::string piece = chess_board[row + 1][col + 2];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row + 1, col + 2};
                        moveset.push_back(new_position);
                    }
                }

                if (row - 1 >= 0) 
                {
                    std::string piece = chess_board[row - 1][col + 2];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row - 1, col + 2};
                        moveset.push_back(new_position);
                    }
                }
            }

            if (col - 2 >= 0)
            {
                if (row + 1 < 8)
                {
                    std::string piece = chess_board[row + 1][col - 2];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row + 1, col - 2};
                        moveset.push_back(new_position);
                    }
                }

                if (row - 1 >= 0) 
                {
                    std::string piece = chess_board[row - 1][col - 2];
                    if (piece == " " || (this->isWhite && piece.substr(0, 1) == "b") || (!this->isWhite && piece.substr(0, 1) == "w"))
                    {
                        Position new_position = {row - 1, col - 2};
                        moveset.push_back(new_position);
                    }
                }
            }
                
            return moveset;
        }


    private:
        static const std::map<std::string, Position> piece_positions;
};

const std::map<std::string, Position> Knight::piece_positions = 
        {
            {"bR2", {0, 0}}, {"bN2", {0, 1}}, {"bB2", {0, 2}}, {"bQ",  {0, 3}},
            {"bK",  {0, 4}}, {"bB1", {0, 5}}, {"bN1", {0, 6}}, {"bR1", {0, 7}},
            {"bP8", {1, 0}}, {"bP7", {1, 1}}, {"bP6", {1, 2}}, {"bP5", {1, 3}},
            {"bP4", {1, 4}}, {"bP3", {1, 5}}, {"bP2", {1, 6}}, {"bP1", {1, 7}},
            {"wP1", {6, 0}}, {"wP2", {6, 1}}, {"wP3", {6, 2}}, {"wP4", {6, 3}},
            {"wP5", {6, 4}}, {"wP6", {6, 5}}, {"wP7", {6, 6}}, {"wP8", {6, 7}},
            {"wR1", {7, 0}}, {"wN1", {7, 1}}, {"wB1", {7, 2}}, {"wQ",  {7, 3}},
            {"wK",  {7, 4}}, {"wB2", {7, 5}}, {"wN2", {7, 6}}, {"wR2", {7, 7}}
        };
        