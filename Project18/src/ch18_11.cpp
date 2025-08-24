#include <exception>
#include <format>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <string>
#include <utility>

class Error final
{
  public:
    Error(std::string errorString) : m_errorString{std::move(errorString)} {}

    std::string const &getErrorString() const { return m_errorString; }

  private:
    std::string m_errorString;
};

std::ostream &operator<<(std::ostream &os, Error const &err)
{
    os << err.getErrorString();
    return os;
}

class ErrorCorrelator final
{
  public:
    void addError(Error const &error) { m_errors.push(error); }
    [[nodiscard]] Error getError()
    {
        if (m_errors.empty()) {
            throw std::out_of_range{"No more errors."};
        }
        Error top{m_errors.top()};
        m_errors.pop();
        return top;
    }

  private:
    std::stack<Error> m_errors;
};

int main()
{
    ErrorCorrelator ec;
    ec.addError(Error{"unable to read file."});
    ec.addError(Error("Incorrect entry from user."));
    ec.addError(Error{"Unable to allocate memory!."});

    while (true) {
        try {
            Error e{ec.getError()};
            std::cout << e << std::endl;
        } catch (std::out_of_range const &e) {
            std::cout << "Finished processing errors.\n"
                      << e.what() << std::endl;
            break;
        }
    }
}