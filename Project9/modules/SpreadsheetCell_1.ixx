module;

#include <charconv>
#include <string>
#include <string_view>

export module SpreadsheetCell_ch9_1;
//
// 저장 데이터는 항상 double 일관성 보장,
// 숫자 연산 등에서 오류를 줄임
// 문자열 입력 /출력은 편의성 차원
// 외부(사용자, 파일 등) 와 주고받을 때 다양한 포맷을 허용
// 그러나 실제 데이터의 저장 및 처리 일관성은 double 타입에 집중

export class SpreadsheetCell
{
  public:
    // ctor
    SpreadsheetCell() = default;
    SpreadsheetCell(SpreadsheetCell const &src) = default;
    SpreadsheetCell(double initialValue) : m_value{initialValue} {};
    explicit SpreadsheetCell(std::string_view initialValue)
        : SpreadsheetCell{stringToDouble(initialValue)} {};

    void set(double value);
    double getValue() const;

    void set(std::string_view inString);
    std::string getString() const;

  private:
    double m_value{};
    mutable size_t m_numAccesses{}; // 로깅 기록을 위한 변수
    //////////////////////// 헬퍼 함수 ////////////////////////
    static std::string doubleToString(double value);
    static double stringToDouble(std::string_view inString);
};

void SpreadsheetCell::set(double value) { m_value = value; }
double SpreadsheetCell::getValue() const
{
    m_numAccesses++;
    return m_value;
}

void SpreadsheetCell::set(std::string_view inString)
{
    this->m_value = stringToDouble(inString);
}
std::string SpreadsheetCell::getString() const
{
    m_numAccesses++;
    return doubleToString(this->m_value);
}

std::string SpreadsheetCell::doubleToString(double value)
{
    return std::to_string(value);
}
double SpreadsheetCell::stringToDouble(std::string_view value)
{
    double number{};
    std::from_chars(value.data(), value.data() + value.size(), number);
    return number;
}
