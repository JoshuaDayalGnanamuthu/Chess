#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "board.hpp"

const sf::Color LIGHT_COLOR(255, 255, 255);
const sf::Color DARK_COLOR(118, 150, 0);
const int TILE_SIZE = 50;
    
const Positions Board::default_piece_positions = 
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

Board::Board(sf::RenderWindow &window, Positions piece_positions, int frameRate): window(window) {
    this->window.setFramerateLimit(frameRate);
    this->piece_positions = piece_positions;
    makeBoard();
    MakeSprites();
}

void Board::makeBoard(void) {
    for (auto &pair: piece_positions) {
        int row = pair.second.posY;
        int col = pair.second.posX;
        std::string piece = pair.first;
        this->chess_board[row][col] = piece;
    }
}

void Board::MakeSprites() 
{
    for ( auto &pair: file_paths ) 
    {
        if (pair.second == " ") continue;
        if (!textures[pair.first].loadFromFile(pair.second)) {
            std::cerr << "Failed to load texture: " << pair.second << "\n";
            return;
        };
    }
}

void Board::printBoardWhite(void) {
    makeBoard();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                return;
        }

        window.clear(sf::Color::Black);

        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                tile.setPosition(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE));
                if ((row + col) % 2 == 0)
                    tile.setFillColor(LIGHT_COLOR);
                else
                    tile.setFillColor(DARK_COLOR);
                window.draw(tile);

                std::string piece = this->chess_board[row][col];
                std::string pieceKey = piece.substr(0, 2);
                if (textures.count(pieceKey))
                {
                    sf::Sprite sprite(textures[pieceKey]);
                    sprite.setScale(sf::Vector2f((float)TILE_SIZE / textures[pieceKey].getSize().x,
                                                 (float)TILE_SIZE / textures[pieceKey].getSize().y));
                    sprite.setPosition(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE));
                    window.draw(sprite);
                }
            }
        }
        window.display();
    }
}

void Board::printBoardBlack(void) {
    makeBoard();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                return;
        }
        window.clear(sf::Color::Black);

        for (int row = 7; row >= 0; row--)
        {
            for (int col = 7; col >= 0; col--)
            {
                int drawRow = 7 - row;
                int drawCol = 7 - col;

                sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                tile.setPosition(sf::Vector2f(drawCol * TILE_SIZE, drawRow * TILE_SIZE));
                if ((row + col) % 2 == 0)
                    tile.setFillColor(LIGHT_COLOR);
                else
                    tile.setFillColor(DARK_COLOR);
                window.draw(tile);

                std::string piece = this->chess_board[row][col];
                std::string pieceKey = piece.substr(0, 2);
                if (textures.count(pieceKey))
                {
                    sf::Sprite sprite(textures[pieceKey]);
                    sprite.setScale(sf::Vector2f(
                        (float)TILE_SIZE / textures[pieceKey].getSize().x,
                        (float)TILE_SIZE / textures[pieceKey].getSize().y
                    ));
                    sprite.setPosition(sf::Vector2f(drawCol * TILE_SIZE, drawRow * TILE_SIZE));
                    window.draw(sprite);
                }
            }
        }
        window.display();
    }
}

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode({400, 400}), "Chess");
//     window.setFramerateLimit(60);
//     sf::Image icon;
//     if (!icon.loadFromFile("icons/chess.png"))
//         return -1;
//     window.setIcon(icon.getSize() , icon.getPixelsPtr());
//     Board* board = new Board(window);
//     board->printBoardWhite();
//     board->printBoardBlack();
//     window.close();
//     delete board;
//     return 0;
// }