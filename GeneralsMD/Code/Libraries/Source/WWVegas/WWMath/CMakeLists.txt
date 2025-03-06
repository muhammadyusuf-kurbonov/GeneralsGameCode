file(GLOB_RECURSE SOURCES_WWMATH
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.CPP
)

add_library(WWMath STATIC ${SOURCES_WWMATH})

target_link_libraries(WWMath PUBLIC
    WWLib WWSaveLoad
)

target_include_directories(WWMath PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

if(SAGE_USE_GLM)
    find_package(glm REQUIRED)
    target_compile_definitions(WWMath PUBLIC
        -DSAGE_USE_GLM
    )
    target_link_libraries(WWMath PUBLIC glm::glm)
else()
    # For d3dx8math.h
    target_link_libraries(WWMath PRIVATE d3d8lib)
endif()