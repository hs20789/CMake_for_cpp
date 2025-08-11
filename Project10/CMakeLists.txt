# 10-1 상속을 이용한 클래스 구현
add_executable(ch10_1 "src/ch10_1.cpp")

# 10-2 코드 재사용을 위한 상속 - 모듈 사용 => MSVC 전용
if(MSVC)
    add_executable(ch10_2 "src/ch10_2.cpp" "modules/MyWeatherPrediction.cpp" "modules/WeatherPrediction.cpp")
    target_sources(ch10_2 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/WeatherPrediction.ixx"
    "modules/MyWeatherPrediction.ixx")
endif()