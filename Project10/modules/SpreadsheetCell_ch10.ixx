module;

#include <string>
#include <string_view>

export module SpreadsheetCell_ch10;

export class SpreadsheetCell
{
  public:
    virtual ~SpreadsheetCell() = default;         // 소멸자 1/5
    virtual void set(std::string_view value) = 0; // 순수 가상 메서드
    virtual std::string getString() const = 0;    // 순수 가상 메서드
};