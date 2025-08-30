## Q. 다음 코드를 분석해서 문제점을 찾아보자. 수정 방안은 다음 문제(7-2)에서 적용해본다.

```
size_t const numberOfElements{10};
int *values{new int[numberOfElements]};
for (int index{}; index < numberOfElemants; ++index) {
    values[index] = index;
}

values[10] = 99;
for (int index{}; index <= numberOfElements; ++index) {
    std::cout << values[index] << "  ";
}
```

--- 

## Solution.

- 배열의 인덱스는 9이다.
- 인덱스는 9까지기에 두번째 `for` 문에서는 <= 말고 < 를 써주어야 한다.
- `new int[numberOfLelmnts]` 는 동적할당되었기에 `delete[]` 로 해제해주어야 한다.