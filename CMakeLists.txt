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

# # 3. Download SDL, and use that.
# if(NOT SDL3_FOUND)
#     include(FetchContent)
#     set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library (if available)")
#     set(SDL_STATIC TRUE CACHE BOOL "Build a SDL static library (if available)")
#     FetchContent_Declare(
#         SDL
#         GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
#         GIT_TAG main  # Replace this with a particular git tag or git hash
#         GIT_SHALLOW TRUE
#         GIT_PROGRESS TRUE
#     )
#     message(STATUS "Using SDL3 via FetchContent")
#     FetchContent_MakeAvailable(SDL)
#     set_property(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/_deps/sdl-src" PROPERTY EXCLUDE_FROM_ALL TRUE)
# endif()

# ====================

# Добавляем пути к заголовочным файлам
include_directories(${INCLUDE_DIR})

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

include(${SRC_DIR}/src.cmake)
