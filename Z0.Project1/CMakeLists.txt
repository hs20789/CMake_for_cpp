# CMakeList.txt: Project1에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.
#
if(MSVC)
    add_compile_options(/EHsc)
endif()

# 이 프로젝트의 실행 파일에 소스를 추가합니다.
## pro1의 실행 파일 생성
add_executable (pro1 "src/Project1.cpp" "include/Project1.h")



# Project1 Chapter1 day1 실행 파일
if(MSVC)
    add_executable(p1c1d1 "src/p1c1d1_msvc.cpp" "include/namespace.h")
    target_sources(p1c1d1 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/airline_ticket.ixx")


elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_executable(p1c1d1 "src/p1c1d1_gcc.cpp" "include/namespace.h")

endif()

## Project1 Chapter1 day2 실행 파일
add_executable(p1c1d2 "src/p1c1d2.cpp" "include/func.h" "src/func.cpp")

## 최종 프로젝트의 실행파일 추가 ** MSVC에서만 적용
#### 직원 정보 관리 시스템
#### 해당 프로그램에서 제공할 기능은 다음과 같습니다.
#### * 직원 채용과 해고
#### * 직원 승진과 좌천
#### * 과거와 현재의 직원 모두 조회
if(MSVC)
    add_executable(Final "src/final/Database.cpp" 
                         "src/final/Employee.cpp" 
                         "src/final/Main.cpp")
    target_sources(Final PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                        "modules/final/Database.ixx"
                        "modules/final/Employee.ixx")
endif()

## 모듈 통합 파일
if(MSVC)
    add_executable(Combination "src/final/Main_c.cpp")
    target_sources(Combination PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                        "modules/comb/Database_c.ixx"
                        "modules/comb/Employee_c.ixx")
endif()

## Employee 모듈 테스트
if(MSVC)
    add_executable(employeeTest "src/final/Employee.cpp" 
                                "src/final/EmployeeTest.cpp")
    target_sources(employeeTest PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                        "modules/final/Employee.ixx")
endif()


## Database 모듈 테스트
if(MSVC)
    add_executable(databaseTest "src/final/Database.cpp" 
                                "src/final/DatabaseTest.cpp"
                                "src/final/Employee.cpp")
    target_sources(databaseTest PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                        "modules/final/Database.ixx"
                        "modules/final/Employee.ixx")
endif()

##############################################################################################################
##############################################################################################################
##############################################################################################################
##############################################################################################################
##############################################################################################################
##############################################################################################################
## 연습문제 
##############################################################################################################
##############################################################################################################
##############################################################################################################
## 연습문제1: Employee 구조체를 HR이란 네임스페이스에 속하도록 수정
if(MSVC)
    add_executable(Prac1 "src/practice/prac1.cpp")
    target_sources(Prac1 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                         "modules/practice/employee_p1.ixx")
endif()
##############################################################################################################
## 연습문제2: 연습문제1에 열거 타입 멤버 title 추가
if(MSVC)
    add_executable(Prac2 "src/practice/prac2.cpp")
    target_sources(Prac2 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                         "modules/practice/employee_p2.ixx")
endif()
##############################################################################################################
## 연습문제3: 연습문제2에 + std::array 사용
if(MSVC)
    add_executable(Prac3 "src/practice/prac3.cpp")
    target_sources(Prac3 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                         "modules/practice/employee_p3.ixx")
endif()
##############################################################################################################
## 연습문제4: 연습문제3에 + std::vector 사용
if(MSVC)
    add_executable(Prac4 "src/practice/prac4.cpp")
    target_sources(Prac4 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                         "modules/practice/employee_p4.ixx")
endif()
##############################################################################################################
## 연습문제5: airline_ticket 모듈에 const 레퍼런스 사용
if(MSVC)
    add_executable(Prac5 "src/practice/prac5.cpp")
    target_sources(Prac5 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                         "modules/practice/airline_ticket_p5.ixx")
endif()
##############################################################################################################
## 연습문제6: 연습문제5에 우수 회원 번호 옵션 추가
if(MSVC)
    add_executable(Prac6 "src/practice/prac6.cpp")
    target_sources(Prac6 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
                         "modules/practice/airline_ticket_p6.ixx")
endif()



# TODO: 필요한 경우 테스트를 추가하고 대상을 설치합니다.

# 헤더 파일 검색 경로를 지정합니다.
target_include_directories(pro1 PUBLIC include)
if(TARGET p1c1d1)
    target_include_directories(p1c1d1 PUBLIC include)
endif()
target_include_directories(p1c1d2 PUBLIC include)


# if(MSVC)
#      
#    
# elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
# 
#
#endif()
