#include "Game.hpp"
#include "Utils.hpp"

int main()
{
    Game game = Game();
    for (size_t i = 0; i < 5; i++)
    {
        Position pos;
        pos.row = 1 + i;
        pos.col = 5;
        game.getPossibleMoves(pos);
        PlayerMove move;
        move.from = pos;
        Position pos2;
        pos2.row = 1 + 1 + i;
        pos2.col = 5;
        move.to = pos2;
        game.move(move);
        // move.from = pos2;
    }
    // game.getPossibleMoves(pos2);

    // PlayerMove move2;
    // move2.from.row = 2;
    // move2.from.col = 5;
    // move2.to.row = 3;
    // move2.to.col = 5;
    // game.move(move2);
    return 0;
}
