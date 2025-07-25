#pragma once

#include <vector>

// Check if a pointer is null
void checkNullPointer(void *ptr);
// int 타입 배열을 두 개(하나는 짞수, 하나는 홀수)로 나누는 함수 - 포인터 사용
void separateOddsAndEvensPtr(const int arr[], size_t size, int **odds,
                             size_t *numOdds, int **evens, size_t *numEvens);

// int 타입 배열을 두 개(하나는 짞수, 하나는 홀수)로 나누는 함수 - 레퍼런스 사용
void separateOddsAndEvensRef(const int arr[], size_t size, int *&odds,
                             size_t &numOdds, int *&evens, size_t &numEvens);

// int 타입 배열을 두 개(하나는 짞수, 하나는 홀수)로 나누는 함수 - 레퍼런스
// 사용, 동적 할당하지 않음
void separateOddsAndEvensRefVec(const std::vector<int> &arr,
                                std::vector<int> &odds,
                                std::vector<int> &evens);

struct OddsAndEvens {
    std::vector<int> odds, evens;
};

// int 타입 배열을 두 개(하나는 짞수, 하나는 홀수)로 나누는 함수 - 레퍼런스
// 사용, 동적 할당하지 않음, 리턴값 사용
OddsAndEvens separateOddsAndEvensRefVecReturn(const std::vector<int> &arr);


// Exception 테스트 함수
double divideNumbers(double numerator, double denominator);