#include <iostream>
#include <print>

// 이차원 배열을 동적으로 할당하는 함수
char **allocateCharacterBoard(size_t xDemansion, size_t yDimension);
// 이차원 동적 배열에 할당된 메모리를 해제하는 함수
void releaseCharacterBoard(char **myArray, size_t xDimension);

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
        << "After delete[] mySimpleArray1"
           "mySimpleArray1;\n------------------------------------------------"
           "-----------------------\n";
    delete[] mySimpleArray1;
    mySimpleArray1 = nullptr;

    std::cout << "Pointer "
                 "Array--------------------------------------------------------"
                 "-------------\n";
    // 포인터 배열
    size_t const size1{4};
    Simple **mySimpleArray2{new Simple *[size1]};

    for (size_t i{}; i < size1; i++) {
        mySimpleArray2[i] = new Simple{};
    }
    for (size_t i{0}; i < size1; i++) {
        delete mySimpleArray2[i];
        mySimpleArray2[i] = nullptr;
    }
    delete[] mySimpleArray2;
    mySimpleArray2 = nullptr;
    std::cout << "Pointer "
                 "Array--------------------------------------------------------"
                 "-------------\n\n\n";
    // 다차원 프리스토어 배열
    char **myArrayptr5{allocateCharacterBoard(4, 4)};
    releaseCharacterBoard(myArrayptr5, 4);
}

// 이차원 배열을 동적으로 할당하는 함수
char **allocateCharacterBoard(size_t xDimansion, size_t yDimension)
{
    char **myArray{new char *[xDimansion]};
    for (size_t i{}; i < xDimansion; i++) {
        myArray[i] = new char[yDimension];
    }
    return myArray;
}
// 이차원 동적 배열에 할당된 메모리를 해제하는 함수
void releaseCharacterBoard(char **myArray, size_t xDimension)
{
    for (size_t i{}; i < xDimension; i++) {
        delete[] myArray[i];
        myArray[i] = nullptr;
    }
    delete[] myArray;
    myArray = nullptr;
}
