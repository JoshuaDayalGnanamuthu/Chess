#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "board.hpp"
#include "piece.hpp"
#include "knight.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "bishop.hpp"
#include <algorithm>
#include <chrono>
#include <thread>

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

std::map<std::string, std::vector<Position>> validMoves(PieceMap& pieces, const board& gameboard, bool isWhite) {
    std::map<std::string, std::vector<Position>> moveset;
    std::string color = isWhite ? "w" : "b";
    for (auto &pair : pieces) {
        if (pair.first.substr(0, 1) == color)
            moveset[pair.first] = pair.second->validMoves(gameboard);
    }
    return moveset;
}

Position tilePressed(int posX, int posY, bool isWhite) {
    Position tile;
    if (isWhite) {
        tile.posY = posY;
        tile.posX = posX;
    } else {
        tile.posY = 7 - posY;
        tile.posX = 7 - posX;
    }
    return tile;
}

int main(void) {
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Chess");
    window.setFramerateLimit(60);

    sf::Image icon;
    if (!icon.loadFromFile("icons/chess.png"))
        return -1;
    window.setIcon(icon.getSize(), icon.getPixelsPtr());

    PieceMap pieces = makePieces();
    Board* gameboard = new Board(window, pieces, 60);
    bool whitePerspective = true;
    std::string color = whitePerspective ? "w" : "b";
    std::vector<Position> highlights;
    Position tile_pressed = {-1, -1};

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("audio/game_start.mp3")) {
        std::cerr << "Error loading sound effect" << std::endl;
        return -1;
    }
    sf::Sound sound(buffer);
    sound.play();

    sf::SoundBuffer gameOverBuffer;
    if (!gameOverBuffer.loadFromFile("audio/game_start.mp3")) {
        std::cerr << "Error loading sound effect" << std::endl;
        return -1;
    }
    sf::Sound endsound(gameOverBuffer);

    sf::SoundBuffer isCheckBuffer;
    if (!isCheckBuffer.loadFromFile("audio/move-check.mp3")) {
        std::cerr << "Error loading sound effect" << std::endl;
        return -1;
    }
    sf::Sound checkSound(isCheckBuffer);

    sf::SoundBuffer isIllegalBuffer;
    if (!isIllegalBuffer.loadFromFile("audio/illegal.mp3")) {
        std::cerr << "Error loading sound effect" << std::endl;
        return -1;
    }
    sf::Sound illegalSound(isIllegalBuffer);
    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                endsound.play();
                while (endsound.getStatus() == sf::Sound::Status::Playing) {
                    sf::sleep(sf::milliseconds(100));
                }
                window.close();
            }
                
            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseEvent->button == sf::Mouse::Button::Left) {
                    Position tile = tilePressed(mouseEvent->position.x / TILE_SIZE, mouseEvent->position.y / TILE_SIZE, whitePerspective);
                    if (!highlights.empty() && std::find(highlights.cbegin(), highlights.cend(), tile) != highlights.cend()) {
                        std::string piece = gameboard->chess_board[tile_pressed.posY][tile_pressed.posX];
                        std::string target_piece = gameboard->chess_board[tile.posY][tile.posX];

                        sf::SoundBuffer moveBuffer;
                        sf::SoundBuffer captureBuffer;
                        if (!moveBuffer.loadFromFile("audio/move.mp3")) {
                            std::cerr << "Error loading sound effect" << std::endl;
                            return -1;
                        }
                        if (!captureBuffer.loadFromFile("audio/capture.mp3")) {
                            std::cerr << "Error loading sound effect" << std::endl;
                            return -1;
                        }
                        
                        gameboard->chess_board[tile.posY][tile.posX] = piece;
                        gameboard->chess_board[tile_pressed.posY][tile_pressed.posX] = " ";
                        pieces[piece]->position = tile;
                        pieces[piece]->hasMoved = true;
                        gameboard->makeBoard();
                        if (pieces[piece]->isCheck(gameboard->chess_board, pieces, whitePerspective)) {
                            illegalSound.play();
                            gameboard->chess_board[tile_pressed.posY][tile_pressed.posX] = piece;
                            gameboard->chess_board[tile.posY][tile.posX] = target_piece;
                            pieces[piece]->position = tile_pressed;
                            pieces[piece]->hasMoved = false;
                            continue;
                        }
                        if (target_piece != " ") {
                            pieces.erase(target_piece);
                        }
                        highlights.clear();

                        sf::Sound moveSound(moveBuffer);
                        sf::Sound captureSound(captureBuffer);

                        if (target_piece != " ") {
                            captureSound.play();
                            if (pieces[piece]->isCheck(gameboard->chess_board, pieces, !whitePerspective)) {
                                checkSound.play();
                            }
                        } 
                        else {
                            moveSound.play();
                            if (pieces[piece]->isCheck(gameboard->chess_board, pieces, !whitePerspective)) {
                                checkSound.play();
                            } 
                        }

                        gameboard->drawBoard(whitePerspective, highlights);
                        std::this_thread::sleep_for(std::chrono::milliseconds(800));
                        whitePerspective = !whitePerspective;
                        color = whitePerspective ? "w" : "b";
                    }
                    if (tile_pressed.posX == tile.posX && tile_pressed.posY == tile.posY) {
                        tile_pressed = {-1, -1};
                        highlights.clear();
                    } 
                    else {
                        tile_pressed = tile;
                        std::string clicked = gameboard->chess_board[tile.posY][tile.posX];
                        if (clicked != " " && clicked.substr(0, 1) == color) {
                            if (!buffer.loadFromFile("audio/move.mp3")) {
                                std::cerr << "Error loading sound effect" << std::endl;
                                return -1;
                            }
                            sf::Sound sound(buffer);
                            sound.play();
                            auto moves = validMoves(pieces, gameboard->chess_board, whitePerspective);
                            highlights = moves[clicked];
                            
                        } 
                        else {
                            highlights.clear();
                        }
                    } 
                }
            }
        }

        gameboard->drawBoard(whitePerspective, highlights);
    }

    delete gameboard;
    return 0;
}