#include "Game.hpp"

int main()
{
    Game game = Game();
    int col = 3;
    for (size_t i = 0; i < 5; i++)
    {
        Position pos;
        pos.row = 1 + i;
        pos.col = col;
        game.renderPossibleMoves(pos);
        PlayerMove move;
        move.from = pos;
        Position pos2;
        pos2.row = 1 + 1 + i;
        pos2.col = col;
        move.to = pos2;
        game.move(move);
    }
    Position pos1;
    Position pos2;
    pos1.row = 1;
    pos1.col = 2;
    pos2.row = 1;
    pos2.col = 4;
    Position pos3;
    Position pos4;
    pos3.row = 2;
    pos3.col = 2;
    pos4.row = 2;
    pos4.col = 4;

    PlayerMove move1;
    PlayerMove move2;
    move1.from = pos1;
    move2.from = pos2;
    move1.to = pos3;
    move2.to = pos4;
    game.move(move1);
    game.move(move2);

    Position pos;
    Position epos;
    pos.row = 0;
    pos.col = 3;
    epos.row = 2;
    epos.col = 5;
    game.renderPossibleMoves(pos);
    PlayerMove move;
    move.from = pos;
    move.to = epos;
    game.move(move);
    game.renderPossibleMoves(epos);
    return 0;
}
