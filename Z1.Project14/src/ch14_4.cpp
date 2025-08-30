#include <iostream>
#include <source_location>
#include <string>
#include <string_view>
#include <utility>

class MyException : public std::exception
{
  public:
    MyException(std::string message,
                std::source_location location = std::source_location::current())
        : m_message{std::move(message)}, m_location{std::move(location)}
    {}

    char const *what() const noexcept override { return m_message.c_str(); }
    virtual std::source_location const &where() const noexcept
    {
        return m_location;
    }

  private:
    std::string m_message;
    std::source_location m_location;
};

void doSomething()
{
    std::cout << __func__ << '\n';
    throw MyException{"Throwing MyException."};
}

int main()
{
    try {
        doSomething();
    } catch (MyException const &e) {
        auto const &location{e.where()};
        std::cerr << std::format("Caught: '{}' at line {} in {}.", e.what(),
                                 location.line(), location.function_name())
                  << std::endl;
    }
}