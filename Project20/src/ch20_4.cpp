#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

int main()
{
    std::vector vec2{1, 1, 1, 1};
    if (std::all_of(std::cbegin(vec2), std::cend(vec2),
                    [](int i) { return i == 1; })) {
        std::cout << "All elements are == 1" << std::endl;
    } else {
        std::cout << "Not all elements are == 1" << std::endl;
    }

    std::vector vec3{0, 0, 1, 0};
    if (std::any_of(std::cbegin(vec3), std::cend(vec3),
                    [](int i) { return i == 1; })) {
        std::cout << "At least one element == 1\n";
    } else {
        std::cout << "No elements are == 1\n";
    }

    std::vector<int> vec4{0, 0, 0, 0};
    if (std::none_of(std::cbegin(vec4), std::cend(vec4),
                     [](int i) { return i == 1; })) {
        std::cout << "All elements are != 1" << std::endl;
    } else {
        std::cout << "Some elements are == 1" << std::endl;
    }

    std::vector<std::string> v = {"a", "bb", "ccc"};

    for (auto s : v) { /* 복사본 */
    }
    for (auto &s : v) {
        s += "!";
    } // 원소 수정
    for (const auto &s : v) { /* 읽기 전용, 복사 없음 */
    }

    // 범용/프로시 이터레이터 안전 패턴
    for (auto &&s : v) { /* lvalue면 &, rvalue면 &&로 */
        std::cout << s << " | ";
    }
    std::cout << std::endl;

    std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int value{3};
    auto tally{std::count_if(std::cbegin(values), std::cend(values),
                             [value](int i) { return i > value; })};
    std::cout << std::format("Found {} values > {}.", tally, value)
              << std::endl;

    int callCounter{};
    tally = std::count_if(std::cbegin(values), std::cend(values),
                          [value, &callCounter](int i) {
                              ++callCounter;
                              return i > value;
                          });
    std::cout << "The lambda expression was calledd " << callCounter
              << " times.\n";
    std::cout << std::format("Found {} values > {}.\n", tally, value);
}