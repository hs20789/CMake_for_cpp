#include <array>
#include <iostream>
#include <print>
#include <vector>

// 스택의 원소에 2를 곱하는 함수
void doubleInts(int *theArray, size_t size);

// 배열을 출력하는 함수
void printArray(int *theArray, size_t size);
// void printArray(int theArray[], size_t size);
// void printArray(int theArray[2], size_t size);
// 위의 세 프로토타입은 모두 동일하다.
int main()
{
    // C 스타일 캐스팅으로는 포인터의 타입을 얼마든지 바꿀 수 있다.
    int *intptr1{new int{}};
    char *charptr1{(char *)intptr1};
    // 정적 캐스팅을 사용하면 더 안전하다.
    int *intptr2{new int{}};
    // char *charptr2{static_cast<char *>(intptr2)};
    char *charptr2{reinterpret_cast<char *>(intptr2)};

    // 배열과 포인터
    int myIntArray[10]{};
    int *myIntptr{myIntArray};
    myIntptr[4] = 5;

    size_t arrSize{4};
    int *freeStoreArray{new int[arrSize]{1, 5, 3, 4}};
    printArray(freeStoreArray, arrSize);
    doubleInts(freeStoreArray, arrSize);
    printArray(freeStoreArray, arrSize);
    delete[] freeStoreArray;
    freeStoreArray = nullptr;

    int stackArray[]{5, 7, 9, 11};
    arrSize = std::size(stackArray);
    printArray(stackArray, arrSize);
    doubleInts(stackArray, arrSize);
    printArray(stackArray, arrSize);
    doubleInts(&stackArray[0], arrSize);
    printArray(stackArray, arrSize);
    stackArray[2] = 100;
    printArray(stackArray, arrSize);
    *(stackArray + 2) = 200;
    printArray(stackArray, arrSize);
}

// 스택의 원소에 2를 곱하는 함수
void doubleInts(int *theArray, size_t size)
{
    for (size_t i{}; i < size; i++) {
        theArray[i] *= 2;
    }
}

// 배열을 출력하는 함수
void printArray(int *theArray, size_t size)
{
    for (size_t i{}; i < size; i++) {
        std::cout << theArray[i] << '\t';
    }
    std::cout << "\n\n";
}