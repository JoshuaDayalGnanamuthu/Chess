#pragma once

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

extern const sf::Color LIGHT_COLOR;
extern const sf::Color DARK_COLOR;
extern const int TILE_SIZE;

struct Position {
    int posY = -1;
    int posX = -1;
};
typedef std::map<std::string, Position> Positions;

class Board {
    typedef std::vector<std::vector<std::string>> board;

public:
    std::map<std::string, int> column_alias;
    size_t num_rows = 8;
    size_t num_cols = 8;
    board chess_board;
    sf::RenderWindow &window;
    Positions piece_positions;

    Board(sf::RenderWindow &window,
          Positions piece_positions = Board::default_piece_positions,
          int frameRate = 60);

    void makeBoard();
    void printBoardWhite();
    void printBoardBlack();

    static const Positions default_piece_positions;

private:
    std::map<std::string, std::string> file_paths;
    std::map<std::string, sf::Texture> textures;

    void MakeSprites();
};