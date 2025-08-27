#include <exception>
#include <iostream>
#include <string>
#include <vector>

void verifyDataSize(std::vector<int> const &data)
{
    if (data.size() % 2 != 0) {
        throw std::logic_error{"Number of data points must be even."};
    }
}

void processData(std::vector<int> const &data)
{
    try {
        verifyDataSize(data);
    } catch (std::logic_error const &caughtException) {
        std::cerr << "Invalid number of data points in dataset. Aborting."
                  << std::endl;
        throw;
    }
    // Check minus
    for (auto &value : data) {
        if (value < 0) {
            throw std::domain_error{"Negative datapoints not allowed."};
        }
    }
}

int main()
{
    try {
        std::vector<int> data{1, 2, 3, -5, 6, 9};
        processData(data);
    } catch (std::domain_error const &caughtException) {
        std::cerr << "std::domain_error: " << caughtException.what()
                  << std::endl;
    } catch (std::logic_error const &caughtException) {
        std::cerr << "std::logic_error: " << caughtException.what()
                  << std::endl;
    }
}