#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <memory>
#include "board.hpp"
#include "piece.hpp"
#include "knight.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "bishop.hpp"


PieceMap makePieces() {
    PieceMap pieces;

    pieces["bR2"] = std::make_unique<Rook>("2", Position{0, 0}, false);
    pieces["bN2"] = std::make_unique<Knight>("2", Position{0, 1}, false);
    pieces["bB2"] = std::make_unique<Bishop>("2", Position{0, 2}, false);
    pieces["bQ1"] = std::make_unique<Queen>("1", Position{0, 3}, false);
    pieces["bK1"] = std::make_unique<King>("1", Position{0, 4}, false);
    pieces["bB1"] = std::make_unique<Bishop>("1", Position{0, 5}, false);
    pieces["bN1"] = std::make_unique<Knight>("1", Position{0, 6}, false);
    pieces["bR1"] = std::make_unique<Rook>("1", Position{0, 7}, false);
    pieces["bP8"] = std::make_unique<Pawn>("8", Position{1, 0}, false);
    pieces["bP7"] = std::make_unique<Pawn>("7", Position{1, 1}, false);
    pieces["bP6"] = std::make_unique<Pawn>("6", Position{1, 2}, false);
    pieces["bP5"] = std::make_unique<Pawn>("5", Position{1, 3}, false);
    pieces["bP4"] = std::make_unique<Pawn>("4", Position{1, 4}, false);
    pieces["bP3"] = std::make_unique<Pawn>("3", Position{1, 5}, false);
    pieces["bP2"] = std::make_unique<Pawn>("2", Position{1, 6}, false);
    pieces["bP1"] = std::make_unique<Pawn>("1", Position{1, 7}, false);
    pieces["wP1"] = std::make_unique<Pawn>("1", Position{6, 0}, true);
    pieces["wP2"] = std::make_unique<Pawn>("2", Position{6, 1}, true);
    pieces["wP3"] = std::make_unique<Pawn>("3", Position{6, 2}, true);
    pieces["wP4"] = std::make_unique<Pawn>("4", Position{6, 3}, true);
    pieces["wP5"] = std::make_unique<Pawn>("5", Position{6, 4}, true);
    pieces["wP6"] = std::make_unique<Pawn>("6", Position{6, 5}, true);
    pieces["wP7"] = std::make_unique<Pawn>("7", Position{6, 6}, true);
    pieces["wP8"] = std::make_unique<Pawn>("8", Position{6, 7}, true);
    pieces["wR1"] = std::make_unique<Rook>("1", Position{7, 0}, true);
    pieces["wN1"] = std::make_unique<Knight>("1", Position{7, 1}, true);
    pieces["wB1"] = std::make_unique<Bishop>("1", Position{7, 2}, true);
    pieces["wQ1"] = std::make_unique<Queen>("1", Position{7, 3}, true);
    pieces["wK1"] = std::make_unique<King>("1", Position{7, 4}, true);
    pieces["wB2"] = std::make_unique<Bishop>("2", Position{7, 5}, true);
    pieces["wN2"] = std::make_unique<Knight>("2", Position{7, 6}, true);
    pieces["wR2"] = std::make_unique<Rook>("2", Position{7, 7}, true);

    return pieces;
}

std::vector<Position> validMoves(PieceMap& pieces, const board& gameboard, bool isWhite) {
    std::vector<Position> moveset;
    std::string color = isWhite ? "w" : "b";
    for (auto &pair: pieces) {
        if (pair.first.substr(0, 1) == color) {
            std::vector<Position> submoveset = pair.second->validMoves(gameboard);
            moveset.insert(moveset.end(), submoveset.begin(), submoveset.end());
        }
    }
    return moveset;
}

int main(void) {
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Chess");
    window.setFramerateLimit(60);

    sf::Image icon;
    if (!icon.loadFromFile("icons/chess.png"))
        return -1;
    window.setIcon(icon.getSize() , icon.getPixelsPtr());


    PieceMap pieces = makePieces();
    Board* gameboard = new Board(window, pieces, 60);
    bool whitePerspective = true;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        gameboard->drawBoard(whitePerspective);
        
    }


    delete gameboard;
    return 0;
}