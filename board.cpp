#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Position {
    int posY = -1;
    int posX = -1;
};

class Board {
    typedef std::vector<std::vector<std::string>> board;
    public:
        std::map<std::string, int> column_alias = 
        {
            {"a", 0}, {"b", 1}, {"c", 2}, {"d", 3}, 
            {"e", 4}, {"f", 5}, {"g", 6}, {"h", 7}
        };

        size_t num_rows = 8;
        size_t num_cols = 8;
        board chess_board = board(num_rows, std::vector<std::string>(num_cols, " "));
        
        void makeBoard(void) {
            for (auto &pair: Board::default_piece_positions) {
                int row = pair.second.posY;
                int col = pair.second.posX;
                std::string piece = pair.first;
                this->chess_board[row][col] = piece;
            }
        }

        void printBoardWhite(void) {
            std::cout << "\n    a   b   c   d   e   f   g   h\n";
            std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

            for (int row = 0; row < 8; row++)
            {
                std::cout << (8 - row) << " |";
                for (int col = 0; col < 8; col++)
                {
                    std::string piece = (this->chess_board[row][col]).substr(0,2);
                    std::string sprite = sprites[piece];
                    std::cout << " " << sprite << " " << "|";
                }
                std::cout << " " << (8 - row) << "\n";
                std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
            }
            std::cout << "    a   b   c   d   e   f   g   h\n\n";
        }

        void printBoardBlack(void) {
            std::cout << "\n    h   g   f   e   d   c   b   a\n";
            std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

            for (int row = 7; row >= 0; row--)
            {
                std::cout << (8 - row) << " |";
                for (int col = 7; col >= 0; col--)
                {
                    std::string piece = (this->chess_board[row][col]).substr(0, 2);
                    std::string sprite = sprites[piece];
                    std::cout << " " << sprite << " " << "|";
                }
                std::cout << " " << (8 - row) << "\n";
                std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
            }
            std::cout << "    h   g   f   e   d   c   b   a\n\n";
        }

    private:
        std::map<std::string, std::string> sprites = 
        {
            {"wP", "♟"}, {"wR", "♜"}, {"wN", "♞"}, {"wB", "♝"}, {"wQ", "♛"}, {"wK", "♚"}, 
            {"bP", "♙"}, {"bR", "♖"}, {"bN", "♘"}, {"bB", "♗"}, {"bQ", "♕"}, {"bK", "♔"},
            {" ", " "}
        };

        static const std::map<std::string, Position> default_piece_positions;
};

const std::map<std::string, Position> Board::default_piece_positions = 
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

int main()
{
    Board board = Board();
    board.makeBoard();
    board.printBoardWhite();
    board.printBoardBlack();
    return 0;
}