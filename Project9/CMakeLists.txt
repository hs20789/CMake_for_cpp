## 실행파일 1.
if(MSVC)
    add_executable(ch9_1 "src/ch9_1.cpp")
    target_sources(ch9_1 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/SpreadsheetCell_1.ixx"
    "modules/Spreadsheet_3.ixx")
endif()

## 테스트용 실행 파일
if(MSVC)
    add_executable(ch9_test "src/ch9_test.cpp")
    target_sources(ch9_test PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/SpreadsheetCell_1.ixx"
    "modules/Spreadsheet_test.ixx")
endif()


##############################################################################################
##############################################################################################
##############################################################################################
##############################################################################################
##############################################################################################
##############################################################################################
##############################################################################################
##############################################################################################

## Practice 1.
if(MSVC)
    add_executable(ch9_prac1 "solution/prac1/ch9_prac1.cpp")
    target_sources(ch9_prac1 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
    "solution/prac1/ch9_m1.ixx")
endif()


## Practice 2.
if(MSVC)
    add_executable(ch9_prac2 "solution/prac2/ch9_prac2.cpp")
    target_sources(ch9_prac2 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
    "solution/prac2/ch9_m2.ixx")
endif()


## Practice 3.
if(MSVC)
    add_executable(ch9_prac3 "solution/prac3/ch9_prac3.cpp")
    target_sources(ch9_prac3 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
    "solution/prac3/ch9_m3.ixx")
endif()


## Practice 4.
if(MSVC)
    add_executable(ch9_prac4 "solution/prac4/ch9_prac4.cpp"
                             "solution/prac4/ch9_m4.cpp")
    target_sources(ch9_prac4 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
    "solution/prac4/ch9_m4.ixx")
endif()