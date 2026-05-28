#pragma once
#include <string>
#include "Utils.hpp"

class Piece
{
private:
    Pieces type;
    Colors color;
    bool has_moved;

public:
    Piece();
    Piece(Pieces startType, Colors playerColor);
    std::string getSymbol() const;
    Pieces getType() const;
    Colors getColor() const;
    bool isWhite() const;
    void moved();
    bool hasMoved();
    void setType(Pieces t_type);
};