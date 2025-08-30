module;

#include <format>
#include <iostream>

export module Simulator_prac3:BikeSimulator_prac3;
import :internals;

export namespace Simulator
{
    class BikeSimulator
    {
      public:
        BikeSimulator()
        {
            std::cout << "BikeSimulator::BikeSimulator()" << std::endl;
        }
        virtual void setOdometer(double miles)
        {
            std::cout << std::format("Bike can go {} miles({} KM)\n", miles,
                                     convertMilesToKm(miles));
        }
    };
} // namespace Simulator
