#include <iostream>
#include <print>

int main()
{
    int *ptr1{nullptr};
    ptr1 = new int;
    delete ptr1;
    ptr1 = nullptr;
    // 위의 코드는 아래의 코드와 같다.
    int *ptr2{new int};
    delete ptr2;
    ptr2 = nullptr;

    // 다음의 코드는 포인터가 스택과 프리스토어(힙) 모두에 있는 예를 보여준다.
    int **ptr3_stack{nullptr};
    ptr3_stack = new int *;
    *ptr3_stack = new int;
    delete *ptr3_stack;
    delete ptr3_stack;
    ptr3_stack = nullptr;
    // 위의 코드는 아래의 코드와 같다.
    int **ptr4_stack{new int *};
    *ptr4_stack = new int;
    delete *ptr4_stack;
    delete ptr4_stack;
    ptr4_stack = nullptr;

    int *ptr5 = static_cast<int *>(malloc(sizeof(int)));
    free(ptr5);
    ptr5 = NULL;
    int *ptr6{new int};
    delete ptr6;
    ptr6 = nullptr;

    // 1. 기본 타입 배열
    int myArray1[5];                // [?, ?, ?, ?, ?]
    int myArray2[5]{1, 2, 3, 4, 5}; // [1, 2, 3, 4, 5]
    int myArray3[5]{1, 2};          // [1, 2, ?, ?, ?]
    int myArray4[5]{0};             // [0, 0, 0, 0, 0]
    int myArray5[5]{};              // [0, 0, 0, 0, 0]

    // 1.2. 동적 할당 배열
    int *myArrayptr1{new int[5]}; // [?, ?, ?, ?, ?]
    delete[] myArrayptr1;
    myArrayptr1 = nullptr;
    int *myArrayptr2{new (std::nothrow) int[5]}; // [?, ?, ?, ?, ?]
    delete[] myArrayptr2;
    myArrayptr2 = nullptr;
    int *myArrayptr3{new int[5]{1, 2, 3, 4, 5}}; // [1, 2, 3, 4, 5]
    delete[] myArrayptr3;
    myArrayptr3 = nullptr;
    int *myArrayptr4{new (std::nothrow) int[5]{}}; // [0, 0, 0, 0, 0]
    delete[] myArrayptr4;
    myArrayptr4 = nullptr;

    // 2. 객체 배열
    class Simple
    {
      public:
        Simple() { std::cout << "Simple constructor called!\n"; }
        ~Simple() { std::cout << "Simple destructor called!\n"; }
    };
    std::cout << "After Simple *mySimpleArray1{new "
                 "Simple[4]};\n------------------------------------------------"
                 "-----------------------\n";
    Simple *mySimpleArray1{new Simple[4]};
    std::cout
        << "After delete[] "
           "mySimpleArray1;\n------------------------------------------------"
           "-----------------------\n";
    delete[] mySimpleArray1;
    mySimpleArray1 = nullptr;
}