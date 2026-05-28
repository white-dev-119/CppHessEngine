#pragma once

#include <vector>
#include "Tile.hpp"
#include "Utils.hpp"

class ChessEngine
{
public:
    ChessEngine();
    std::vector<Tile> movePiece(PlayerMove move);
    std::vector<Tile> getBoard() const;
    bool validateMove(PlayerMove move);
    std::vector<Position> getPossibleMoves(Position figurePosition);

private:
    std::vector<Tile> board;
    void initializeBoard();
};