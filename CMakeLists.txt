cmake_minimum_required(VERSION 3.12)
project(SDL_GameEngine)

# Включаем генерацию compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Задаем переменные для директорий
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

# Добавляем подмодули Git из .gitmodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
    message(STATUS "Submodule update")
    execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE GIT_SUBMOD_RESULT
    )
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
endif()

# ====================

# 1. Try system SDL3 package first
find_package(SDL3 QUIET)
if(SDL3_FOUND)
    message(STATUS "Using SDL3 via find_package")
endif()

# 2. Try using a vendored SDL library
if(NOT SDL3_FOUND AND EXISTS "${EXTERNAL_DIR}/SDL/CMakeLists.txt")
    add_subdirectory(${EXTERNAL_DIR}/SDL)
    message(STATUS "Using SDL3 via add_subdirectory")
    set(SDL3_FOUND TRUE)
endif()

# ====================

# 1. Try system SDL3_ttf package first
find_package(SDL3_ttf QUIET)
if(SDL3_ttf_FOUND)
    message(STATUS "Using SDL3_ttf via find_package")
endif()

# 2. Try using a vendored SDL library
if(NOT SDL3_ttf_FOUND AND EXISTS "${EXTERNAL_DIR}/SDL_ttf/CMakeLists.txt")
    add_subdirectory(${EXTERNAL_DIR}/SDL_ttf)
    message(STATUS "Using SDL3_ttf via add_subdirectory")
    set(SDL3_FOUND TRUE)
endif()

# ====================

# Добавляем пути к заголовочным файлам
include_directories(${INCLUDE_DIR})

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_ttf::SDL3_ttf SDL3::SDL3)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

include(${SRC_DIR}/src.cmake)
