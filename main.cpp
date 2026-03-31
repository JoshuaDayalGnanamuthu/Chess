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


Positions piece_positions = 
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

std::map<std::string, std::unique_ptr<Piece>> makePieces() {
    std::map<std::string, std::unique_ptr<Piece>> pieces;

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
        
int main(void) {
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Chess");
    window.setFramerateLimit(60);

    sf::Image icon;
    if (!icon.loadFromFile("icons/chess.png"))
        return -1;
    window.setIcon(icon.getSize() , icon.getPixelsPtr());


    std::map<std::string, std::unique_ptr<Piece>> pieces = makePieces();
    Board* gameboard = new Board(window, piece_positions, 60);
    gameboard->printBoardWhite();
    gameboard->printBoardBlack();











    delete gameboard;
    window.close();
    return 0;
}