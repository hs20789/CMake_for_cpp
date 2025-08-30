#include <iostream>
#include <memory>

auto basicLambda{[] { std::cout << "Hello from Lambda\n"; }};

int main()
{
    basicLambda();
    auto parameterLambda{
        [](int value) { std::cout << "The value is: " << value << std::endl; }};
    parameterLambda(42);

    auto returningLambda{[](int a, int b) -> int { return a + b; }};
    int sum{returningLambda(11, 22)};
    std::cout << sum << '\n';

    double data{1.23};
    auto capturingLambda{[data] { std::cout << "Data = " << data << '\n'; }};
    capturingLambda();

    double pi{3.1415};
    auto myLambda{[myCapther = "Pi: ", pi] {
        std::cout << myCapther << pi << std::endl;
    }};
    myLambda();

    auto myPtr{std::make_unique<double>(3.1415)};
    auto myLambda2{[p = std::move(myPtr)] { std::cout << *p << '\n'; }};
    myLambda2();
}
