add_executable(ch18_1 "src/ch18_1.cpp")

add_executable(ch18_2 "src/ch18_2.cpp")

add_executable(ch18_3 "src/ch18_3.cpp")

add_executable(ch18_4 "src/ch18_4.cpp")

add_executable(ch18_5 "src/ch18_5.cpp")

add_executable(ch18_6 "src/ch18_6.cpp")

add_executable(ch18_7 "src/ch18_7.cpp")

add_executable(ch18_8 "src/ch18_8.cpp")

add_executable(ch18_9 "src/ch18_9.cpp")

add_executable(ch18_10 "src/ch18_10.cpp")

add_executable(ch18_11 "src/ch18_11.cpp")

add_executable(ch18_12 "src/ch18_12.cpp")

add_executable(ch18_13 "src/ch18_13.cpp")

add_executable(ch18_14 "src/ch18_14.cpp")

add_executable(ch18_15 "src/ch18_15.cpp")

add_executable(ch18_16 "src/ch18_16.cpp")

add_executable(ch18_17 "src/ch18_17.cpp")

add_executable(ch18_18 "src/ch18_18.cpp")

add_executable(ch18_19 "src/ch18_19.cpp")

############################################################### 

# 연습문제 1
add_executable(ch18_prac1 "solution/prac1/ch18_prac1.cpp")

# 연습문제 2.
if (MSVC)
	add_library(ch18_m2)
	target_sources(ch18_m2
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"solution/prac2/Person.ixx"
						"solution/prac2/PhoneBook.ixx"
	)				
	add_executable(ch18_prac2 "solution/prac2/ch18_prac2.cpp")
	target_link_libraries(ch18_prac2 PRIVATE ch18_m2)
endif()