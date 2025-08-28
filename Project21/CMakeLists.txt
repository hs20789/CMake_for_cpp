# 실행 파일
foreach(num RANGE 1 6)   
    add_executable(ch21_${num} "src/ch21_${num}.cpp")
endforeach()
