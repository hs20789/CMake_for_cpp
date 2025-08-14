# 10-1 상속을 이용한 클래스 구현
add_executable(ch10_1 "src/ch10_1.cpp")

# 10-2 코드 재사용을 위한 상속 - 모듈 사용 => MSVC 전용
if(MSVC)
    add_executable(ch10_2 "src/ch10_2.cpp" "modules/MyWeatherPrediction.cpp" "modules/WeatherPrediction.cpp")
    target_sources(ch10_2 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/WeatherPrediction.ixx"
    "modules/MyWeatherPrediction.ixx")
endif()

# 10-3 다형성을 위한 상속 - 모듈 사용 => MSVC 전용
if(MSVC)
    add_executable(ch10_3 "src/ch10_3.cpp")
    target_sources(ch10_3 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/SpreadsheetCell_ch10.ixx"
    "modules/StringSpreadsheetCell_ch10.ixx"
    "modules/DoubleSpreadsheetCell_ch10.ixx")
endif()

# 10-4 다중 상속
add_executable(ch10_4 "src/ch10_4.cpp")

# 10-5 상속과 관련되 흥미로운 문제들
add_executable(ch10_5 "src/ch10_5.cpp")

# 10-6 RTTI, 캐스트
add_executable(ch10_6 "src/ch10_6.cpp")

###################################################################################

## 연습문제 1~4. - 모듈 사용 => MSVC 전용
if(MSVC)
    add_executable(ch10_prac "solution/prac/ch10_prac.cpp")
    target_sources(ch10_prac PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "solution/prac/Person_ch10_prac.ixx"
    "solution/prac/Employee_ch10_prac.ixx"
    "solution/prac/Manager_ch10_prac.ixx"
    "solution/prac/HR_ch10_prac.ixx"
    "solution/prac/Director_ch10_prac.ixx")
endif()

