file(GLOB_RECURSE SOURCES_WWSHADE
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(WWShade STATIC ${SOURCES_WWSHADE})

target_link_libraries(WWShade PUBLIC
    WWMath WW3D2 WWLib WWDebug
)