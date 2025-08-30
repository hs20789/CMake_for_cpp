#include <iostream>
#include <iterator>
#include <vector>

class MoveableClass
{
  public:
    MoveableClass() { std::cout << "Default ctor\n"; }
    MoveableClass(MoveableClass const &src) { std::cout << "Copy ctor\n"; }
    MoveableClass(MoveableClass &&src) noexcept { std::cout << "Move ctor\n"; }
    MoveableClass &operator=(MoveableClass const &src)
    {
        std::cout << "Copy assignment operator\n";
    }
    MoveableClass &operator=(MoveableClass &&src) noexcept
    {
        std::cout << "Move assignment operator\n";
    }
};

int main()
{
    std::vector<MoveableClass> vecSource;
    MoveableClass mc;
    vecSource.push_back(mc);
    vecSource.push_back(mc);
    //

    std::cout << "=======================================\n";

    std::vector<MoveableClass> vecOne{std::cbegin(vecSource),
                                      std::cend(vecSource)};

    std::cout << "=======================================\n";

    std::vector<MoveableClass> vecTwo{
        std::make_move_iterator(std::begin(vecSource)),
        std::make_move_iterator(std::end(vecSource))};

    // 다른 객체로 이동시킨 객체는 더 이상 사용해서는 안된다 //
}