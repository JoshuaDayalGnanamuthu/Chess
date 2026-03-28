#include <iostream>
#include <string>
#include <vector>
#include <map>

#define RESET       "\033[0m"
#define BG_LIGHT    "\033[48;2;240;217;181m"
#define BG_DARK     "\033[48;2;181;136;101m"
#define FG_WHITE    "\033[97m"
#define FG_BLACK    "\033[30m"

class Board {
    typedef std::vector<std::vector<std::string>> board;
    public:
        board chess_board = {
            {"black_rook","black_knight","black_bishop","black_queen","black_king","black_bishop","black_knight","black_rook"},
            {"black_pawn","black_pawn","black_pawn","black_pawn","black_pawn","black_pawn","black_pawn","black_pawn"},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {" "," "," "," "," "," "," "," "},
            {"white_pawn","white_pawn","white_pawn","white_pawn","white_pawn","white_pawn","white_pawn","white_pawn"},
            {"white_rook","white_knight","white_bishop","white_queen","white_king","white_bishop","white_knight","white_rook"}
        };

        void print_board_white(void) {
            std::cout << "\n     a     b     c     d     e     f     g     h\n\n";
            for (int row = 0; row < 8; row++)
            {

                printPaddingRow(row);
                std::cout << " " << (8 - row) << " ";
                printPieceRow(row);
                std::cout << "  " << (8 - row) << "\n";
                printPaddingRow(row);
            }
            std::cout << "\n     a     b     c     d     e     f     g     h\n\n";
        }

        void print_board_black(void) {
            std::cout << "\n     h     g     f     e     d     c     b     a\n\n";
            for (int row = 7; row >= 0; row--)
            {
                printPaddingRow(row, true);
                std::cout << " " << (8 - row) << " ";
                printPieceRow(row, true);
                std::cout << "  " << (8 - row) << "\n";
                printPaddingRow(row, true);
            }
            std::cout << "\n     h     g     f     e     d     c     b     a\n\n";
        }

    private:
        std::map<std::string, std::string> sprites = {
            {"white_pawn",   "♙"}, {"white_rook",   "♖"}, {"white_knight", "♘"},
            {"white_bishop", "♗"}, {"white_queen",  "♕"}, {"white_king",   "♔"},
            {"black_pawn",   "♟"}, {"black_rook",   "♜"}, {"black_knight", "♞"},
            {"black_bishop", "♝"}, {"black_queen",  "♛"}, {"black_king",   "♚"},
            {" ", " "}
        };

        bool isWhitePiece(const std::string& piece) {
            return piece.substr(0, 5) == "white";
        }

        std::string getBg(int row, int col) {
            return ((row + col) % 2 == 0) ? BG_LIGHT : BG_DARK;
        }

        void printPaddingRow(int row, bool reversed = false) {
            std::cout << "   ";
            for (int i = 0; i < 8; i++) {
                int col = reversed ? (7 - i) : i;
                std::cout << getBg(row, col) << "      " << RESET;
            }
            std::cout << "\n";
        }

        void printPieceRow(int row, bool reversed = false) {
            for (int i = 0; i < 8; i++) {
                int col = reversed ? (7 - i) : i;
                std::string bg = getBg(row, col);
                std::string fg = isWhitePiece(chess_board[row][col]) ? FG_WHITE : FG_BLACK;
                std::string sprite = sprites.count(chess_board[row][col]) ? sprites[chess_board[row][col]] : " ";
                std::cout << bg << fg << "  " << sprite << "   " << RESET;
            }
        }
};

int main()
{
    Board board = Board();
    board.print_board_white();
    board.print_board_black();
    return 0;
}