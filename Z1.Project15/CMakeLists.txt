if (MSVC)
	add_library(SpreadsheetCell)
	target_sources(SpreadsheetCell 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"modules/SpreadsheetCell.ixx"	
	)				
	add_executable(ch15_1 "src/ch15_1.cpp")
	target_link_libraries(ch15_1 PRIVATE SpreadsheetCell)
endif()

add_executable(ch15_2 "src/ch15_2.cpp")

if (MSVC)
	add_library(ch15_m1)
	target_sources(ch15_m1 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"solution/prac1/ch15_prac1.ixx"	
	)				
	add_executable(ch15_prac1 "solution/prac1/ch15_prac1.cpp")
	target_link_libraries(ch15_prac1 PRIVATE ch15_m1)
endif()

if (MSVC)
	add_library(ch15_m2)
	target_sources(ch15_m2 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"solution/prac2/ch15_prac2.ixx"	
	)				
	add_executable(ch15_prac2 "solution/prac2/ch15_prac2.cpp")
	target_link_libraries(ch15_prac2 PRIVATE ch15_m2)
endif()

if (MSVC)
	add_library(ch15_m3)
	target_sources(ch15_m3 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"solution/prac3/ch15_prac3.ixx"	
	)				
	add_executable(ch15_prac3 "solution/prac3/ch15_prac3.cpp")
	target_link_libraries(ch15_prac3 PRIVATE ch15_m3)
endif()

if (MSVC)
	add_library(ch15_m4)
	target_sources(ch15_m4 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"solution/prac4/ch15_prac4.ixx"	
	)				
	add_executable(ch15_prac4 "solution/prac4/ch15_prac4.cpp")
	target_link_libraries(ch15_prac4 PRIVATE ch15_m4)
endif()