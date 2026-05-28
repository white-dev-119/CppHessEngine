#include "Tile.hpp"
Tile::Tile(int i) {
    int SIZE = 8;
    row = i / SIZE;
    if (i > SIZE)
    {
        col = ((SIZE - i) * -1) % SIZE;
    }
    else
    {
        col = i % SIZE;
    }
    std::ostringstream ss;
    ss << "Row: " << row << " " << "Col: " << col << std::endl;
    id = ss.str();
    isWhite = col % 2 == row % 2;

    Colors playerColor = Colors::WHITE;
    if (row > 6)
    {
        playerColor = Colors::BLACK;
    }

    if (row == 1 || row == 6)
    {
        figure = Piece(Pieces::PAWN, playerColor);
    }
    else if (row == 0 || row == 7)
    {
        if (col == 0 || col == 7)
        {
            figure = Piece(Pieces::ROOK, playerColor);
        }
        else if (col == 1 || col == 6)
        {
            figure = Piece(Pieces::KNIGHT, playerColor);
        }
        else if (col == 2 || col == 5)
        {
            figure = Piece(Pieces::BISHOP, playerColor);
        }
        else if (col == 4)
        {
            figure = Piece(Pieces::KING, playerColor);
        }
        else if (col == 3)
        {
            figure = Piece(Pieces::QUEEN, playerColor);
        }
    }
    else
    {
        figure = Piece();
    }
}
void Tile::setFigure(Piece piece)
{
    piece.moved();
    figure = piece;
}
void Tile::setFigureType(Pieces type)
{
    figure.setType(type);
}
Piece Tile::getFigure() const
{
    return figure;
}