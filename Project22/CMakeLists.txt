# 실행 파일
foreach(num RANGE 1 6)
    add_executable(ch22_${num} "src/ch22_${num}.cpp")
endforeach()