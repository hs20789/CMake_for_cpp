// Spreadsheet_2.ixx에서 대입 연산자 오버로딩을 개선한 버전

module;

#include <cstddef>
#include <format>
#include <stdexcept>
#include <utility>

export module Spreadsheet_ch9_3;
export import SpreadsheetCell_ch9_1;

using s = size_t;
// size_t는 부호 없는 정수 타입을 보장 플랫폼 따라 구현은 달라질 수 있음

export class Spreadsheet
{
  public:
    Spreadsheet() = delete;                            // 디폴트 생성자
    Spreadsheet(s width, s height);                     // 매개변수 생성자
    Spreadsheet(Spreadsheet const &src);                // 복사 생성자 1/5
    Spreadsheet(Spreadsheet &&src) noexcept;            // 이동 생성자 2/5
    Spreadsheet &operator=(Spreadsheet &&rhs) noexcept; // 이동 대입 연산자 3/5
    Spreadsheet &operator=(Spreadsheet const &rhs);     // 복사 대입 연산자 4/5
    ~Spreadsheet();                                     // 소멸자 5/5

    void setCellAt(s x, s y, SpreadsheetCell cell);
    SpreadsheetCell &getCellAt(s x, s y);
    void swap(Spreadsheet &other) noexcept;

  private:
    s m_width{};
    s m_height{};
    SpreadsheetCell **m_cells{nullptr};

    // 헬퍼 함수
    void verifyCoordinate(s x, s y) const;
};

export void swap(Spreadsheet &first, Spreadsheet &second) noexcept
{
    first.swap(second);
}

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
    Spreadsheet temp{rhs}; // 모든 작업을 임시 인스턴스에서 처리
    swap(temp);            // 익셉션을 던지지 않는 연산에서만 작업을 처리
    return *this;
}

/**
 * Spreadsheet 이동 생성자
 * @param src
 */
Spreadsheet::Spreadsheet(Spreadsheet &&src) noexcept { ::swap(*this, src); }

/**
 * Spreadsheet 이동 대입 연산자
 * @param rhs
 * @return
 */
Spreadsheet &Spreadsheet::operator=(Spreadsheet &&rhs) noexcept
{
    if (this != &rhs) {
        ::swap(*this, rhs);
        return *this;
    }
    return *this;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/**
 * 복제 후 맞바꾸기 구문을 위한 swap 멤버 함수
 * @param other
 */
void Spreadsheet::swap(Spreadsheet &other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void Spreadsheet::setCellAt(s x, s y, SpreadsheetCell cell)
{
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadsheetCell &Spreadsheet::getCellAt(s x, s y)
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// 헬퍼 함수
///////////////////////////////////////

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
