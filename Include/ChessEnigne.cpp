#include "ChessEngine.hpp"
#include <algorithm>

ChessEngine::ChessEngine()
{
    initializeBoard();
}
std::vector<Tile> ChessEngine::movePiece(PlayerMove move)
{
    int current_index = move.getFromIndex();
    if (board[current_index].getFigure().getType() == Pieces::EMPTY)
    {
        return board;
    }
    int next_pos = move.getToIndex();
    if (validateMove(move))
    {
        board[next_pos].setFigure(board[current_index].getFigure());
        board[current_index].setFigureType(Pieces::EMPTY);
    }
    return board;
}
std::vector<Position> ChessEngine::getPossibleMoves(Position figurePosition)
{
    Piece figure = board[figurePosition.getIndex()].getFigure();
    std::vector<Position> possibleMoves = {};
    switch (figure.getType())
    {
    case Pieces::PAWN:
        if (!figure.hasMoved())
        {
            if (figure.isWhite())
            {
                for (size_t i = 1; i < 3; i++)
                {
                    Position t_pos;
                    t_pos.col = figurePosition.col;
                    t_pos.row = figurePosition.row + i;
                    if(board[t_pos.getIndex()].getFigure().getType() == Pieces::EMPTY){
                        possibleMoves.push_back(t_pos);
                    }
                }
            }
        }
        else
        {
            if (figure.isWhite())
            {
                Position t_pos;
                t_pos.col = figurePosition.col;
                t_pos.row = figurePosition.row + 1;
                if (board[t_pos.getIndex()].getFigure().getType() == Pieces::EMPTY)
                {
                    possibleMoves.push_back(t_pos);
                }
            }
            std::cout << "Moved" << std::endl;
        }
        break;
    default:
        break;
    }
    return possibleMoves;
}

bool ChessEngine::validateMove(PlayerMove move)
{
    std::vector<Position> possibleMoves = getPossibleMoves(move.from);
    if (std::find(possibleMoves.begin(), possibleMoves.end(), move.to) != possibleMoves.end())
    {
        std::cout << "Found" << std::endl;
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