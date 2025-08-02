## ch07의 첫 번째 실행 파일
add_executable(ch07_1 "src/ch7_1.cpp")

## ch07의 두 번째 실행 파일
add_executable(ch07_2 "src/ch7_2.cpp")

## ch07의 세 번째 실행 파일 - 윈도우에서만 작동
if (MSVC)
	add_executable(ch07_3_MSVC "src/ch7_3_MSVC.cpp")
endif()

## ch07의 네 번째 실행 파일
add_executable(ch07_4 "src/ch7_4.cpp")