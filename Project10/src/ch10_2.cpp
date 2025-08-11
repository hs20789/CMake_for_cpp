#include <iostream>

import MyWeatherPrediction;

class Something
{
  public:
    Something() { std::cout << "2"; }
    Something(int num) { std::cout << num; }
    virtual ~Something() { std::cout << "2"; }
};

class Base
{
  public:
    Base() { std::cout << "1"; }
    virtual ~Base() { std::cout << "1"; }
};

class Derived : public Base
{
  public:
    Derived() { std::cout << "3"; }
    virtual ~Derived() { std::cout << "3"; }

  private:
    Something m_dataMember;
};

class DerivedDerived: public Derived
{
public:
    DerivedDerived() { std::cout << "4"; }
  virtual ~DerivedDerived() { std::cout << "4"; }
};

int main()
{
    std::cout << "Start of main\n";
    Base *ptr{new Derived{}};
    delete ptr;
    std::cout << "\nend of section\n====================================\n";

    DerivedDerived myDerived2;
}