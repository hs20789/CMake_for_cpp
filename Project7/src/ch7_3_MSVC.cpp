#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif
#endif

#include <iostream>

class Simple
{
  public:
    Simple() { m_intPtr = new int{}; }
    ~Simple() { delete m_intPtr; }
    void setValue(int value) { *m_intPtr = value; }

  private:
    int *m_intPtr;
};

void doSomething(Simple *&outSimplePtr);

int main()
{
    //_CrtSetBreakAlloc(183);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Simple *simplePtr{new Simple{}};
    doSomething(simplePtr);
    delete simplePtr;
}

void doSomething(Simple *&outSimplePtr)
{
    outSimplePtr = new Simple();
    // 버그! 원본 객체를 삭제하지 않았다.
}
