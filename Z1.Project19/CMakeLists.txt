add_executable(ch19_1 "src/ch19_1.cpp")

add_executable(ch19_2 "src/ch19_2.cpp" "src/ch19_2_2.cpp" "include/Employee.h")
target_include_directories(ch19_2 PUBLIC include)

add_executable(ch19_3 "src/ch19_3.cpp")

add_executable(ch19_4 "src/ch19_4.cpp")

add_executable(ch19_5 "src/ch19_5.cpp")

add_executable(ch19_prac1 "solution/ch19_prac1.cpp")

add_executable(ch19_prac2 "solution/ch19_prac2.cpp")

add_executable(ch19_prac3 "solution/ch19_prac3.cpp")

add_executable(ch19_prac4 "solution/ch19_prac4.cpp")

add_executable(ch19_prac5 "solution/ch19_prac5.cpp")
