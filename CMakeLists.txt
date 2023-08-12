cmake_minimum_required(VERSION 3.12)
project(SDL_GameEngine VERSION 0.2 DESCRIPTION "GameEngine on SDL v0.2")

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
    set(SDL3_ttf_FOUND TRUE)
endif()

# ====================

# 1. Try system SDL3_image package first
find_package(SDL3_image QUIET)
if(SDL3_image_FOUND)
    message(STATUS "Using SDL3_image via find_package")
endif()

# 2. Try using a vendored SDL library
if(NOT SDL3_image_FOUND AND EXISTS "${EXTERNAL_DIR}/SDL_image/CMakeLists.txt")
    add_subdirectory(${EXTERNAL_DIR}/SDL_image)
    message(STATUS "Using SDL3_image via add_subdirectory")
    set(SDL3_image_FOUND TRUE)
endif()

# ====================

# Добавляем пути к заголовочным файлам

include(${SRC_DIR}/src.cmake)
include(GNUInstallDirs)

set(lib_name "SGE")

add_library(${lib_name} SHARED ${SOURCES})

target_include_directories(${lib_name} PUBLIC
    $<BUILD_INTERFACE:${INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>)
target_link_libraries(${lib_name} PUBLIC SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf SDL3::SDL3)

set_target_properties(${lib_name} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${lib_name} PROPERTIES PUBLIC_HEADER ${INCLUDE_DIR}/SGE.hpp)

install(TARGETS ${lib_name}
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY ${INCLUDE_DIR} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${lib_name})

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${lib_name})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})


# ====================

# Проверка форматирования с помощью clang-format
set(CLANG_FORMAT_COMMAND /usr/bin/clang-format-15)
set(CLANG_FORMAT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/.clang-format)

# Добавляем пользовательскую цель для автоматической правки кода
add_custom_target(
    clang-format-fix
    COMMAND ${CLANG_FORMAT_COMMAND} -style=file -i ${SOURCES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running clang-format to fix code style..."
    VERBATIM
)

# Добавляем правку кода к цели построения
add_dependencies(${PROJECT_NAME} clang-format-fix)
