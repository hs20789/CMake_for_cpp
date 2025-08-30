module;

#include <iostream>

export module Simulator_prac1;

export namespace Simulator
{
    class CarSimulator
    {
      public:
        CarSimulator() { std::cout << "CarSimulator's Default ctor called!\n"; }
    };

    class BikeSimulator
    {
      public:
        BikeSimulator()
        {
            std::cout << "BikeSimulator's Default ctor called!\n";
        }
    };
} // namespace Simulator