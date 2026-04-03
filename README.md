# Chess Game

A simple chess game implemented in C++ using the SFML library.

## Features

- Full chess board with piece movement
- Legal move validation (prevents illegal moves that would leave king in check)
- Checkmate detection with game over screen
- Sound effects for moves, captures, and check
- Visual highlights for possible moves
- Perspective switching between white and black

## Requirements

- C++17 compatible compiler (e.g., clang++)
- SFML 3.0 or later
- macOS (tested on macOS, may work on other platforms with SFML)

## Building

1. Ensure SFML is installed via Homebrew:
   ```
   brew install sfml
   ```

2. Clone or download the project files.

3. Run make to build:
   ```
   make
   ```

## Running

Execute the built binary:
```
./build/main
```

## Controls

- Left-click on a piece to select it and see highlighted legal moves
- Left-click on a highlighted square to move the piece
- Close the window to exit

## Game Rules

Standard chess rules apply. The game detects checkmate and displays a winner screen.

## File Structure

- `main.cpp`: Main game loop and logic
- `board.cpp/hpp`: Board rendering and management
- `piece.cpp/hpp`: Base piece class
- `king.cpp/hpp`, `queen.cpp/hpp`, etc.: Individual piece implementations
- `audio/`: Sound effect files
- `icons/`: Icon file
- `koval/`: Piece sprite images

## License

This project is for educational purposes.