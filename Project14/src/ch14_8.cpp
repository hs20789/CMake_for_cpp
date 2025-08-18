#include <exception>
#include <format>
#include <iostream>
#include <memory>
#include <source_location>

int main()
{
    int *ptr{nullptr};
    size_t integerCount{std::numeric_limits<size_t>::max()};
    std::cout << std::format("Trying to allocate memory for {} integers.\n",
                             integerCount);

    try {
        ptr = new int[integerCount];
    } catch (std::bad_alloc const &e) {
        auto location{std::source_location::current()};
        std::cerr << std::format("{} ({}): Unable to allocate memory: {}",
                                 location.file_name(), location.line(),
                                 e.what())
                  << std::endl;
    }
    return 0;
}
