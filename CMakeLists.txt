cmake_minimum_required(VERSION 3.15)
project(Clean_Boom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

include_directories(
        "D:/tuxiaolai/Dependencies/easyx4mingw_25.9.10/include"
        "C:/Users/Administrator/AppData/Local/Programs/Python/Python313/include"
)
link_directories(
        "D:/tuxiaolai/Dependencies/easyx4mingw_25.9.10/lib64"
        "C:/Users/Administrator/AppData/Local/Programs/Python/Python313/libs"
)

add_executable(Clean_Boom src/main.cpp
        src/Setting.cpp src/Settings.h
        src/Init.cpp src/Init.h
        src/Utils.cpp src/Utils.h
        src/Image.cpp src/Image.h
        src/Board.cpp src/Board.h
        src/Event.cpp src/Event.h
        #        src/Python_Helper.cpp src/Python_Helper.h
        src/Draw.cpp src/Draw.h
        src/Update.cpp src/Update.h
        src/Result.cpp src/Result.h
        src/Chord.cpp src/Chord.h
        src/Game.cpp src/Game.h
)

add_custom_command(
        TARGET Clean_Boom POST_BUILD
        COMMAND windres ${CMAKE_CURRENT_SOURCE_DIR}/Clean_Boom.rc -O coff -o ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Clean_Boom.res
        COMMENT "Compiling icon resources"
)

target_link_libraries(Clean_Boom libeasyxw.a gdi32 python313 -mwindows ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Clean_Boom.res)


set(Python_EXECUTABLE "C:/Users/Administrator/AppData/Local/Programs/Python/Python313/python.exe")

execute_process(
        COMMAND "${Python_EXECUTABLE}" -c "import pybind11; print(pybind11.get_cmake_dir())"
        OUTPUT_VARIABLE pybind11_CMAKE_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        RESULT_VARIABLE pybind11_CMAKE_RESULT
)

if(NOT pybind11_CMAKE_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to find pybind11 CMake directory using Python script.")
endif()

list(APPEND CMAKE_PREFIX_PATH ${pybind11_CMAKE_DIR})

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

set(GAME_SOURCES_FOR_PY
        src/Setting.cpp
        src/Init.cpp
        src/Utils.cpp
        src/Image.cpp
        src/Board.cpp
        src/Event.cpp
        src/Draw.cpp
        src/Update.cpp
        src/Result.cpp
        src/Chord.cpp
        src/Game.cpp
)

add_library(tuxiaolai_Clean_Boom_cpp MODULE ${GAME_SOURCES_FOR_PY} src/python_bindings.cpp)

target_link_libraries(tuxiaolai_Clean_Boom_cpp PRIVATE libeasyxw.a gdi32 pybind11::module -lpython313)

set_target_properties(tuxiaolai_Clean_Boom_cpp PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib_py
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib_py
)

set_target_properties(tuxiaolai_Clean_Boom_cpp PROPERTIES
        PREFIX ""
        SUFFIX ".pyd"
        CXX_STANDARD 17
)

target_include_directories(tuxiaolai_Clean_Boom_cpp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        "C:/Users/Administrator/AppData/Local/Programs/Python/Python313/include"
        "D:/tuxiaolai/Dependencies/easyx4mingw_25.9.10/include"
)