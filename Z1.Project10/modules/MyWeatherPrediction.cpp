#include <format>
#include <iostream>
#include <string>

module MyWeatherPrediction;

// MyWeatherPrediction::Impl member function definitions

int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius)
{
    int fahrenheit{static_cast<int>((celsius * (9.0 / 5.0)) + 32)};
    return fahrenheit;
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit)
{
    int celsius{static_cast<int>((fahrenheit - 32) * (5.0 / 9.0))};
    return celsius;
}

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
    int fahrenheitTemp{convertCelsiusToFahrenheit(temp)};
    setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
    int fahrenheitTemp{getTomorrowTempFahrenheit()};
    return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
    std::cout
        << std::format(
               "Tomorrow will be {} degrees Celsius ({} degrees Fahrenheit)",
               getTomorrowTempCelsius(), getTomorrowTempFahrenheit())
        << std::endl;
    std::cout << std::format("Chance of rain is {}%", getChanceOfRain() * 100)
              << std::endl;
    if (getChanceOfRain() > 0.5) {
        std::cout << "Bring Umbrella!" << std::endl;
    }
}

std::string MyWeatherPrediction::getTemperature() const
{
    // 참고: \u00B0은 ISO/IEC 10646 표준의 온도 기호다.
    return WeatherPrediction::getTemperature() + "\u00B0F";
}
