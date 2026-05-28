#include "Piece.hpp"

Piece::Piece() {
    type = Pieces::EMPTY;
}
Piece::Piece(
    Pieces startSymbol,
    Colors playerColor
):type(startSymbol), color(playerColor) {}
std::string Piece::getSymbol() const {
    switch (type)
    {
    case Pieces::PAWN:
        return "P";
    case Pieces::ROOK:
        return "R";
    case Pieces::BISHOP:
        return "B";
    case Pieces::KNIGHT:
        return "Kn";
    case Pieces::QUEEN:
        return "Q";
    case Pieces::KING:
        return "K";
    case Pieces::EMPTY:
    default:
        return " ";
    }
}
Pieces Piece::getType() const {
    return type;
}
Colors Piece::getColor() const {
    return color;
}
bool Piece::isWhite() const {
    return color == Colors::WHITE;
}
void Piece::moved(){
    has_moved = true;
}
bool Piece::hasMoved() const {
    return has_moved;
}
void Piece::setType(Pieces t_type){
    type = t_type;
}