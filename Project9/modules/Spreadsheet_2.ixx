// Spreadsheet_1.ixx에서 코드 중복을 개선한 버전

module;

#include <cstddef>
#include <format>
#include <stdexcept>

export module Spreadsheet_ch9_2;
export import SpreadsheetCell_ch9_1;

using s = size_t;
// size_t는 부호 없는 정수 타입을 보장 플랫폼 따라 구현은 달라질 수 있음

export class Spreadsheet
{
  public:
    Spreadsheet(s width, s height);
    void setCellAt(s x, s y, SpreadsheetCell cell);
    SpreadsheetCell &getCallAt(s x, s y);
    ~Spreadsheet();

  private:
    void verifyCoordinate(s x, s y) const;
    s m_width{};
    s m_height{};
    SpreadsheetCell **m_cells{nullptr};
};

// Definition

/**
 * Spreadsheet 생성자
 * @param width
 * @param height
 */
Spreadsheet::Spreadsheet(s width, s height) : m_width{width}, m_height{height}
{
    m_cells = new SpreadsheetCell *[m_width];
    for (s i{}; i < m_width; i++) {
        m_cells[i] = new SpreadsheetCell[m_height];
    }
}


/**
 * Spreadsheet 소멸자
 */
Spreadsheet::~Spreadsheet()
{
    for (s i{}; i < m_width; i++) {
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
}

void Spreadsheet::verifyCoordinate(s x, s y) const
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

void Spreadsheet::setCellAt(s x, s y, SpreadsheetCell cell)
{
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadsheetCell &Spreadsheet::getCallAt(s x, s y)
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}
