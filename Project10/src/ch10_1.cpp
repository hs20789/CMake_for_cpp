#include <iostream>
#include <memory>

class Base
{
  public:
    virtual void someMethod()
    {
        std::cout << "This is Base's version of someMethod\n";
    }

  protected:
    int m_protectedInt{};

  private:
    int m_privateInt{};
};

class Derived : public Base
{
  public:
    virtual void someOtherMethod();
    void someMethod() override;
};

class Last final : public Derived
{
  public:
    void someMethod() override { std::cout << "Last Class\n"; }
};

int main()
{
    std::cout
        << "1. =========================================================\n";
    Derived myDerived;
    myDerived.someOtherMethod();
    myDerived.someMethod();

    std::cout
        << "2. =========================================================\n";
    Base myBase;
    myBase.someMethod();
    // myBase.someOtherMethod(); -> 오류

    std::cout
        << "3. =========================================================\n";
    std::unique_ptr<Base> baseSmart{std::make_unique<Derived>()};
    Base *base{new Derived};
    baseSmart->someMethod();
    base->someMethod();
}

void Derived::someOtherMethod()
{
    std::cout << "I can access base class data member m_pretectdeInt.\n";
    std::cout << "Its value is " << m_protectedInt << std::endl;
}

void Derived::someMethod()
{
    std::cout << "This is Derived's version of someMethod().\n";
}
