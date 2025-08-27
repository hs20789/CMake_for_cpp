// 시스템의 한 에러가 여러 컴포넌트에 에러를 발생시키는 경우가 많다. 에러 처리를
// 잘하는 시스템은 이러한 에러 상관관계를 고려해서 가장 중요한 에러부터 먼저
// 처리한다. 이러한 에러 상관관계를 std::priority_queue로 구현할 수 있다.
// 여기서는 에러 상황마다 우선 순위가 정해졌다고 가정한다. 에러 상관관계란 결국
// 에러 상황을 우선순위에 따라 정렬한 것이다. 그러므로 우선순위가 가장 높은
// 에러를 제일 먼져 처리한다.

#include <exception>
#include <format>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <utility>

class Error final
{
  public:
    Error(int priority, std::string errorString)
        : m_priority{priority}, m_errorString{std::move(errorString)}
    {}
    int getPriority() const { return m_priority; }
    std::string const &getErrorString() const { return m_errorString; }

    auto operator<=>(Error const &rhs) const
    {
        return getPriority() <=> rhs.getPriority();
    }

  private:
    int m_priority{};
    std::string m_errorString;
};

std::ostream &operator<<(std::ostream &os, Error const &err)
{
    os << std::format("{} (priority {})", err.getErrorString(),
                      err.getPriority());
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
    std::priority_queue<Error> m_errors;
};

int main()
{
    ErrorCorrelator ec;
    ec.addError(Error{3, "unable to read file."});
    ec.addError(Error(1, "Incorrect entry from user."));
    ec.addError(Error{10, "Unable to allocate memory!."});

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