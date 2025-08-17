add_executable(ch13_1 "src/ch13_1.cpp")

add_executable(ch13_2 "src/ch13_2.cpp")

add_executable(ch13_3 "src/ch13_3.cpp")

add_executable(ch13_4 "src/ch13_4.cpp")

add_executable(ch13_5 "src/ch13_5.cpp")

add_executable(ch13_6 "src/ch13_6.cpp")


if (MSVC)
	add_library(Person)
	target_sources(Person 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"solution/prac1/ch13_prac1.ixx"	
	)				
	add_executable(ch13_prac1 "solution/prac1/ch13_prac1.cpp")
	target_link_libraries(ch13_prac1 PRIVATE Person)
endif()

if (MSVC)
	add_library(Database)
	target_sources(Database 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"solution/prac1/ch13_prac1.ixx"	
						"solution/prac2/ch13_prac2.ixx"
	)				
	add_executable(ch13_prac2 "solution/prac2/ch13_prac2.cpp")
	target_link_libraries(ch13_prac2 PRIVATE Database)
endif()