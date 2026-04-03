#pragma once

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "piece.hpp"

extern const sf::Color LIGHT_COLOR;
extern const sf::Color DARK_COLOR;
extern const sf::Color HIGHLIGHT_COLOR;
extern const int TILE_SIZE;

class Board {
public:
    std::map<std::string, int> column_alias = 
    {
        {"a", 0}, {"b", 1}, {"c", 2}, {"d", 3}, 
        {"e", 4}, {"f", 5}, {"g", 6}, {"h", 7}
    };
    size_t num_rows = 8;
    size_t num_cols = 8;
    board chess_board = board(num_rows, std::vector<std::string>(num_cols, " "));
    sf::RenderWindow &window;
    PieceMap& pieces;

    Board(sf::RenderWindow &window, PieceMap& pieces, int frameRate = 60);

    void makeBoard();
    void drawBoard(bool whitePerspective, std::vector<Position> highlights);
    void clearTextures() { textures.clear(); }

private:
    std::map<std::string, std::string> file_paths = {
        {"wP", "koval/wP.png"}, {"wR", "koval/wR.png"}, {"wN", "koval/wN.png"}, 
        {"wB", "koval/wB.png"}, {"wQ", "koval/wQ.png"}, {"wK", "koval/wK.png"}, 
        {"bP", "koval/bP.png"}, {"bR", "koval/bR.png"}, {"bN", "koval/bN.png"}, 
        {"bB", "koval/bB.png"}, {"bQ", "koval/bQ.png"}, {"bK", "koval/bK.png"},
        {" ", " "}
    };
    std::map<std::string, sf::Texture> textures;

    void MakeSprites();
};