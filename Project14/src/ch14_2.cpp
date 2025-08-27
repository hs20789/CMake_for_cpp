#include <exception>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

std::vector<int> readIntegerFile(std::string filename);

class FileError : public std::exception
{
  public:
    FileError(std::string filename) : m_filename{std::move(filename)} {}
    char const *what() const noexcept override { return m_message.c_str(); }
    virtual std::string const &getFilename() const noexcept
    {
        return m_filename;
    }

  protected:
    virtual void setMessage(std::string message)
    {
        m_message = std::move(message);
    }

  private:
    std::string m_filename;
    std::string m_message;
};

class FileOpenError : public FileError
{
  public:
    FileOpenError(std::string filename) : FileError{std::move(filename)}
    {
        setMessage(std::format("Unable to open {}.", getFilename()));
    }
};

class FileReadError : public FileError
{
  public:
    FileReadError(std::string filename, size_t lineNumber)
        : FileError{std::move(filename)}, m_lineNumber{lineNumber}
    {
        setMessage((std::format("Error reading {} at line {}.", getFilename(),
                                lineNumber)));
    }

    virtual size_t getLineNumber() const noexcept { return m_lineNumber; }

  private:
    size_t m_lineNumber{};
};

int main()
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    try {
        std::vector<int> myInts{readIntegerFile(filename)};
        for (auto const &element : myInts) {
            std::cout << element << " -- ";
        }
        std::cout << std::endl;
    } catch (FileError const &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

std::vector<int> readIntegerFile(std::string filename)
{
    std::filesystem::path path_{"Project14/docs"};
    std::ifstream inputStream{path_.append(filename.data())};

    if (inputStream.fail()) {
        throw FileOpenError{filename};
    }

    std::vector<int> integers;
    size_t lineNumber{};
    while (!inputStream.eof()) {
        std::string line;
        std::getline(inputStream, line);
        lineNumber++;

        std::istringstream lineStream{line};

        int temp{};
        while (lineStream >> temp) {
            integers.push_back(temp);
        }
        if (!lineStream.eof()) {
            throw FileReadError{filename, lineNumber};
        }
    }
    return integers;
}