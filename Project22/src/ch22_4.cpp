#include <chrono>
#include <cmath>
#include <iostream>

int main()
{
    // 시스템에서 현재 시간을 알아내서 사람이 읽기 쉬운 형태로 변환해서 콘솔에
    // 출력하는 과정
    using namespace std::chrono;
    system_clock::time_point tpoint{system_clock::now()};
    time_t tt{system_clock::to_time_t(tpoint)};
    tm *t{localtime(&tt)};
    std::cout << std::put_time(t, "%H %M %S") << std::endl;

    std::stringstream ss;
    ss << std::put_time(t, "%H:%M:%S");
    std::string stringTime{ss.str()};
    std::cout << stringTime << std::endl;

    char buffer[80] = {};
    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
    std::cout << buffer << std::endl;

    // 특정한 코드 영역을 실행하는 데 걸리는 시간을 측정
    auto start{high_resolution_clock::now()};
    double d{};
    for (int i{}; i < 1'000'000; ++i) {
        d += std::sqrt(std::sin(i) * std::cos(i));
    }
    auto end{high_resolution_clock::now()};
    auto diff{end - start};
    std::cout << duration<double, std::milli>{diff}.count() << "ms"
              << std::endl;
}