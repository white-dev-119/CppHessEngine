#include "Game.hpp"
#include "Utils.hpp"

int main(int argc, char const *argv[])
{
    Game game = Game();
    PlayerMove move;
    move.from.row = 1;
    move.from.col = 5;
    move.to.row = 2;
    move.to.col = 5;
    game.move(move);
    PlayerMove move2;
    move2.from.row = 2;
    move2.from.col = 5;
    move2.to.row = 3;
    move2.to.col = 5;
    game.move(move2);
    return 0;
}
