#pragma once
#include <sstream>
#include <iostream>
#include "Piece.hpp"
class Tile
{
private:
    std::string id;
    Piece figure;
    int row;
    int col;
    bool isWhite;

public:
    void setFigure(Piece piece);
    void setFigureType(Pieces type);
    Piece getFigure() const;
    Tile(int i);
};