#include <format>
#include <iostream>

import KeyValuePair2;

int main()
{
    KeyValuePair<int, double> kv1{33, 3.14};
    std::cout << std::format("kv1 => key: {}, value: {}\n", kv1.getKey(),
                             kv1.getValue());

    KeyValuePair kv2{188, 2.22};
    std::cout << std::format("kv2 => key: {}, value: {}\n", kv2.getKey(),
                             kv2.getValue());


}