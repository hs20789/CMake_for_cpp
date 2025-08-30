module;

#include <format>
#include <iostream>

export module Simulator_prac3:CarSimulator_prac3;
import :internals;

export namespace Simulator
{
    class CarSimulator
    {
      public:
        CarSimulator()
        {
            std::cout << "CarSimulator::CarSimulator()" << std::endl;
        }
        virtual void setOdometer(double miles)
        {
            std::cout << std::format("Car can go {} miles({} KM)\n", miles,
                                     convertMilesToKm(miles));
        }
    };
} // namespace Simulator
