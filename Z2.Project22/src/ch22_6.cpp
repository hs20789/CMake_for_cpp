#include <chrono>
#include <format>
#include <iostream>

int main()
{
    std::chrono::year y1{2020};
    using std::chrono_literals::operator""y;
    auto y2{2020y};

    std::chrono::month m1{6};
    auto m2{std::chrono::June};

    using std::chrono_literals::operator""d;
    std::chrono::day d1{22};
    auto d2{22d};

    std::chrono::year_month_day fulldate1{2020y, std::chrono::June, 22d};
    auto fulldate2{2020y / std::chrono::June / 22d};
    auto fulldate3{22d / std::chrono::June / 2020y};

    std::chrono::year_month_day fulldate4{std::chrono::Monday[3] /
                                          std::chrono::June / 2020};
    auto june22{std::chrono::June / 22d};
    auto june22_2020{2020y / june22};

    auto lastDayOfAJune{std::chrono::June / std::chrono::last};
    auto lastDayOfJune2020{2020y / lastDayOfAJune};

    auto lastMondayOfJune2020{2020y / std::chrono::June /
                              std::chrono::Monday[std::chrono::last]};
}