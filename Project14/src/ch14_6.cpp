#include <exception>
#include <format>
#include <iostream>
#include <source_location>
#include <string>
#include <string_view>

class MyException : public std::exception
{
  public:
    MyException(std::string_view message) : m_message{std::move(message)} {}
    char const *what() const noexcept override { return m_message.c_str(); }

  private:
    std::string m_message;
};

void doSomething();

int main()
{
    try {
        doSomething();
    } catch (MyException const &e) {
        std::cout << std::format("{} caught MyException: {}", __func__,
                                 e.what())
                  << std::endl;
        try {
            std::rethrow_if_nested(e);
        } catch (std::runtime_error const &e) {
            std::cout << std::format("  Nested exception: {}", e.what())
                      << std::endl;
        }
    }
}

void doSomething()
{
    try {
        throw std::runtime_error{"Throwing a runtime_error exception."};
    } catch (std::runtime_error const &e) {
        std::cout << std::format("{} caught a runtime error", __func__)
                  << std::endl;
        std::cout << std::format("{} throwing MyException", __func__)
                  << std::endl;
        std::throw_with_nested(
            MyException{"MyException with nested runtime_error"});
    }
}