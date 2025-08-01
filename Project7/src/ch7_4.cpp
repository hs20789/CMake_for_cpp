#include <iostream>
#include <memory>

class Simple
{
  public:
    Simple() { m_intPtr = new int{}; }
    ~Simple() { delete m_intPtr; }
    void setValue(int value) { *m_intPtr = value; }
    void go() { std::cout << "go func\n"; }

  private:
    int *m_intPtr;
};

void leaky();
void couldBeLeaky();
void notLeaky1();
void notLeaky2();

int main()
{
    leaky();
    couldBeLeaky();
    notLeaky1();
    notLeaky2();
}

void leaky()
{
    Simple *mySimplePtr{new Simple{}};
    mySimplePtr->go();
}

void couldBeLeaky()
{
    Simple *mySimplePtr{new Simple{}};
    // go() 메서드에서 익셉션 발생시 누수 발생
    mySimplePtr->go();
    delete mySimplePtr;
}

void notLeaky1()
{
    auto mySimpleSmartPtr{std::make_unique<Simple>()};
    mySimpleSmartPtr->go();
}

void notLeaky2()
{
    std::unique_ptr<Simple> mySimpleSmartPtr{new Simple{}};
    mySimpleSmartPtr->go();
}