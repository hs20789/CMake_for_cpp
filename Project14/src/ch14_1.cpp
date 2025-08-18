#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

std::vector<int> readIntegerFile(std::string_view filename);

double SafeDivide(double num, double den);

int main()
{
    std::string const filename{"test1.txt"};
    try {
        std::vector<int> myInts{readIntegerFile(filename)};
        for (auto const &element : myInts) {
            std::cout << element << " -- ";
        }
        std::cout << std::endl;
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << SafeDivide(5, 2) << '\n';
        std::cout << SafeDivide(10, 0) << '\n';
        std::cout << SafeDivide(3, 3) << '\n';
    } catch (std::invalid_argument const &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

std::vector<int> readIntegerFile(std::string_view filename)
{
    std::filesystem::path path_{"Project14/docs"};
    path_.append(filename.data());
    std::ifstream inputStream{path_};

    // 파일 열기에 실패한 경우
    if (inputStream.fail()) {
        throw std::invalid_argument{"Unable to open the file."};
    }

    std::vector<int> integers;
    int temp{};
    while (inputStream >> temp) {
        integers.push_back(temp);
    }

    // 파일을 읽는 도중 에러가 발생
    if (!inputStream.eof()) {
        throw std::runtime_error{"Error reading the file."};
    }
    return integers;
}

double SafeDivide(double num, double den)
{
    if (den == 0) {
        throw std::invalid_argument{"Divide by Zero"};
    }
    return num / den;
}