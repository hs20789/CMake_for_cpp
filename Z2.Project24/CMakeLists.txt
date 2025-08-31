# 실행 파일
foreach(num RANGE 1 2)
    add_executable(ch24_${num} "src/ch24_${num}.cpp")
endforeach()

# 연습 파일
foreach(num RANGE 1 4)
    add_executable(ch24_prac${num} "solution/ch24_prac${num}.cpp")
endforeach()
