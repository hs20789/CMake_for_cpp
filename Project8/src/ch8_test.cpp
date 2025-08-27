#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

class Foo
{
  public:
    Foo() = default;
    Foo(Foo const& src) = delete;
    Foo(Foo &src) = default;
    Foo(int value) : m_value(value) {};
    

    int getValue() const;
    void setValue(int value);

  private:
    int m_value{10};
};

int main()
{
    using std::literals::string_literals::operator ""s;
    Foo f1{};


    Foo f2 = f1;
    std::cout << f2.getValue() << '\n';
}

int Foo::getValue() const { return this->m_value; }

void Foo::setValue(int value) { this->m_value = value; }
