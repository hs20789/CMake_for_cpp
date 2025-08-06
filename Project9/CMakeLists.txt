## 연습용 실행파일
if(MSVC)
    add_executable(ch9_1 "src/ch9_1.cpp")
    target_sources(ch9_1 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES 
    "modules/SpreadsheetCell_1.ixx"
    "modules/Spreadsheet_2.ixx")
endif()

## 테스트용 실행 파일
add_executable(ch9_test "src/ch9_test.cpp")