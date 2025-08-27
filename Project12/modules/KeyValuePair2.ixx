module;

#include <concepts>

export module KeyValuePair2;

export template <std::integral Key, std::floating_point Value>
class KeyValuePair
{
  private:
    Key m_key;
    Value m_value;

  public:
    KeyValuePair(Key const &key, Value const &value)
        : m_key{key}, m_value{value}
    {}

    void setKey(Key const &key) { m_key = key; }
    Key const &getKey() { return m_key; }

    void setValue(Value const &value) { m_value = value; }
    Value const &getValue() { return m_value; }
};