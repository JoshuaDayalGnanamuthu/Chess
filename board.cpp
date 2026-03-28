#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef std::vector<std::vector<std::string>> Board;
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

Board board = {
        {"♖","♘","♗","♕","♔","♗","♘","♖"},
        {"♙","♙","♙","♙","♙","♙","♙","♙"},
        {" "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "},
        {" "," "," "," "," "," "," "," "},
        {"♟","♟","♟","♟","♟","♟","♟","♟"},
        {"♜","♞","♝","♛","♚","♝","♞","♜"}        
    };

void print_board_white(const Board &board) {
    std::cout << "\n    a   b   c   d   e   f   g   h\n";
    std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

    for (int row = 0; row < 8; row++)
    {
        std::cout << (8 - row) << " |";
        for (int col = 0; col < 8; col++)
        {
            std::cout << " " << board[row][col] << " " << "|";
        }
        std::cout << " " << (8 - row) << "\n";
        std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    }

    std::cout << "    a   b   c   d   e   f   g   h\n\n";
}
void print_board_black(const Board &board) {
    std::cout << "\n    a   b   c   d   e   f   g   h\n";
    std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

    for (int row = 7; row >= 0; row--)
    {
        std::cout << (8 - row) << " |";
        for (int col = 0; col < 8; col++)
        {
            std::cout << " " << board[row][col] << " " << "|";
        }
        std::cout << " " << (8 - row) << "\n";
        std::cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    }

    std::cout << "    a   b   c   d   e   f   g   h\n\n";
}

int main()
{
    print_board_white(board);
    print_board_black(board);
    return 0;
}