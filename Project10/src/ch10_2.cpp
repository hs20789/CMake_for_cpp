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

class DerivedDerived : public Derived
{
  public:
    DerivedDerived() { std::cout << "4"; }
    virtual ~DerivedDerived() { std::cout << "4"; }
};

// 북 클래스
class Book
{
  public:
    virtual ~Book() = default;
    virtual std::string getDescription() const { return "Book"; }
    virtual int getHeight() const { return 120; }
};

class Paperback : public Book
{
  public:
    std::string getDescription() const override
    {
        return "Paperback" + Book::getDescription();
    }
};

class Romance : public Paperback
{
  public:
    std::string getDescription() const override
    {
        return "Romance" + Paperback::getDescription();
    }
    int getHeight() const override { return Paperback::getHeight() / 2; }
};

class Technical : public Book
{
  public:
    std::string getDescription() const override
    {
        return "Technical" + Book::getDescription();
    }
};

int main()
{
    std::cout << "Start of main\n";
    Base *ptr{new Derived{}};
    delete ptr;
    std::cout << "\nend of section\n====================================\n\n";
    Base *ptr2{new DerivedDerived{}};
    delete ptr2;
    std::cout << "\nend of section\n====================================\n\n";

    // Book 클래스
    Romance novel;
    Book book;
    std::cout << novel.getDescription() << std::endl;
    std::cout << book.getDescription() << std::endl;
    std::cout << novel.getHeight() << std::endl;
    std::cout << book.getHeight() << std::endl;
    std::cout << "\nend of section\n====================================\n\n";

    // Upcast & Downcast
    Base myBase{Derived{}};         // 슬라이싱
    Base *myBasePtr{new Derived{}}; // 업캐스트

}