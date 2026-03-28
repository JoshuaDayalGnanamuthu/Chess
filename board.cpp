#include <iostream>
#include <string>
#include <vector>
#include <map>


class Board {
    typedef std::vector<std::vector<std::string>> board;
    public:
        std::map<std::string, int> column_alias = {
            {"a", 0},
            {"b", 1},
            {"c", 2},
            {"d", 3},
            {"e", 4},
            {"f", 5},
            {"g", 6},
            {"h", 7}
        };
        
        board chess_board = {
            {"bR2","bN2","bB2","bQ","bK","bB1","bN1","bR1"},
            {"bP8","bP7","bP6","bP5","bP4","bP3","bP2","bP1"},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {"wP1","wP2","wP3", "wP4","wP5","wP6","wP7","wP8"},
            {"wR1","wN1","wB1","wQ","wK","wB2","wN2","wR2"}        
        };

        size_t num_rows = 8;
        size_t num_cols = 8;

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
        std::map<std::string, std::string> sprites = {
            {"wP", "♟"}, {"wR", "♜"}, {"wN", "♞"}, {"wB", "♝"}, {"wQ", "♛"}, {"wK", "♚"}, 
            {"bP", "♙"}, {"bR", "♖"}, {"bN", "♘"}, {"bB", "♗"}, {"bQ", "♕"}, {"bK", "♔"},
            {" ", " "}
        };
};

int main()
{
    Board board = Board();
    board.printBoardWhite();
    board.printBoardBlack();
    return 0;
}