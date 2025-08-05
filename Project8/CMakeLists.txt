if(MSVC)
    add_executable(ch8_1 "src/ch8_1.cpp")
    target_sources(ch8_1 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/SpreadsheetCell.ixx")
endif()

add_executable(ch8_test "src/ch8_test.cpp")


if(MSVC)
    add_executable(ch8_2 "src/ch8_2.cpp")
    target_sources(ch8_2 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/SpreadsheetCell.ixx")
endif()

add_executable(ch8_prac1 "solution/ch8_prac1.cpp")


if(MSVC)
    add_executable(ch8_prac2 "solution/ch8_prac2.cpp")
    target_sources(ch8_prac2 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "solution/ch8_m2.ixx")
endif()


if(MSVC)
    add_executable(ch8_prac3 "solution/ch8_prac3.cpp")
    target_sources(ch8_prac3 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "solution/ch8_m3.ixx")
endif()


if(MSVC)
    add_executable(ch8_prac4 "solution/ch8_prac4.cpp")
    target_sources(ch8_prac4 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "solution/ch8_m4.ixx")
endif()
