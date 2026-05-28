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
    std::vector<PossibleMove> getPossibleMoves(Position figurePosition);

private:
    std::vector<Tile> board;
    std::vector<Event> event_list;
    void initializeBoard();
    void registerEvent(EventType event_type);
};