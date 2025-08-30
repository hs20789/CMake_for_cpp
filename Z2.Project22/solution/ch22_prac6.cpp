#include <chrono>
#include <ctime>
#include <format>
#include <iostream>

using namespace std;
using namespace std::chrono;

system_clock::duration getDurationSinceMidnight()
{
    const auto now = system_clock::now();

    time_t nowTimeT = system_clock::to_time_t(now);
    tm midnightTm{};

#ifdef _WIN32
    // Windows: localtime_s(tm*, const time_t*)
    localtime_s(&midnightTm, &nowTimeT);
#else
    // POSIX:   localtime_r(const time_t*, tm*)
    localtime_r(&nowTimeT, &midnightTm);
#endif

    midnightTm.tm_hour = 0;
    midnightTm.tm_min = 0;
    midnightTm.tm_sec = 0;
    midnightTm.tm_isdst = -1; // DST 재계산

    const time_t midT = mktime(&midnightTm); // 로컬 자정
    const auto midnight = system_clock::from_time_t(midT);

    return now - midnight;
}

int main()
{
    const auto sinceMidnight = getDurationSinceMidnight();

    cout << duration_cast<seconds>(sinceMidnight).count() << '\n';

    hh_mm_ss hms{floor<seconds>(sinceMidnight)};
    cout << std::format("{:%T}\n", hms) << '\n';
}
