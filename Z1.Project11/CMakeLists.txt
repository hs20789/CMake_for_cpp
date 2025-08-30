# 실행 파일 1. 모듈 사용 => MSVC 전용
if (MSVC)
	add_executable(ch11_1 "src/ch11_1.cpp")
	target_sources(ch11_1 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
					"modules/Person.ixx")
endif()
				   
##############################################################################

# 연습 문제 1. 
if (MSVC)
	add_library(Simulator_prac1)
	target_sources(Simulator_prac1 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"modules/Simulator_prac1.ixx"
	) 

	add_executable(ch11_prac1 "src/ch11_prac1.cpp")
	target_link_libraries(ch11_prac1 PRIVATE Simulator_prac1)
endif()


# 연습 문제 2.
if (MSVC)
	add_library(Simulator_prac2)
	target_sources(Simulator_prac2 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
							"modules/Simulator_prac2.ixx"

					PRIVATE # 모듈 구현부
						"modules/impl/BikeSimulator_prac2.cpp"
						"modules/impl/CarSimulator_prac2.cpp"
	) 

	add_executable(ch11_prac2 "src/ch11_prac2.cpp")
	target_link_libraries(ch11_prac2 PRIVATE Simulator_prac2)
endif()


# 연습 문제 3.
if (MSVC)
	add_library(Simulator_prac3)
	target_sources(Simulator_prac3 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
							"modules/Simulator_prac3.ixx"
							"modules/impl/BikeSimulator_prac3.ixx"
							"modules/impl/CarSimulator_prac3.ixx"
							"modules/impl/Simulator_internals.cpp"
	) 

	add_executable(ch11_prac3 "src/ch11_prac3.cpp")
	target_link_libraries(ch11_prac3 PRIVATE Simulator_prac3)
endif()