module;

#include <cstddef>
#include <format>
#include <stdexcept>

export module Spreadsheet_ch9_1;
export import SpreadsheetCell_ch9_1;

using s = size_t;
// size_t는 부호 없는 정수 타입을 보장 플랫폼 따라 구현은 달라질 수 있음

export class Spreadsheet
{
  public:
    /**
     * Spreadsheet 생성자
     * @param width
     * @param height
     */
    Spreadsheet(s width, s height);
    void setCellAt(s x, s y, SpreadsheetCell cell);
    SpreadsheetCell &getCallAt(s x, s y);

  private:
    bool inRange(s value, s upper) const;
    s m_width{};
    s m_height{};
    SpreadsheetCell **m_cells{nullptr};
};

// Definition

Spreadsheet::Spreadsheet(s width, s height) : m_width{width}, m_height{height}
{
    m_cells = new SpreadsheetCell *[m_width];
    for (s i{}; i < m_width; i++) {
        m_cells[i] = new SpreadsheetCell[m_height];
    }
}

void Spreadsheet::setCellAt(s x, s y, SpreadsheetCell cell)
{
    if (!inRange(x, m_width)) {
        throw std::out_of_range{
            std::format("{} must be less than {}", x, m_width)};
    }
    if (!inRange(y, m_height)) {
        throw std::out_of_range{
            std::format("{} must be less than {}", y, m_height)};
    }
    m_cells[x][y] = cell;
}

SpreadsheetCell &Spreadsheet::getCallAt(s x, s y)
{
    if (!inRange(x, m_width)) {
        throw std::out_of_range{
            std::format("{} must be less than {}", x, m_width)};
    }
    if (!inRange(y, m_height)) {
        throw std::out_of_range{
            std::format("{} must be less than {}", y, m_height)};
    }
    return m_cells[x][y];
}

// setCellAt 과 getCellAt에서 코드 중복이 있기에 코드 중복을 피하는게 좋다. 이를
// 개선한 버전은 Spreadsheet_2.ixx이다.
