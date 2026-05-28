#pragma once

#include <string>
#include <iomanip>
#include <algorithm>

#include "Utils.hpp"
#include "Piece.hpp"
#include "Tile.hpp"
#include "ChessEngine.hpp"

class Game
{
public:
    Game(ChessEngine &engine);
    Game();
    void move(PlayerMove move);
    void getPossibleMoves(Position chess_pos);

private:
    bool running;
    ChessEngine engine;
    void drawBoard(const std::vector<Tile> &board);
    void drawBoard(const std::vector<Tile> &board, const std::vector<PossibleMove> &possible_positions);
};