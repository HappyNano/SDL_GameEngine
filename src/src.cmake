# Рекурсивно добавляем исходные файлы в проект
function(add_sources_recursive dir)
    file(GLOB_RECURSE sources ${dir}/*.cpp ${dir}/*.c)
    list(APPEND all_sources ${sources})

    file(GLOB_RECURSE headers ${dir}/*.hpp ${dir}/*.h)
    list(APPEND all_headers ${headers})

    set(SOURCES ${SOURCES} ${sources} PARENT_SCOPE)

    foreach(subdir IN LISTS ARGV)
        if(IS_DIRECTORY ${dir}/${subdir})
            add_sources_recursive(${dir}/${subdir})
        endif()
    endforeach()
endfunction()

# Добавляем исходные файлы в проект
set(SOURCES "")
add_sources_recursive(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Добавляем исходные файлы в основной CMakeLists.txt
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES} ${HEADERS})