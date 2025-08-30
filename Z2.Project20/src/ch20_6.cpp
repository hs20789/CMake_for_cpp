#include <algorithm>
#include <iostream>
#include <vector>

void populateContainer(auto &cont)
    requires requires(decltype(cont) c, int v) {
        { c.push_back(v) } -> std::same_as<void>;
    }
{
    while (true) {
        std::cout << "Enter a number (0 to quit): ";
        int value;
        std::cin >> value;
        if (value == 0) {
            break;
        }
        cont.push_back(value);
    }
}

int main()
{
    auto printContainer{[](auto &cont) {
        for (auto const &v : cont) {
            std::cout << v << " || ";
        }
        std::cout << std::endl;
    }};

    std::vector<int> vec1, vec2;
    populateContainer(vec1);

    auto cnt = std::count_if(std::cbegin(vec1), std::cend(vec1),
                             [](int i) { return i % 2 == 0; });
    vec2.resize(cnt);
    auto endIterator{std::copy_if(std::cbegin(vec1), std::cend(vec1),
                                  std::begin(vec2),
                                  [](int i) { return i % 2 == 0; })};
    //    vec2.erase(endIterator, std::end(vec2));

    std::cout << "Vector2:" << std::endl;
    printContainer(vec2);

    std::vector<int> vec3, vec4;
    populateContainer(vec3);
    size_t tally{};
    std::cout << "Enter number of elements you want to copy: ";
    std::cin >> tally;

    vec4.resize(tally);
    tally = std::min(tally, std::size(vec3));
    std::copy_n(std::cbegin(vec3), tally, std::begin(vec4));
    std::cout << "Vector4:" << std::endl;
    printContainer(vec4);
}