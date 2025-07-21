# CMakeList.txt: Project1에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.
#
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 이 프로젝트의 실행 파일에 소스를 추가합니다.
add_executable (pro1 "src/Project1.cpp" "include/Project1.h")
add_executable (p1d1 "src/p1d1.cpp" "include/namespace.h")
add_executable (chap2 "src/chap2.cpp")

# TODO: 필요한 경우 테스트를 추가하고 대상을 설치합니다.

# 헤더 파일 검색 경로를 지정합니다.
target_include_directories(pro1 PUBLIC include)
target_include_directories(p1d1 PUBLIC include)
