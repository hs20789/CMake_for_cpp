#include <bit>
#include <iostream>
#include <string>
#include <typeinfo>

class Animal
{
  public:
    virtual void eat() = 0;
    virtual void sleep() { std::cout << "zzzzz...." << std::endl; }
};
class Dog : public virtual Animal
{
  public:
    virtual void bark() { std::cout << "Woof!\n"; }
    void eat() override { std::cout << "The dog ate.\n"; }
};

class Bird : public virtual Animal
{
  public:
    virtual void chirp() { std::cout << "Chirp!\n"; }
    void eat() override { std::cout << "The bird ate.\n"; }
};

class DogBird : public Dog, public Bird
{
  public:
    virtual void eat() override { Dog::eat(); }
};
class Loggable
{
  public:
    virtual ~Loggable() = default;
    virtual std::string getLogMessage() const = 0;
};

class Foo : public Loggable
{
  public:
    std::string getLogMessage() const override { return "Hello logger.\n"; }
};

class Base
{
  public:
    virtual ~Base() = default;
};

class Derived : public Base
{
  public:
    virtual ~Derived() = default;
};

void logObject(Loggable const &loggableObject);

void speak(Animal const &animal);

int main()
{
    Foo testFoo;
    logObject(testFoo);
    std::cout << "========================================\n";

    DogBird myConfusedAnimal;
    myConfusedAnimal.eat();
    myConfusedAnimal.sleep();
    std::cout << "========================================\n";

    int *ptr1{new int{100}};
    void *generic_ptr1{static_cast<void *>(ptr1)};
    double *ptr2{static_cast<double *>(generic_ptr1)};
    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl; // 미정의 동작 UB
    std::cout << "========================================\n";

    // 캐스팅
    int i{3};
    int j{4};
    double result{static_cast<double>(i) / j};
    std::cout << result << std::endl;
    std::cout << "========================================\n";

    Base *b{nullptr};
    Derived *d{new Derived{}};
    b = d;
    d = static_cast<Derived *>(b);

    Base base;
    Derived derived;
    Base &br{derived};
    Derived &dr{static_cast<Derived &>(br)};

    std::cout << "========================================\n";
}

void speak(Animal const &animal)
{
    if (typeid(animal) == typeid(Dog)) {
        std::cout << "Woof!\n";
    } else if (typeid(animal) == typeid(Bird)) {
        std::cout << "Chirp!\n";
    }
}

void logObject(Loggable const &loggableObject)
{
    std::cout << typeid(loggableObject).name() << ": ";
    std::cout << loggableObject.getLogMessage() << std::endl;
}