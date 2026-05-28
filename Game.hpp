#pragma once

#include <string>
#include <iomanip>
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

private:
    bool running;
    ChessEngine engine;
    void drawBoard(const std::vector<Tile> &board);
};