#include "Game.hpp"
#include "Utils.hpp"

int main()
{
    Game game = Game();
    for (size_t i = 0; i < 5; i++)
    {
        Position pos;
        pos.row = 1 + i;
        pos.col = 6;
        game.getPossibleMoves(pos);
        PlayerMove move;
        move.from = pos;
        Position pos2;
        pos2.row = 1 + 1 + i;
        pos2.col = 6;
        move.to = pos2;
        game.move(move);
    }
    Position pos;
    pos.row = 0;
    pos.col = 5;
    game.getPossibleMoves(pos);
    return 0;
}
