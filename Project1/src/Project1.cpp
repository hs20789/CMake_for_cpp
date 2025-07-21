#include <iostream>

int main() {
    // 표준 __cplusplus: 모든 컴파일러에서 표준값. 단, Visual Studio는 옵션에
    // 따라 199711L만 반환될 수 있음.
    std::cout << "__cplusplus: " << __cplusplus << std::endl;

#ifdef _MSVC_LANG
    // Visual Studio 전용: 진짜 활성화된 표준 버전
    std::cout << "_MSVC_LANG: " << _MSVC_LANG << std::endl;
#endif

    return 0;
}
