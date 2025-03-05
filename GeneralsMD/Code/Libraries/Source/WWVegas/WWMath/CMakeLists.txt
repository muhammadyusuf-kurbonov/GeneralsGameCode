file(GLOB_RECURSE SOURCES_WWMATH
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.CPP
)

add_library(WWMath STATIC ${SOURCES_WWMATH})

# For d3dx8math.h
target_link_libraries(WWMath PRIVATE
    d3d8
)

target_link_libraries(WWMath PUBLIC
    WWLib WWSaveLoad
)

target_include_directories(WWMath PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)