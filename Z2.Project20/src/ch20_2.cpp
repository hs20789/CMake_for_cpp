#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <span>
#include <string>
#include <vector>

int main()
{
    std::vector myVector{5, 6, 9, 8, 8, 3};
    auto beginIter{std::cbegin(myVector)};
    auto endIter{std::cend(myVector)};

    auto it{std::find_if_not(beginIter, endIter, [](int i) { return i < 8; })};
    if (it != endIter) {
        std::cout << "First element not < 8 is " << *it << std::endl;
    }
    it = std::adjacent_find(beginIter, endIter);
    if (it != endIter) {
        std::cout << "FOund two conecutive equal elements with value " << *it
                  << std::endl;
    }

    std::vector targets{8, 9};
    it = std::find_first_of(beginIter, endIter, std::cbegin(targets),
                            std::cend(targets));
    if (it != endIter) {
        std::cout << "Found one of 8 or 9: " << *it << std::endl;
    }

    std::vector sub{8, 3};
    if (it = std::search(beginIter, endIter, std::cbegin(sub), std::cend(sub));
        it == endIter) {
        std::cout << "Found subsequence {8, 3}\n";
    } else {
        std::cout << "Unable to find subsequence {8, 3}\n";
    }

    if (auto it2{std::find_end(beginIter, endIter, std::cbegin(sub),
                               std::cend(sub))};
        it != it2) {
        std::cout << "Error: search and find_end found different subsequences "
                  << "even though there is only one match.\n";
    }

    if (it = std::search_n(beginIter, endIter, 2, 8); it != endIter) {
        std::cout << "Found two consecutive 8s\n";
    } else {
        std::cout << "Unable to find two consecutive 8s\n";
    }

    std::string text{"This is the haystack to search a needle in."};
    std::string toSearchFor{"needle"};

    std::boyer_moore_horspool_searcher searcher{std::cbegin(toSearchFor),
                                                std::cend(toSearchFor)};
    if (auto result{std::search(std::cbegin(text), std::cend(text), searcher)};
        result != std::cend(text)) {
        std::cout << "Found the needle\n";
    } else {
        std::cout << "Needle not found\n";
    }
}