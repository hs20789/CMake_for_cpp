#include <iostream>
#include <string_view>

class Base
{
  public:
    virtual ~Base() = default;
    Base() { std::cout << "Base's Default ctor\n"; };
    Base(std::string_view str) { std::cout << "Base's string_view ctor\n"; };
    Base(float f) { std::cout << "Base's float ctor\n"; }
    virtual void someMethod() {};
    virtual void overload() { std::cout << "Base's overload()\n"; }
    virtual void overload(int i) { std::cout << "Base's overload(int i)\n"; }
};

class Derived : public Base
{
  public:
    using Base::overload;
    Derived(int i) { std::cout << "Derived's int ctor\n"; };
    using Base::Base;
    Derived(float f) { std::cout << "Derived's float ctor\n"; }
    using Base::someMethod;            // 베이스 클래스의 버전을 명시적으로 상속
    virtual void someMethod(int i) {}; // 새 버전을 추가
    virtual void someOtherMethod() {};
    virtual void overload() override { std::cout << "Derived's overload()\n"; }
};

class Base1
{
  public:
    virtual ~Base1() = default;
    Base1() = default;
    Base1(float f) { std::cout << "Base1's float ctor\n"; }
};

class Base2
{
  public:
    virtual ~Base2() = default;
    Base2() = default;
    Base2(float f) { std::cout << "Base2's float ctor\n"; }
};

class Derived2 : public Base1, public Base2
{
  public:
    using Base1::Base1;
    using Base2::Base2;
    Derived2(char c) { std::cout << "Derived2's char ctor\n"; };
    Derived2(float f) { std::cout << "Derived2's float ctor\n"; };
};

class BaseStatic
{
  public:
    static void beStatic() { std::cout << "BaseStatic being static!\n"; }
};

class DerivedStatic : public BaseStatic
{
  public:
    static void beStatic() { std::cout << "DerivedStatic keepin it static!\n"; }
};

class MilesEstimator
{
  private:
    int m_gallonsLeft{};
    virtual int getMilstPerGallone() const { return 20; }

  public:
    virtual ~MilesEstimator() = default;
    int getMilesLeft() const { return getMilstPerGallone() * getGallonsLeft(); }
    virtual void setGallonsLeft(int gallons) { m_gallonsLeft = gallons; }
    virtual int getGallonsLeft() const { return m_gallonsLeft; }
};

class EfficientCarMilesEstimator : public MilesEstimator
{
  private:
    int getMilstPerGallone() const override { return 35; }
};

int main()
{
    Base base1{};
    Base base2{"Hello~"};
    std::cout << "============================\n";
    Derived derived1{"Hello"};
    std::cout << "============================\n";
    Derived derived2{3};
    std::cout << "============================\n";
    Derived derived3{};
    std::cout << "============================\n";
    Derived derived4{1.23f};
    std::cout << "============================\n";
    Derived2 derived5{1.23f};
    std::cout << "============================\n";
    BaseStatic::beStatic();
    DerivedStatic::beStatic();
    std::cout << "============================\n";
    DerivedStatic myDerivedStatic;
    BaseStatic &ref{myDerivedStatic};
    myDerivedStatic.beStatic();
    ref.beStatic();
    std::cout << "============================\n";
    Derived derived6;
    Base &ref2{derived6};
    ref2.overload(6);
    std::cout << "============================\n";
    Derived derived7;
    derived7.overload(7);
    std::cout << "============================\n";
    MilesEstimator myMilesEstimator;
    myMilesEstimator.setGallonsLeft(2);
    std::cout << std::format("Normal estiamtor can go {} more miles.\n",
                             myMilesEstimator.getMilesLeft());
    std::cout << "============================\n";
    EfficientCarMilesEstimator myEstimator;
    myEstimator.setGallonsLeft(2);
    std::cout << std::format("Efficient estiamtor can go {} more miles.\n",
                             myEstimator.getMilesLeft());
    std::cout << "============================\n";
}