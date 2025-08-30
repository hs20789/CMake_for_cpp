#include <functional>
#include <iostream>

class Processor
{
  public:
    using CallBack = std::function<int(int)>;

    explicit Processor(CallBack callback) : m_callback{callback} {}
    int operator()(int value) { return m_callback(value); }

  private:
    CallBack m_callback;
};

int Square(int val) { return val * val; }
int TriSquare(int val) { return val * val * val; }

int main()
{
    Processor pro1{Square};
    std::cout << pro1(3) << std::endl;

    Processor pro2{TriSquare};
    std::cout << pro2(3) << std::endl;
}