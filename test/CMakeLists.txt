cmake_minimum_required(VERSION 3.16)
project(test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-static -Ofast -Wall -Wextra -Werror)
add_compile_options(-fsanitize=address -fsanitize=undefined)
add_link_options(-fsanitize=address -fsanitize=undefined)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
    test.cpp
    test_main.cpp
    test_big.cpp
    test_small.cpp
    ../src/big_words.cpp
    ../src/trie.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
target_link_libraries(${PROJECT_NAME}
    GTest::Main
    Threads::Threads
)
