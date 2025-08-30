module;

#include <optional>
#include <string>
#include <string_view>

import DoubleSpreadsheetCell_ch10;
export import SpreadsheetCell_ch10;
export module StringSpreadsheetCell_ch10;

export class StringSpreadsheetCell : public SpreadsheetCell
{
  public:
    StringSpreadsheetCell() = default; // 기본 생성자
    StringSpreadsheetCell(    // 변환 생성자
        DoubleSpreadsheetCell const &cell)
        : m_value{cell.getString()}
    {}

    void set(std::string_view value) override;
    std::string getString() const override;

  private:
    std::optional<std::string> m_value;
};

export StringSpreadsheetCell operator+(StringSpreadsheetCell const &lhs,
                                       StringSpreadsheetCell const rhs)
{
    StringSpreadsheetCell newCell;
    double temp{std::stod(lhs.getString()) + std::stod(rhs.getString())};
    newCell.set(std::to_string(temp));
    return newCell;
}

void StringSpreadsheetCell::set(std::string_view value) { m_value = value; }
std::string StringSpreadsheetCell::getString() const
{
    return m_value.value_or("");
}
