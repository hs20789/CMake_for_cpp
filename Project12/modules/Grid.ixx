module;

#include <cstddef>
#include <format>
#include <optional>
#include <stdexcept>
#include <vector>

export module Grid;

export template <typename T> class Grid
{
  public:
    explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
    virtual ~Grid() = default;                  // 소멸자 1/5
    Grid(Grid const &src) = default;            // 복사 생성자 2/5
    Grid &operator=(Grid const &rhs) = default; // 복사 대입 연산자 3/5
    Grid(Grid &&src) = default;                 // 이동 생성자 4/5
    Grid &operator=(Grid &&src) = default;      // 이동 대입 연산자 5/5

    std::optional<T> &at(size_t x, size_t y);
    std::optional<T> const &at(size_t x, size_t y) const;

    size_t getHeight() const { return m_height; }
    size_t getWidth() const { return m_width; }

    static size_t const DefaultWidth{10};
    static size_t const DefaultHeight{10};

  private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::optional<T>>> m_cells;
    size_t m_width{}, m_height{};
};

template <typename T>
Grid<T>::Grid(size_t width, size_t height) : m_width{height}, m_height{height}
{
    m_cells.resize(m_width);
    for (auto &column : m_cells) {
        column.resize(m_height);
    }
}

template <typename T> void Grid<T>::verifyCoordinate(size_t x, size_t y) const
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

template <typename T>
std::optional<T> const &Grid<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

template <typename T> std::optional<T> &Grid<T>::at(size_t x, size_t y)
{
    return const_cast<std::optional<T> &>(std::as_const(*this).at(x, y));
}
