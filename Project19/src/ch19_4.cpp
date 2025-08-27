#include <format>
#include <functional>
#include <iostream>
#include <queue>
#include <string>

void func(int num, std::string_view str)
{
    std::cout << std::format("func({}, {})\n", num, str);
}

auto f1{std::bind(func, std::placeholders::_1, "HeonSu")};

int main()
{
    std::plus<int> myPlus;
    int res{myPlus(4, 5)};
    std::cout << res << std::endl;

    std::priority_queue<int, std::vector<int>, std::greater<>> myQueue;
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(2);
    myQueue.push(1);

    while (!myQueue.empty()) {
        std::cout << myQueue.top() << " ";
        myQueue.pop();
    }
    std::cout << '\n';
    f1(16);
}