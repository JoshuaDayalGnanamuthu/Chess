#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "board.hpp"

const sf::Color LIGHT_COLOR(255, 255, 255);
const sf::Color DARK_COLOR(118, 150, 0);
const int TILE_SIZE = 50;
    
Board::Board(sf::RenderWindow &window, PieceMap& pieces, int frameRate): window(window), pieces(pieces) {
    this->window.setFramerateLimit(frameRate);
    makeBoard();
    MakeSprites();
}

void Board::makeBoard() {
    for (auto &row: this->chess_board) {
        for (auto &cell : row) {
            cell = " ";
        }
    }
    for (auto &pair : this->pieces) {
        int row = pair.second->position.posY;
        int col = pair.second->position.posX;
        this->chess_board[row][col] = pair.first;
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
