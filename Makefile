GCC = clang++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic
LDFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system
SRCS = main.cpp board.cpp rook.cpp king.cpp queen.cpp piece.cpp pawn.cpp bishop.cpp knight.cpp

main: $(SRCS)
	$(GCC) $(CFLAGS) $(SRCS) -o build/main $(LDFLAGS)

clean:
	rm -f build/main