cmake_minimum_required(VERSION 3.16)
project(jb-rider-test-task LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-static -Ofast -Wall -Wextra -Werror)

find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Concurrent REQUIRED)

add_subdirectory(test)

add_executable(${PROJECT_NAME}
    include/big_words.h
    include/model.h
    include/model_fwd.h
    include/trie.h
    include/view.h
    include/view.ui
    src/big_words.cpp
    src/main.cpp
    src/model.cpp
    src/trie.cpp
    src/view.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME}
    Threads::Threads
    Qt5::Widgets
    Qt5::Concurrent
)
