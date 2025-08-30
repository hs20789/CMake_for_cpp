#include <format>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

template <typename InputIter, typename OuputIter>
void myCopy(InputIter begin, InputIter end, OuputIter target)
{
    for (auto iter{begin}; iter != end; ++iter) {
        *target = *iter;
    }
}

int main()
{
    {
        std::vector<int> vec1;
        for (auto value : std::ranges::istream_view<int>(std::cin) |
                              std::views::take_while(
                                  [](auto const &v) { return v != -1; })) {
            vec1.push_back(value);
        }
        myCopy(vec1.begin(), vec1.end(),
               std::ostream_iterator<int>{std::cout, " "});
    }

    std::cout << std::endl << "> ";

    {
        std::vector<int> values;

        std::ranges::copy(
            std::ranges::istream_view<int>(std::cin) |
                std::views::take_while([](const auto &v) { return v != -1; }),
            back_inserter(values));

        myCopy(std::begin(values), std::end(values),
               std::ostream_iterator<int>{std::cout, " "});
    }
}