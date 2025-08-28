#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void removeEmptyremoveEmptyStringsWithoutAlgorithms(
    std::vector<std::string> strings)
{
    for (auto iter{strings.begin()}; iter != strings.end();) {
        if (iter->empty())
            iter = strings.erase(iter);
        else
            ++iter;
    }
}

void removeEmptyStrings(std::vector<std::string> strings)
{
    auto it{std::remove_if(std::begin(strings), std::end(strings),
                           [](std::string const &str) { return str.empty(); })};
    strings.erase(it, std::end(strings));
}

int main()
{
    auto printCont{[](auto const &cont) {
        for (auto &v : cont) {
            std::cout << v << " || ";
        }
        std::cout << std::endl;
    }};
    std::vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Before reverse values:\n";
    printCont(values);

    std::reverse(std::begin(values), std::end(values));
    std::cout << "After reverse values:\n";
    printCont(values);

    std::vector vec{11, 22, 33, 44, 55};
    printCont(vec);

    auto newEnd{std::shift_left(std::begin(vec), std::end(vec), 2)};
    vec.erase(newEnd, std::end(vec));
    printCont(vec);

    auto newBegin{std::shift_right(std::begin(vec), std::end(vec), 2)};
    vec.erase(std::begin(vec), newBegin);
    printCont(vec);
}