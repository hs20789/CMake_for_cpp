#include <iostream>
#include <random>
#include <string>

int main()
{
    std::string answer;
    std::cout << "Do you want to throw a dice? (Enter 'yes' or 'no'): ";
    while (std::cin >> answer) {
        if (answer == "yes")
            break;
        else if (answer == "no") {
            std::cout << "Bye~\n";
            return 1;
        } else
            std::cout << "Please Enter 'yes' or 'no': ";
    }

    std::random_device seeder;
    auto const seed{seeder.entropy() != 0 ? seeder() : std::time(nullptr)};
    std::mt19937 engind{static_cast<std::mt19937::result_type>(seed)};

    std::uniform_int_distribution<int> distribution{1, 6};
    // 실제 난수를 뽑으려면 의사난수 엔진을 인수로 넘겨 호출해야 한다.
    for (int i{1}; i < 3; ++i) {
        std::cout << std::format("{}st result of dice: {}\n", i,
                                 distribution(engind));
    }
    std::cout << "Thank you to throw a dice!! Good Bye~" << std::endl;
    //
}