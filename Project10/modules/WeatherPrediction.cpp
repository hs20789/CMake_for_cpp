#include <format>
#include <iosfwd>
#include <iostream>
#include <sstream>

module WeatherPrediction;

// WeatherPrediction::Impl member function


WeatherPrediction::~WeatherPrediction() {}

void WeatherPrediction::setCurrentTempFahrenheit(int temp)
{
    m_currentTempFahrenheit = temp;
}

void WeatherPrediction::setPositionOfJupiter(int distanceFromMars)
{
    m_distanceFromMars = distanceFromMars;
}

int WeatherPrediction::getTomorrowTempFahrenheit() const
{
    // Obviously, this is nonsense
    return (m_distanceFromMars / 1000) + m_currentTempFahrenheit;
}

double WeatherPrediction::getChanceOfRain() const
{
    // Obviously, this is nonsense too
    return 0.5;
}

void WeatherPrediction::showResult() const
{
    std::cout << std::format("Result: {} chance.  Temp. {}", getChanceOfRain() * 100,
                   getTomorrowTempFahrenheit())
         << std::endl;
}

std::string WeatherPrediction::getTemperature() const
{
    std::stringstream ss;
    ss << m_currentTempFahrenheit;
    return ss.str();
}
