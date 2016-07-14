cmake_minimum_required(VERSION 2.8)
project(cbehave C)

include_directories(..)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_BINARY_DIR}/..)

if(MSVC)
	add_definitions(-wd"4127" -wd"4102" -wd"4996")
else()
	if(NOT BEOS AND NOT HAIKU)
		add_definitions(-Wno-unused-label)
	endif()
endif()

add_executable(calculator_test calculator_test.c calculator.c)
target_link_libraries(calculator_test cbehave)

add_executable(mock_test mock_test.c)
target_link_libraries(mock_test cbehave)

add_executable(product_database_test product_database_test.c product_database.c database.h)
target_link_libraries(product_database_test cbehave)

add_executable(string_test string_test.c)
target_link_libraries(string_test cbehave)

add_executable(text_editor_test text_editor_test.c)
target_link_libraries(text_editor_test cbehave)
