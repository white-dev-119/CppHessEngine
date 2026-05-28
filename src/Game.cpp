#include "Game.hpp"

Game::Game(ChessEngine &engine)
{
    running = true;
    engine = engine;
    drawBoard(engine.getBoard());
}
Game::Game()
{
    running = true;
    engine = ChessEngine();
    drawBoard(engine.getBoard());
}
void Game::move(PlayerMove move)
{
    drawBoard(engine.movePiece(move));
}
void Game::getPossibleMoves(Position pos) {
    drawBoard(engine.getBoard(), engine.getPossibleMoves(pos));
};
void Game::drawBoard(const std::vector<Tile> &board)
{
    const int CELL_WIDTH = 8;
    for (int row = 8; row >= 1; --row)
    {
        std::cout << std::setw(CELL_WIDTH) << row;
        for (int col = 0; col < 8; ++col)
        {
            int index = (row - 1) * 8 + col;
            std::cout << std::setw(CELL_WIDTH) << board[index].getFigure().getSymbol();
        }
        std::cout << '\n';
    }
    std::cout << std::setw(CELL_WIDTH) << " ";
    for (int col = 0; col < 8; ++col)
    {
        char letter = static_cast<char>('a' + col);
        std::cout << std::setw(CELL_WIDTH) << letter;
    }
    std::cout << "\n\n";
}
void Game::drawBoard(const std::vector<Tile> &board, const std::vector<PossibleMove> &possible_positions)
{
    const int CELL_WIDTH = 8;
    std::vector<int> possible_position_indexes = {};
    for (auto i : possible_positions)
    {
        possible_position_indexes.push_back(i.getIndex());
    }

    for (int row = 8; row >= 1; --row)
    {
        std::cout << std::setw(CELL_WIDTH) << row;
        for (int col = 0; col < 8; ++col)
        {
            int index = (row - 1) * 8 + col;
            if (std::find(possible_position_indexes.begin(), possible_position_indexes.end(), index) != possible_position_indexes.end())
            {
                std::cout << std::setw(CELL_WIDTH) << "X";
            }
            else
            {
                std::cout << std::setw(CELL_WIDTH) << board[index].getFigure().getSymbol();
            }
        }
        std::cout << '\n';
    }
    std::cout << std::setw(CELL_WIDTH) << " ";
    for (int col = 0; col < 8; ++col)
    {
        char letter = static_cast<char>('a' + col);
        std::cout << std::setw(CELL_WIDTH) << letter;
    }
    std::cout << "\n\n";
}