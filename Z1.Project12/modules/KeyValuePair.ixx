// Key와 Value라는 템플릿 타입 매개변수 두 개를 받는 KeyValuePair 클래스 템플릿

module;
#include <string>
#include <utility>
export module KeyValuePair;

export template <typename Key, typename Value> class KeyValuePair
{
  private:
    Key m_key;
    Value m_value;

  public:
    // key와 value을 인수로 받는 생성자
    KeyValuePair(Key const &key, Value const &value)
        : m_key{key}, m_value{value}
    {}
    KeyValuePair(Key &&key, Value &&value)
        : m_key{std::move(key)}, m_value{std::move(value)}
    {}

    void setKey(Key const &key) { m_key = key; }
    Key const &getKey() const { return m_key; }

    void setValue(Value const &value) { m_value = value; }
    Value const &getValue() const { return m_value; }
};

export template <> class KeyValuePair<char const *, char const *>
{
  private:
    std::string m_key;
    std::string m_value;

  public:
    KeyValuePair(const char *key, const char *value)
        : m_key{key}, m_value{value}
    {}

    const std::string &getKey() const { return m_key; }
    void setKey(const char *key) { m_key = key; }

    const std::string &getValue() const { return m_value; }
    void setValue(const char *value) { m_value = value; }
};