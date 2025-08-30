#include <forward_list>
#include <iostream>
#include <iterator>

int main()
{
    std::forward_list<int> list1{5, 6};
    std::forward_list list2{1, 2, 3, 4};
    std::forward_list<int> list3{7, 8, 9};

    list1.splice_after(list1.before_begin(), list2);
    list1.push_front(0);

    auto iter{list1.before_begin()};
    auto iterTemp{iter};

    while (++iterTemp != std::end(list1)) {
        ++iter;
    }

    list1.insert_after(iter, std::cbegin(list3), std::cend(list3));
    for (auto &i : list1) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}