file(GLOB_RECURSE SOURCES_WWSAVELOAD
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.CPP
)

add_library(WWSaveLoad STATIC ${SOURCES_WWSAVELOAD})

target_link_libraries(WWSaveLoad PUBLIC
    WWLib
)

target_include_directories(WWSaveLoad PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../WWMath
)

target_include_directories(WWSaveLoad PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
)