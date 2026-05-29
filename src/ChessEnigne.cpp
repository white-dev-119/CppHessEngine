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
    case Pieces::ROOK:{
        size_t squares = 1;
        PossibleMove n_pos;
        PossibleMove s_pos;
        PossibleMove e_pos;
        PossibleMove w_pos;

        bool n_pos_calc = true;
        bool s_pos_calc = true;
        bool e_pos_calc = true;
        bool w_pos_calc = true;

        n_pos.col = figurePosition.col;
        s_pos.col = figurePosition.col;
        e_pos.row = figurePosition.row;
        w_pos.row = figurePosition.row;
        while (squares < 10)
        {
            n_pos.row = figurePosition.row + squares;
            if (n_pos.inBounds() && n_pos_calc){
                Piece piece = board[n_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    n_pos.type = EventType::MOVE;
                    possibleMoves.push_back(n_pos);
                }
                else if (piece.getType() != Pieces::EMPTY || piece.getColor() == figure.getColor())
                {
                    n_pos_calc = false;
                }
                else if(piece.getType() != Pieces::EMPTY || piece.getColor() != figure.getColor())
                {
                    n_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(n_pos);
                }
            }
            s_pos.row = figurePosition.row - squares;
            if (s_pos.inBounds() && s_pos_calc)
            {
                Piece piece = board[s_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    s_pos.type = EventType::MOVE;
                    possibleMoves.push_back(s_pos);
                }
                else if (piece.getType() != Pieces::EMPTY || piece.getColor() == figure.getColor())
                {
                    s_pos_calc = false;
                }
                else if (piece.getType() != Pieces::EMPTY || piece.getColor() != figure.getColor())
                {
                    s_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(s_pos);
                }
            }
            e_pos.col = figurePosition.col + squares;
            if (e_pos.inBounds() && e_pos_calc)
            {
                Piece piece = board[e_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    e_pos.type = EventType::MOVE;
                    possibleMoves.push_back(e_pos);
                }
                else if (piece.getType() != Pieces::EMPTY || piece.getColor() == figure.getColor())
                {
                    e_pos_calc = false;
                }
                else if (piece.getType() != Pieces::EMPTY || piece.getColor() != figure.getColor())
                {
                    e_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(e_pos);
                }
            }
            w_pos.col = figurePosition.col - squares;
            if (w_pos.inBounds() && w_pos_calc)
            {
                Piece piece = board[w_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    w_pos.type = EventType::MOVE;
                    possibleMoves.push_back(w_pos);
                }
                else if (piece.getType() != Pieces::EMPTY || piece.getColor() == figure.getColor())
                {
                    w_pos_calc = false;
                }
                else if (piece.getType() != Pieces::EMPTY || piece.getColor() != figure.getColor())
                {
                    w_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(w_pos);
                }
            }
            ++squares;
        }
        break;
    }
    case Pieces::BISHOP:{
        size_t squares = 1;
        PossibleMove r_u_pos;
        PossibleMove r_d_pos;
        PossibleMove l_u_pos;
        PossibleMove l_d_pos;

        bool r_u_pos_calc = true;
        bool r_d_pos_calc = true;
        bool l_u_pos_calc = true;
        bool l_d_pos_calc = true;

        while (squares < 10)
        {
            r_u_pos.col = figurePosition.col + squares;
            r_u_pos.row = figurePosition.row + squares;

            l_u_pos.col = figurePosition.col - squares;
            l_u_pos.row = figurePosition.row + squares;

            r_d_pos.col = figurePosition.col + squares;
            r_d_pos.row = figurePosition.row - squares;

            l_d_pos.col = figurePosition.col - squares;
            l_d_pos.row = figurePosition.row - squares;

            if(r_u_pos.inBounds() && r_u_pos_calc)
            {
                Piece piece = board[r_u_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    r_u_pos.type = EventType::MOVE;
                    possibleMoves.push_back(r_u_pos);
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() == figure.getColor())
                {
                    r_u_pos_calc = false;
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() != figure.getColor()){
                    r_u_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(r_u_pos);
                    r_u_pos_calc = false;
                }
            }
            if(l_u_pos.inBounds() && l_u_pos_calc)
            {
                Piece piece = board[l_u_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    l_u_pos.type = EventType::MOVE;
                    possibleMoves.push_back(l_u_pos);
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() == figure.getColor())
                {
                    l_u_pos_calc = false;
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() != figure.getColor()){
                    l_u_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(l_u_pos);
                    l_u_pos_calc = false;
                }
            }
            if(r_d_pos.inBounds() && r_d_pos_calc)
            {
                Piece piece = board[r_d_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    r_d_pos.type = EventType::MOVE;
                    possibleMoves.push_back(r_d_pos);
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() == figure.getColor())
                {
                    r_d_pos_calc = false;
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() != figure.getColor()){
                    r_d_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(r_d_pos);
                    r_d_pos_calc = false;
                }
            }
            if(l_d_pos.inBounds() && l_d_pos_calc)
            {
                Piece piece = board[l_d_pos.getIndex()].getFigure();
                if (piece.getType() == Pieces::EMPTY)
                {
                    l_d_pos.type = EventType::MOVE;
                    possibleMoves.push_back(l_d_pos);
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() == figure.getColor())
                {
                    l_d_pos_calc = false;
                }
                else if (piece.getType() != Pieces::EMPTY && piece.getColor() != figure.getColor()){
                    l_d_pos.type = EventType::ATTACK;
                    possibleMoves.push_back(l_d_pos);
                    l_d_pos_calc = false;
                }
            }
            ++squares;
        }

        break;
    }
    case Pieces::KNIGHT:
    case Pieces::QUEEN:
    case Pieces::KING:
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