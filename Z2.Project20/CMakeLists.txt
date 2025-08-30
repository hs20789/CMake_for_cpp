# 실행 파일
foreach(num RANGE 1 11)   
    add_executable(ch20_${num} "src/ch20_${num}.cpp")
endforeach()

foreach(num RANGE 1 4)
    add_executable(ch20_prac${num} "solution/prac${num}/ch20_prac${num}.cpp")
endforeach()