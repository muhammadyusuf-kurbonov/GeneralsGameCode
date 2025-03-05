if (UNIX)

set(SOURCE_COMPAT
    module_compat.cpp
    string_compat.cpp
    thread_compat.cpp
    time_compat.cpp
    wchar_compat.cpp
)

list(TRANSFORM SOURCE_COMPAT PREPEND "Source/")

add_library(CompatLib STATIC ${SOURCE_COMPAT})

target_include_directories(CompatLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

endif()