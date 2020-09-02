cmake_minimum_required(VERSION 3.10)
project(Data-Master)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(data
        src/data.cpp
        include/data.h
        include/BST/bst.h
        deps/rapidcsv.h
        include/List/List.h)

set_target_properties(data PROPERTIES LINKER_LANGUAGE CXX)


add_executable(example examples/example.cpp include/data.h)

add_executable(tests tests/tests.cpp deps/catch.hpp include/data.h tests/tests.cpp)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_custom_target(doc
        COMMAND rm -rf ../doc/html
        COMMAND doxygen ../doxyconfig
        COMMAND mv html ../doc
        COMMENT "Generate documentation")

install(TARGETS example DESTINATION ${PROJECT_SOURCE_DIR}/bin)


enable_testing()

add_test(NAME bstint
        COMMAND tests [bstint])

add_test(NAME bstchars
        COMMAND tests [bstchars])

add_test(NAME bstint-dupp
        COMMAND tests [bstint-dupp])

add_test(NAME ListInteger
        COMMAND tests [ListInteger])

add_test(NAME Size
        COMMAND tests [Size])

add_test(NAME pushback
        COMMAND tests [pushback])

add_test(NAME listErase
        COMMAND tests [listErase])

add_test(NAME listPlus
        COMMAND tests [listPlus])

add_test(NAME listBracket
        COMMAND tests [listBracket])

add_test(NAME ListTransform
        COMMAND tests [listTransform])

add_test(NAME valgrind
        COMMAND valgrind ./example)
