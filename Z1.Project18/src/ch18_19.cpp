#include <format>
#include <iostream>
#include <string>
#include <unordered_map>

void printMap(auto const &m)
{
    for (auto &[key, value] : m) {
        std::cout << std::format("{} (Phone: {})", key, value) << std::endl;
    }
    std::cout << "=========================" << std::endl;
}

int main()
{
    std::unordered_map<std::string, std::string> phoneBook{
        {"Marc G.", "123-4567889"},
        {"Scott K.", "654-987321"},
        {"HeonSu Jeong", "10-1234-5678"},
        {"James D.", "342-123125"},
        {"Edward K.", "231-211341"}};
    printMap(phoneBook);

    phoneBook.insert(std::make_pair("John D.", "321-987654"));
    phoneBook["Johan G."] = "963-25817";
    phoneBook["Freddy K."] = "39480-21311";
    phoneBook.erase("Freddy K.");
    printMap(phoneBook);

    size_t const bucket{
        phoneBook.bucket("HeonSu Jeong")}; // Marc. G. 가 있는 버킷의 인덱스
    std::cout << std::format(
        "Heonsu Jeong is in bucket {}/{} containing the following {} names:",
        bucket, phoneBook.bucket_count(), phoneBook.bucket_size(bucket));
    //
    int num{};
    auto localBegin{phoneBook.cbegin(bucket)};
    auto localEnd{phoneBook.cend(bucket)};
    for (auto iter{localBegin}; iter != localEnd; ++iter) {
        std::cout << std::format("\t{} (Phone: {})", iter->first, iter->second)
                  << std::endl;
    }
    std::cout << "*************************************************************"
                 "*****\n";

    std::cout << std::format("There are {} buckets\n",
                             phoneBook.bucket_count());
    std::cout << std::format("Average number of elements in a bucket is {}.\n",
                             phoneBook.load_factor());
}