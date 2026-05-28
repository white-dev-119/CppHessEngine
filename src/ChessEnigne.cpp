#include "ChessEngine.hpp"
#include <algorithm>

ChessEngine::ChessEngine()
{
    initializeBoard();
}
std::vector<Tile> ChessEngine::movePiece(PlayerMove move)
{
    int current_index = move.getFromIndex();
    Piece current_piece = board[current_index].getFigure();
    if (current_piece.getType() == Pieces::EMPTY)
    {
        return board;
    }
    int next_pos = move.getToIndex();
    if (validateMove(move))
    {
        board[next_pos].setFigure(current_piece);
        current_piece.moved();
        board[current_index].setFigureType(Pieces::EMPTY);
        registerEvent(EventType::MOVE);
    }
    return board;
}
std::vector<PossibleMove> ChessEngine::getPossibleMoves(Position figurePosition)
{
    Piece figure = board[figurePosition.getIndex()].getFigure();
    std::vector<PossibleMove> possibleMoves = {};
    switch (figure.getType())
    {
    case Pieces::PAWN:{
        size_t moves = 2;
        if (figure.hasMoved())
        {
            moves = 1;
        }
        for (size_t i = 1; i <= moves; i++)
        {
            PossibleMove t_pos;
            t_pos.col = figurePosition.col;
            t_pos.row = figurePosition.row + i;
            t_pos.type = EventType::MOVE;
            Pieces piece = board[t_pos.getIndex()].getFigure().getType();
            if (piece != Pieces::EMPTY)
            {
                break;
            }
            if (piece == Pieces::EMPTY)
            {
                possibleMoves.push_back(t_pos);
            }
        }
        for (int x = -1; x <= 1; x++)
        {
            if (x == 0)
            {
                continue;
            }
            PossibleMove t_pos;
            t_pos.col = figurePosition.col + x;
            t_pos.row = figurePosition.row + 1;
            Pieces piece = board[t_pos.getIndex()].getFigure().getType();
            if(piece != Pieces::EMPTY)
            {
                t_pos.type = EventType::ATTACK;
                possibleMoves.push_back(t_pos);
            }
        }
        break;
    }
    default:
        break;
    }
    return possibleMoves;
}

bool ChessEngine::validateMove(PlayerMove move)
{
    std::vector<PossibleMove> possibleMoves = getPossibleMoves(move.from);
    if (std::find(possibleMoves.begin(), possibleMoves.end(), move.to) != possibleMoves.end())
    {
        return true;
    }
    return false;
}
std::vector<Tile> ChessEngine::getBoard() const
{
    return board;
}
void ChessEngine::initializeBoard()
{
    board.reserve(64);
    for (size_t i = 0; i < 64; i++)
    {
        board.emplace_back(i);
    }
}
void ChessEngine::registerEvent(EventType type)
{
    switch (type)
    {
    case EventType::MOVE:
        break;
    default:
        break;
    }
}