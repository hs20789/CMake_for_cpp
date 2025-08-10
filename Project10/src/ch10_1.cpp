#include <iostream>
#include <memory>

class Base
{
  public:
    virtual void someMethod()
    {
        std::cout << "This is Base's version of someMethod\n";
    }
    Base() = default;
    Base(Base const &src) = default;                // 복사 생성자 1/5
    Base(Base &&src) noexcept = default;            // 이동 생성자 2/5
    Base &operator=(Base const &src) = default;     // 복사 대입 연산자 3/5
    Base &operator=(Base &&src) noexcept = default; // 이동 대입 연산자 4/5
    virtual ~Base() = default;                      // 소멸자 5/5

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
    void someMethod() override;
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
    std::unique_ptr<Base> baseSmart2{std::make_unique<Last>()};
    baseSmart2->someMethod();
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

void Last::someMethod()
{
    std::cout << "This is Last's version of someMethod().\n";
}