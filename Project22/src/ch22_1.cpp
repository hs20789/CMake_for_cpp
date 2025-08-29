#include <format>
#include <iostream>
#include <ratio>

template <class R> void print_ratio(const char *name)
{
    std::cout << name << " = " << R::num << "/" << R::den << '\n';
}

int main()
{
    // 1/60이라는 유리수를 컴파일 시간 상수로 선언
    using r1 = std::ratio<1, 60>;

    // r1 유리수의 분자(num)와 분모(den)
    // 컴파일 시간 상수이며 아래와 같이 접근
    std::intmax_t num{r1::num};
    std::intmax_t den{r1::den};
    std::cout << std::format("1) r1 = {}/{}", num, den) << std::endl;

    constexpr std::intmax_t n{1};
    constexpr std::intmax_t d{30};
    using r2 = std::ratio<n, d>;
    print_ratio<r2>("r2");
    std::cout << std::format("2) r2 = {}/{}", r2::num, r2::den) << std::endl;

    using result = std::ratio_add<r1, r2>::type;
    std::cout << std::format("3) sum = {}/{}", result::num, result::den)
              << std::endl;

    using res = std::ratio_less<r2, r1>;
    std::cout << std::format("4) r2 < r1: {}", res::value) << std::endl;
}