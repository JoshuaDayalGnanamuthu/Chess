#include <iostream>
#include <string>
#include <vector>
#include <map>


class Board {
    typedef std::vector<std::vector<std::string>> board;
    public:
        board chess_board = {
            {"♖","♘","♗","♕","♔","♗","♘","♖"},
            {"♙","♙","♙","♙","♙","♙","♙","♙"},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {"♟","♟","♟","♟","♟","♟","♟","♟"},
            {"♜","♞","♝","♛","♚","♝","♞","♜"}        
        };

        size_t num_rows = 8;
        size_t num_cols = 8;

        void print_board_white(void) {
            std::cout << "\n    a   b   c   d   e   f   g   h\n";
            std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

            for (int row = 0; row < 8; row++)
            {
                std::cout << (8 - row) << " |";
                for (int col = 0; col < 8; col++)
                {
                    std::cout << " " << this->chess_board[row][col] << " " << "|";
                }
                std::cout << " " << (8 - row) << "\n";
                std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
            }
            std::cout << "    a   b   c   d   e   f   g   h\n\n";
        }

        void print_board_black(void) {
            std::cout << "\n    a   b   c   d   e   f   g   h\n";
            std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

            for (int row = 7; row >= 0; row--)
            {
                std::cout << (8 - row) << " |";
                for (int col = 0; col < 8; col++)
                {
                    std::cout << " " << this->chess_board[row][col] << " " << "|";
                }
                std::cout << " " << (8 - row) << "\n";
                std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
            }
            std::cout << "    a   b   c   d   e   f   g   h\n\n";
        }

    private:
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
};

int main()
{
    Board board = Board();
    board.print_board_black();
    board.print_board_white();
    std::cout << "Hello World \n" << std::endl;
    return 0;
}