module;

#include <cstddef>
#include <format>
#include <memory>
#include <stdexcept>
#include <utility>

module GameBoard;

using s = std::size_t;

GameBoard::GameBoard(s width, s height) : m_width{width}, m_height{height}
{
    m_cells.resize(m_width);
    for (auto &column : m_cells) {
        column.resize(m_height);
    }
}

GameBoard::GameBoard(GameBoard const &src)
    : GameBoard{src.m_width, src.m_height}
{
    // 메모리 할당을 비복제 생성자에 위임
    // 그러고 나서 데이터를 복제
    for (s i{}; i < m_width; i++) {
        for (s j{}; j < m_height; j++) {
            if (src.m_cells[i][j]) {
                m_cells[i][j] = src.m_cells[i][j]->clone();
            }
        }
    }
}

void GameBoard::verifyCoordinate(s x, s y) const
{
    if (x >= m_width) {
        throw std::out_of_range{
            std::format("{} must be less than {}.", x, m_width)};
    }
    if (y >= m_height) {
        throw std::out_of_range{
            std::format("{} must be less than {}.", y, m_height)};
    }
}

void GameBoard::swap(GameBoard &other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void swap(GameBoard &first, GameBoard &second) noexcept { first.swap(second); }

GameBoard &GameBoard::operator=(GameBoard const &rhs)
{
    // 복제 후 맞바꾸기
    GameBoard temp{rhs};
    swap(temp);
    return *this;
}

std::unique_ptr<GamePiece> const &GameBoard::at(s x, s y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

std::unique_ptr<GamePiece> &GameBoard::at(s x, s y)
{
    return const_cast<std::unique_ptr<GamePiece> &>(
        std::as_const(*this).at(x, y));
}
