## Q. 연습 문제 7-1에 나온 코드를 안전하고 모던 C++ 구문에 맞게 고쳐보자.

---

## Solution.

## 1. delete[] 사용

```
size_t const numberOfElements { 10 };
int* values { new int[numberOfElements] };
for (int index{}; index < numberOfElements; ++index){
    values[index] = index;
}
values[9] = 99;
for (int index{}; index < numberOfElements; ++index){
    std::cout << values[index] << "  ";
}
delete[] values;
```

2. std::unique_ptr 사용

```
size_t const numberOfElements { 10 };
std::unique_ptr<int[]> values{ new int[numberOfElements] };
for (int index{}; index < numberOfElements; ++index){
    values[index] = index;
}
values[9] = 99;
for (int index{}; index < numberOfElements; ++index){
    std::cout << values[index] << "  ";
}
```

3. std::make_unique 사용

```
size_t const numberOfElements { 10 };
auto values {std::make_unique<int[]>(10)};
for (int index{}; index < numberOfElements; ++index){
    values[index] = index;
}
values[9] = 99;
for (int index{}; index < numberOfElements; ++index){
    std::cout << values[index] << "  ";
}
```

4. std::vector 사용

```
size_t const numberOfElements { 10 };
std::vector<int> values{};
for (int index{}; index < numberOfElements; ++index){
    values.push_back(index);
}
values.back() = 99;
for (auto const& value : values){
    std::cout << value << "  ";
}
```