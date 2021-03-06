cmake_minimum_required(VERSION 2.8)
project(cbehave C)

include_directories(..)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_BINARY_DIR}/..)

if(MSVC)
	add_definitions(-wd"4127" -wd"4102" -wd"4996")
else()
	add_definitions(-Wno-unused-label)
	if("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
	else()
		add_definitions(-Wno-pointer-to-int-cast)
	endif()
endif()

enable_testing()

add_executable(calculator_test calculator_test.c calculator.c)
target_link_libraries(calculator_test cbehave)
add_test(NAME calculator_test COMMAND calculator_test)

add_executable(mock_test mock_test.c)
target_link_libraries(mock_test cbehave)
add_test(NAME mock_test COMMAND mock_test)

add_executable(product_database_test product_database_test.c product_database.c database.h)
target_link_libraries(product_database_test cbehave)
add_test(NAME product_database_test COMMAND product_database_test)

add_executable(string_test string_test.c)
target_link_libraries(string_test cbehave)
add_test(NAME string_test COMMAND string_test)

add_executable(text_editor_test text_editor_test.c)
target_link_libraries(text_editor_test cbehave)
add_test(NAME text_editor_test COMMAND text_editor_test)
