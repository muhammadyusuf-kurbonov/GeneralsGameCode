if (UNIX)

set(SOURCE_COMPAT
    module_compat.cpp
    string_compat.cpp
    thread_compat.cpp
    time_compat.cpp
    wchar_compat.cpp
    d3dx8_compat.cpp
    d3dx8math.cpp
)

list(TRANSFORM SOURCE_COMPAT PREPEND "Source/")

add_library(CompatLib STATIC ${SOURCE_COMPAT})

find_package(glm REQUIRED)
target_link_libraries(CompatLib PUBLIC glm::glm)

find_package(gli REQUIRED)
target_link_libraries(CompatLib PUBLIC gli)

target_include_directories(CompatLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

# Add an empty library and link it to libdxvk_d3d8.so.0
add_library(d3d8lib INTERFACE)
target_link_libraries(d3d8lib INTERFACE
    dxvk_d3d8
)

target_include_directories(d3d8lib INTERFACE
    ${CMAKE_SOURCE_DIR}/extern/dxvk-native/usr/include/dxvk
)

# Search library in dxvk-native folder
target_link_directories(d3d8lib INTERFACE
    ${CMAKE_SOURCE_DIR}/extern/dxvk-native/usr/lib
)

target_link_libraries(CompatLib PRIVATE d3d8lib)

endif()