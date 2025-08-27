# 실행 파일
foreach(num RANGE 1 15)   
    add_executable(ch20_${num} "src/ch20_${num}.cpp")
endforeach()