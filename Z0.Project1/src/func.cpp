#include "func.h"
#include <iostream>

void checkNullPointer(void *ptr) {
    if (!ptr)
        std::cout << "This pointer is null.\n";
    else
        std::cout << "This pointer is not null.\n";
}

void separateOddsAndEvensPtr(const int arr[], size_t size, int **odds,
                             size_t *numOdds, int **evens, size_t *numEvens) {
    *numOdds = *numEvens = 0;
    for (size_t i{}; i < size; ++i) {
        if (arr[i] % 2 == 1)
            ++(*numOdds);
        else
            (*numEvens)++;
    } // 홀수와 짝수의 개수를 세기

    *odds = new int[*numOdds];
    *evens = new int[*numEvens];

    size_t oddsPos{}, evensPos{};
    for (size_t i{}; i < size; ++i) {
        if (arr[i] % 2 == 1)
            (*odds)[oddsPos++] = arr[i];
        else
            (*evens)[evensPos++] = arr[i];
    } // 홀수와 짝수를 분리하여 각각의 배열에 저장
}

// int 타입 배열을 두 개(하나{는 짞수, 하나는 홀수)로 나누는 함수 - 레퍼런스
// 사용
void separateOddsAndEvensRef(const int arr[], size_t size, int *&odds,
                             size_t &numOdds, int *&evens, size_t &numEvens) {
    numOdds = numEvens = 0;
    for (size_t i{}; i < size; ++i) {
        if (arr[i] % 2 == 1)
            ++numOdds;
        else
            ++numEvens;
    } // 홀수와 짝수의 개수를 세기)

    odds = new int[numOdds];
    evens = new int[numEvens];

    size_t oddsPos{}, evensPos{};
    for (size_t i{}; i < size; ++i) {
        if (arr[i] % 2 == 0)
            odds[oddsPos++] = arr[i];
        else
            evens[evensPos++] = arr[i];
    }
}

// int 타입 배열을 두 개(하나는 짞수, 하나는 홀수)로 나누는 함수 - 레퍼런스
// 사용, 동적 할당하지 않음
void separateOddsAndEvensRefVec(const std::vector<int> &arr,
                                std::vector<int> &odds,
                                std::vector<int> &evens) {
    for (int i : arr) {
        if (i % 2 == 0)
            odds.push_back(i);
        else
            evens.push_back(i);
    }
}

// int 타입 배열을 두 개(하나는 짞수, 하나는 홀수)로 나누는 함수 - 레퍼런스
// 사용, 동적 할당하지 않음, 리턴값 사용
OddsAndEvens separateOddsAndEvensRefVecReturn(const std::vector<int> &arr) {
    std::vector<int> odds{}, evens{};
    for (int i : arr) {

        if (i % 2 == 0)
            odds.push_back(i);
        else
            evens.push_back(i);
    }
    return OddsAndEvens{.odds{odds}, .evens{evens}};
}

// Exception 테스트 함수
double divideNumbers(double numerator, double denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0.");
    return numerator / denominator;
}