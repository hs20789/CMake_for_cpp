#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int getNumberOfDaysBetweenDates(const sys_days &date1, const sys_days &date2)
{
    return (date2 - date1).count();
}

int main()
{
    cout << getNumberOfDaysBetweenDates(2025y / August / 30d,
                                        2025y / November / 13d)
         << endl;
}
