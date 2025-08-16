#include <iostream>
#include <memory>

import GameBoard;
import Grid;

class ChessPiece : public GamePiece
{
  public:
    std::unique_ptr<GamePiece> clone() const override
    {
        // 복제 생성자를 호출해서 이 인스턴스를 복제한다.
        return std::make_unique<ChessPiece>(*this);
    }
};

void processGameBoard(const GameBoard &board)
{
    const std::unique_ptr<GamePiece> &pawn{board.at(0, 0)};

    // Doesn't compile
    // board.at(1, 2) = std::make_unique<ChessPiece>();
}

int main()
{
    GameBoard chessBoard{8, 8};
    auto pawn{std::make_unique<ChessPiece>()};
    chessBoard.at(0, 0) = std::move(pawn);
    chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
    chessBoard.at(0, 1) = nullptr;

    GameBoard board2;
    board2 = chessBoard;

    processGameBoard(board2);

    std::cout << "\n==========================Generic "
                 "Programming==========================\n";

    Grid<int> myIntGrid;

    Grid<double> myDoubleGrid{11, 11};
    myIntGrid.at(0, 0) = 10;
    int x{myIntGrid.at(0, 0).value_or(0)};

    Grid<int> grid2{myIntGrid};
    Grid<int> anotherIntGrid;
    anotherIntGrid = grid2;
    std::cout << std::format("{}, {}, {}\n", x, grid2.at(0, 0).value_or(0),
                             anotherIntGrid.at(0, 0).value_or(0));


}
