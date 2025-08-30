module;

#include <charconv>
#include <compare>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

export module SpreadsheetCell_15;

export class SpreadsheetCell
{
  public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue) : m_value{initialValue} {}
    explicit SpreadsheetCell(std::string_view initialValue)
        : m_value{stringToDouble(initialValue)}
    {}

    void set(double value) { m_value = value; }
    void set(std::string_view value) { m_value = stringToDouble(value); }

    inline double getValue() const { return m_value; }
    inline std::string getString() const { return doubleToString(m_value); }

    static std::string doubleToString(double value)
    {
        return std::to_string(value);
    }
    static double stringToDouble(std::string_view value)
    {
        double number{0};
        std::from_chars(value.data(), value.data() + value.size(), number);
        return number;
    }

    SpreadsheetCell &operator+=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator-=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator*=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator/=(const SpreadsheetCell &rhs);

    [[nodiscard]] auto operator<=>(const SpreadsheetCell &) const = default;

    SpreadsheetCell operator-() const;
    SpreadsheetCell &operator++();   // Prefix
    SpreadsheetCell operator++(int); // Postfix
    SpreadsheetCell &operator--();   // Prefix
    SpreadsheetCell operator--(int); // Postfix

  private:
    double m_value{0};
};

export SpreadsheetCell operator+(const SpreadsheetCell &lhs,
                                 const SpreadsheetCell &rhs)
{
    auto result{lhs}; // Local copy
    result += rhs;    // Forward to +=()
    return result;
}

export SpreadsheetCell operator-(const SpreadsheetCell &lhs,
                                 const SpreadsheetCell &rhs)
{
    auto result{lhs}; // Local copy
    result -= rhs;    // Forward to -=()
    return result;
}

export SpreadsheetCell operator*(const SpreadsheetCell &lhs,
                                 const SpreadsheetCell &rhs)
{
    auto result{lhs}; // Local copy
    result *= rhs;    // Forward to *=()
    return result;
}

export SpreadsheetCell operator/(const SpreadsheetCell &lhs,
                                 const SpreadsheetCell &rhs)
{
    auto result{lhs}; // Local copy
    result /= rhs;    // Forward to /=()
    return result;
}

export std::ostream &operator<<(std::ostream &ostr, SpreadsheetCell const &cell)
{
    ostr << "Cell's Value: " << cell.getValue();
    return ostr;
}

export std::istream &operator>>(std::istream &istr, SpreadsheetCell &cell)
{
    double value{};
    istr >> value;
    cell.set(value);
    return istr;
}

export std::ofstream &operator<<(std::ofstream &ofstr,
                                 SpreadsheetCell const &cell)
{
    ofstr << "Cell's Value: " << cell.getValue();
    return ofstr;
}

export std::ifstream &operator>>(std::ifstream &ifstr, SpreadsheetCell &cell)
{
    double value{};
    ifstr >> value;
    cell.set(value);
    return ifstr;
}

// 클래스 메서드 연산자 오버로드
SpreadsheetCell SpreadsheetCell::operator-() const
{
    return SpreadsheetCell{-getValue()};
}

SpreadsheetCell &SpreadsheetCell::operator++()
{
    set(getValue() + 1);
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator++(int)
{
    auto oldCell{*this};
    ++(*this);
    return oldCell;
}

SpreadsheetCell &SpreadsheetCell::operator--()
{
    set(getValue() - 1);
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator--(int)
{
    auto oldCell{*this};
    --(*this);
    return oldCell;
}

SpreadsheetCell &SpreadsheetCell::operator+=(const SpreadsheetCell &rhs)
{
    set(getValue() + rhs.getValue());
    return *this;
}

SpreadsheetCell &SpreadsheetCell::operator-=(const SpreadsheetCell &rhs)
{
    set(getValue() - rhs.getValue());
    return *this;
}

SpreadsheetCell &SpreadsheetCell::operator*=(const SpreadsheetCell &rhs)
{
    set(getValue() * rhs.getValue());
    return *this;
}

SpreadsheetCell &SpreadsheetCell::operator/=(const SpreadsheetCell &rhs)
{
    if (rhs.getValue() == 0) {
        throw std::invalid_argument{"Divide by zero."};
    }
    set(getValue() / rhs.getValue());
    return *this;
}
