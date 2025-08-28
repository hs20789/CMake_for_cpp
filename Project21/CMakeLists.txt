# 실행 파일
foreach(num RANGE 1 5)   
    add_executable(ch21_${num} "src/ch21_${num}.cpp")
endforeach()

# 연습 문제
foreach(num RANGE 1 4)
    add_executable(ch21_prac${num} "solution/ch21_prac${num}.cpp")
endforeach()
