if(CMAKE_CXX_COMPILE_ID STREQUAL "GNU")
	set(CMAKE_BUILD_TYPE Debug)
endif()

## ch07의 첫 번째 실행 파일
add_executable(ch07_1 "src/ch7_1.cpp")

## ch07의 두 번째 실행 파일
add_executable(ch07_2 "src/ch7_2.cpp")

## ch07의 세 번째 실행 파일 
if (MSVC)
	add_executable(ch07_3_MSVC "src/ch7_3_MSVC.cpp")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_executable(ch07_3_GNU "src/ch7_3_GNU.cpp")
endif()

#####################################################################################
## 연습문제 7-3
add_executable(ch7_prac3 "solution/prac3.cpp")
