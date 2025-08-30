foreach(num RANGE 1 5)
    add_executable(ch23_${num} "src/ch23_${num}.cpp")    
endforeach()

foreach(num RANGE 1 5)
    add_executable(ch23_prac${num} "solution/ch23_prac${num}.cpp")
endforeach()