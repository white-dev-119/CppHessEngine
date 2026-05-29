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
enum EventType
{
    MOVE,
    ATTACK,
    RANK_UP
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
    bool inBounds()
    {
        if (row < 8 && col < 8 && row > -1 && col > -1)
        {
            return true;
        }
        return false;
    }
};
struct PossibleMove: Position 
{
    EventType type;
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

class Event
{};
