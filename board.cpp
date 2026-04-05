#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "board.hpp"

const sf::Color LIGHT_COLOR(255, 255, 255);
const sf::Color DARK_COLOR(118, 150, 0);
const sf::Color HIGHLIGHT_COLOR(255, 255, 0, 100);
const int TILE_SIZE = 50;
    
Board::Board(sf::RenderWindow &window, PieceMap& pieces, int frameRate): window(window), pieces(pieces) {
    this->window.setFramerateLimit(frameRate);
    makeBoard();
    MakeSprites();
}

void Board::evaluate() {
    this->whiteScore = 0;
    this->blackScore = 0;
    for (const auto &pair: this->pieces) {
        std::string pieceType = pair.second->type;
        int pieceValue = pieceValues[pieceType];
        if (pair.second->isWhite) {
            this->whiteScore += pieceValue;
        }
        else {
            this->blackScore += pieceValue;
        }
    }
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

void Board::drawBoard(bool whitePerspective, std::vector<Position> highlights) {
    makeBoard();
    window.clear(sf::Color::Black);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int row = whitePerspective ? i : 7 - i;
            int col = whitePerspective ? j : 7 - j;

            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            tile.setPosition(sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE));
            tile.setFillColor((row + col) % 2 == 0 ? LIGHT_COLOR : DARK_COLOR);
            window.draw(tile);

            bool isHighlight = false;
            for (auto& move : highlights) {
                if (move.posY == row && move.posX == col) {
                    isHighlight = true;
                    break;
                }
            }

            if (isHighlight) {
                sf::RectangleShape highlight(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                highlight.setPosition(sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE));
                if ((row + col) % 2 == 0)
                    highlight.setFillColor(sf::Color(130, 151, 105, 200));
                else
                    highlight.setFillColor(sf::Color(106, 111, 64, 200));
                window.draw(highlight);
            }

            std::string pieceKey = chess_board[row][col].substr(0, 2);
            if (textures.count(pieceKey)) {
                sf::Sprite sprite(textures[pieceKey]);
                sprite.setScale(sf::Vector2f(
                    (float)TILE_SIZE / textures[pieceKey].getSize().x,
                    (float)TILE_SIZE / textures[pieceKey].getSize().y
                ));
                sprite.setPosition(sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE));
                window.draw(sprite);
            }
        }
    }
    window.display();
}
