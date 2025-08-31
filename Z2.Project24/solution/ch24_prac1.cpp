#include <iostream>
#include <string>
#include <variant>
#include <vector>

class Error
{
  public:
    Error(std::string message) : m_message{std::move(message)} {}
    std::string const &getMessage() const { return m_message; }

  private:
    std::string m_message;
};

std::variant<std::vector<int>, Error> getData(bool fail)
{
    if (fail) {
        return Error{"Error occured!!."};
    } else {
        return std::vector{1, 2, 3, 4, 5, 6};
    }
}

void handleResult(std::variant<std::vector<int>, Error> const &result)
{
    {
        using namespace std;
        if (holds_alternative<Error>(result)) {
            cout << "Error: " << get<Error>(result).getMessage() << endl;
        } else {
            auto &data{get<vector<int>>(result)};
            for (auto &value : data) {
                cout << value << " || ";
            }
            cout << endl;
        }
    }
}

int main()
{
    //
    //
    handleResult(getData(true));
    handleResult(getData(false));
}