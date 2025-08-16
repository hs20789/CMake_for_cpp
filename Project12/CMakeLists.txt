if (MSVC)
	add_library(GameBoard)
	target_sources(GameBoard 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"modules/GameBoard.ixx"
						"modules/Grid.ixx"
					PRIVATE
						"modules/implement/GameBoard.cpp"
						
	)				
	add_executable(GameBoardTest "src/GameBoardTest.cpp")
	target_link_libraries(GameBoardTest PRIVATE GameBoard)
endif()


if (MSVC)
	add_library(KeyValuePair)
	target_sources(KeyValuePair 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"modules/KeyValuePair.ixx"						
	)				
	add_executable(ch12_1 "src/ch12_1.cpp")
	target_link_libraries(ch12_1 PRIVATE KeyValuePair)
endif()


if (MSVC)
	add_library(KeyValuePair2)
	target_sources(KeyValuePair2 
					PUBLIC # 공개 인터페이스
						FILE_SET cxx_modules TYPE CXX_MODULES FILES
						"modules/KeyValuePair2.ixx"						
	)				
	add_executable(ch12_2 "src/ch12_2.cpp")
	target_link_libraries(ch12_2 PRIVATE KeyValuePair2)
endif()


add_executable(concat "src/concat.cpp")