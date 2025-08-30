# CMakeList.txt : 최상위 CMake 프로젝트 파일, 전역 구성을 수행하고
# 여기에 하위 프로젝트를 포함합니다.
#
cmake_minimum_required (VERSION 4.0.1)

# c++ 버전의 기본값을 c++23 으로 설정
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(MSVC)
	set(CMAKE_CXX_FLAGS "/utf-8")
endif()

# 지원되는 경우 MSVC 컴파일러에 대해 핫 다시 로드 사용하도록 설정합니다.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMake_for_cpp")

# 하위 프로젝트를 포함합니다.
#add_subdirectory ("Z0.Project1")
#add_subdirectory ("Z0.Project2")
#add_subdirectory ("Z0.Project7")
#add_subdirectory ("Z0.Project8")
#add_subdirectory ("Z0.Project9")
#add_subdirectory ("Z1.Project10")
#add_subdirectory ("Z1.Project11")
#add_subdirectory ("Z1.Project12")
#add_subdirectory ("Z1.Project13")
#add_subdirectory ("Z1.Project14")
#add_subdirectory ("Z1.Project15")
#add_subdirectory ("Z1.Project16")
#add_subdirectory ("Z1.Project17")
#add_subdirectory ("Z1.Project18")
#add_subdirectory ("Z1.Project19")
#add_subdirectory ("Z2.Project20")
#add_subdirectory ("Z2.Project21")
#add_subdirectory ("Z2.Project22")
add_subdirectory ("Z2.Project23")