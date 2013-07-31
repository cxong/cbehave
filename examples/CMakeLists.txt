add_executable(calculator_test calculator_test.c calculator.c)
target_link_libraries(calculator_test cbehave)

add_executable(calculator_test_c90 calculator_test_c90.c calculator.c)
target_link_libraries(calculator_test_c90 cbehave)

add_executable(mock_test mock_test.c)
target_link_libraries(mock_test cbehave)

add_executable(product_database_test product_database_test.c product_database.c database.h)
target_link_libraries(product_database_test cbehave)

add_executable(string_test string_test.c)
target_link_libraries(string_test cbehave)

add_executable(text_editor_test text_editor_test.c)
target_link_libraries(text_editor_test cbehave)