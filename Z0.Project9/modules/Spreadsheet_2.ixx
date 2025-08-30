// Spreadsheet_1.ixx에서 코드 중복을 개선한 버전

module;

#include <cstddef>
#include <format>
#include <stdexcept>
#include <utility>

export module Spreadsheet_ch9_2;
export import SpreadsheetCell_ch9_1;

using s = size_t;
// size_t는 부호 없는 정수 타입을 보장 플랫폼 따라 구현은 달라질 수 있음

export class Spreadsheet
{
  public:
    Spreadsheet(s width, s height);
    Spreadsheet(Spreadsheet const &src);
    void setCellAt(s x, s y, SpreadsheetCell cell);
    SpreadsheetCell &getCallAt(s x, s y);
    ~Spreadsheet();

    Spreadsheet &operator=(Spreadsheet const &rhs);

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

/**
 * Spreadsheet 복사 생성자(원시 포인터 있기에 정의)
 * @param src
 */
Spreadsheet::Spreadsheet(Spreadsheet const &src)
    : Spreadsheet{src.m_width, src.m_height}
{
    for (s i{}; i < m_width; i++) {
        for (s j{}; j < m_height; j++) {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

/**
 * Spreadsheet 대입 연산자 오버로딩
 * @param rhs
 * @return
 */
Spreadsheet &Spreadsheet::operator=(Spreadsheet const &rhs)
{
    // check myself
    if (this == &rhs) {
        return *this;
    }
    // deallocating original memeory
    for (s i{}; i < (*this).m_width; i++) {
        delete[] (*this).m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;

    // try allocating new memory
    m_width = rhs.m_width;
    m_height = rhs.m_height;

    m_cells = new SpreadsheetCell *[m_width];
    for (s i{}; i < m_width; i++) {
        m_cells[i] = new SpreadsheetCell[m_height];
    }

    // copy data
    for (s i{}; i < m_width; i++) {
        for (s j{}; j < m_height; j++) {
            m_cells[i][j] = rhs.m_cells[i][j];
        }
    }
    return *this;
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
