#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

class IntWrapper
{
  public:
    IntWrapper(int i) : m_wrappedInt{i} {}
    int getValue() const { return m_wrappedInt; }
    bool operator==(IntWrapper const &) const = default;

  private:
    int m_wrappedInt{};
};

namespace std {
    template <> struct hash<IntWrapper>
    {
        size_t operator()(IntWrapper const &x) const
        {
            return std::hash<int>{}(x.getValue());
        }
    };
} // namespace std

int main()
{
    std::unordered_map<int, std::string> m{
        {1, "Item 1"}, {2, "Item 2"}, {3, "Item 3"}, {4, "Item 4"}};

    for (auto const &[key, value] : m) {
        std::cout << key << " = " << value << std::endl;
    }

    for (auto const &p : m) {
        std::cout << p.first << " = " << p.second << std::endl;
    }
    std::cout << "Bucket Count: " << m.bucket_count() << std::endl;
}