#include <iostream>
#include <source_location>
#include <string>
#include <string_view>
#include <utility>

void logMessage(std::string_view message, std::source_location const &location =
                                              std::source_location::current());

void foo();

int main()
{
    // 1
    // 2
    foo();
}

void logMessage(std::string_view message, std::source_location const &location)
{
    std::cout << std::format("{} ({}): {}: {}", location.file_name(),
                             location.line(), location.function_name(), message)
              << std::endl;
}

void foo() { logMessage("Starting execution of foo()."); }