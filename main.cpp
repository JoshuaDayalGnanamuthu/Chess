#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "board.hpp"


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

int main(void) {
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Chess");
    window.setFramerateLimit(60);
    sf::Image icon;
    if (!icon.loadFromFile("icons/chess.png"))
        return -1;
    window.setIcon(icon.getSize() , icon.getPixelsPtr());

    Board* gameboard = new Board(window, piece_positions, 60);
    gameboard->printBoardWhite();











    delete gameboard;
    window.close();
    return 0;
}