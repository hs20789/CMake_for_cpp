#include <bit>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>

int main()
{
    std::fstream fst{"Project16/docs/bit.txt", std::ios_base::out};
    fst << std::popcount(0b10101010u) << std::endl;

    uint8_t value{0b11101011u};
    fst << std::countl_one(value) << std::endl;
    fst << std::countr_one(value) << std::endl;

    value = 0b10001000u;

    fst << std::format("bit ceil({0:08b} = {0}) = {1:08b} = {1}", value,
                       std::bit_ceil(value))
        << std::endl;

    fst << std::format("bit floor({0:08b} = {0}) = {1:08b} = {1}", value,
                       std::bit_floor(value))
        << std::endl;
}