#include <deque>
#include <format>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

template <typename T> void printOut(T const &container)
{
    for (auto &v : container) {
        std::cout << std::format("{:<15}|", v);
    }
    std::cout << std::endl;
}

std::list<std::string>
getTotalEnrollment(std::vector<std::list<std::string>> const &courseStudents,
                   std::list<std::string> const &droppedStudents);

int main()
{
    std::vector<int>{1, 2, 3, 2, 1, 2, 4, 5};
    //
    std::list<std::string> dictionary{"aardvark", "ambulance"};
    std::list<std::string> bWords{"bathos", "balderdash"};

    dictionary.push_back("canticle");
    dictionary.push_back("consumerism");

    if (!bWords.empty()) {
        std::list<std::string>::const_iterator iterLastB{--(std::cend(bWords))};
        std::list<std::string>::const_iterator it{std::cbegin(dictionary)};

        for (; it != iterLastB; ++it) {
            if (*it > *iterLastB) {
                break;
            }
        }
        dictionary.splice(it, bWords);
    }
    printOut(dictionary);
}

std::list<std::string>
getTotalEnrollment(std::vector<std::list<std::string>> const &courseStudents,
                   std::list<std::string> const &droppedStudents)
{
    std::list<std::string> allStudents;

    for (auto &lst : courseStudents) {
        allStudents.insert(std::cend(allStudents), std::cbegin(lst),
                           std::cend(lst));
    }
    allStudents.sort();

    allStudents.unique();

    for (auto &str : droppedStudents) {
        allStudents.remove(str);
    }
    return allStudents;
}
