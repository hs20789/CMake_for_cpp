#include <iomanip>
#include <iostream>

int main()
{
    // bool 값
    bool myBool{true};
    std::cout << "This is the default: " << myBool << std::endl;
    std::cout << "This should be true: " << std::boolalpha << myBool
              << std::endl;
    std::cout << "This should be 1: " << std::noboolalpha << myBool
              << std::endl;

    // "%6d" 와 같은 효과를 스트림에 적용
    int num1{123};
    printf("This should be |   123|: |%6d|\n", num1);
    std::cout << "This should be |   123|: |" << std::setw(6) << num1 << "|\n";

    using namespace std;
    {
        int i{123};
        // Fill with *
        cout << "This should be '***123': " << setfill('*') << setw(6) << i
             << endl;
        // Reset fill character
        cout << setfill(' ');

        // Floating-point values
        double dbl{1.452};
        double dbl2{5};
        cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2
             << endl;
        cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl
             << endl;
        // Reset fill character
        cout << setfill(' ');

        // Instructs cout to start formatting numbers according to your
        // location. Chapter 21 explains the details of the imbue() call and the
        // locale object.
        cout.imbue(locale{""});

        // Format numbers according to your location
        cout << "This is 1234567 formatted according to your location: "
             << 1234567 << endl;

        // Money amount. What exactly an amount of money means depends on your
        // location. For example, in the USA, a money amount of 120000 means
        // 120000 dollar cents, which is 1200.00 dollars.
        std::locale sysloc("");
        std::cout.imbue(sysloc);
        cout << "This should be a money amount of 120000, "
             << "formatted according to your location: "
             << put_money("120000", /*intl=*/true) << endl;

        // Date and time
#if !defined(_MSC_VER)
        time_t t_t{time(nullptr)}; // Get current system time.
        tm *t{localtime(&t_t)};    // Convert to local time.
        cout << "This should be the current date and time formatted according "
                "to your location: "
             << put_time(t, "%c") << endl;
#else
        // Visual C++:
        time_t t_t{time(nullptr)};
        tm t;
        localtime_s(&t, &t_t);
        cout << "This should be the current date and time formatted according "
                "to your location: "
             << put_time(&t, "%c") << endl;
#endif

        // Quoted string
        cout << "This should be: \"Quoted string with \\\"embedded "
                "quotes\\\".\": "
             << quoted("Quoted string with \"embedded quotes\".") << endl;

        // Use setprecision manipulator.
        cout << "This should be '1.2346': " << setprecision(5) << 1.23456789
             << endl;

        // Use precision() method
        cout.precision(5);
        cout << "This should be '1.2346': " << 1.23456789 << endl;
    } // namespace std;
}