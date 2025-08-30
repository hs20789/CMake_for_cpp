// module;

// #include <charconv>
// #include <optional>
// #include <string>
// #include <string_view>

// import SpreadsheetCell_ch10;
// export module DoubleSpreadsheetCell_ch10;

// export class DoubleSpreadsheetCell : public SpreadsheetCell
// {
//   public:
//     virtual void set(double value);
//     void set(std::string_view value) override;
//     std::string getString() const override;

//   private:
//     std::optional<double> m_value;
//     // 헬퍼 멤버 함수
//     static std::string doubleToString(double value);
//     static double stringToDouble(std::string_view value);
// };

// void DoubleSpreadsheetCell::set(double value) { m_value = value; }
// void DoubleSpreadsheetCell::set(std::string_view value)
// {
//     m_value = stringToDouble(value);
// }
// std::string DoubleSpreadsheetCell::getString() const
// {
//     return m_value.has_value() ? doubleToString(*m_value) : "";
// }

// std::string DoubleSpreadsheetCell::doubleToString(double value)
// {
//     return std::to_string(value);
// }

// double DoubleSpreadsheetCell::stringToDouble(std::string_view value)
// {
//     double number{};
//     std::from_chars(value.data(), value.data() + value.size(), number);
//     return number;
// }
