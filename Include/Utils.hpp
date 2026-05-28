#pragma once

enum class Colors
{
    WHITE,
    BLACK
};
enum class Pieces
{
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING,
    EMPTY
};
struct Position
{
    int row;
    int col;
    int getIndex()
    {
        return row * 8 + col;
    }
    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
};
struct PlayerMove
{
    Position from;
    Position to;
    int getFromIndex ()
    {
        return from.getIndex();
    }
    int getToIndex ()
    {
        return to.getIndex();
    }
};
