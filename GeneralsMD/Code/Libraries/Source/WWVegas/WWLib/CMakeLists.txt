file(GLOB_RECURSE SOURCES_WWLIB
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.CPP
)

add_library(WWLib STATIC ${SOURCES_WWLIB})

target_link_libraries(WWLib PUBLIC
    WWDebug
)

target_link_libraries(WWLib PRIVATE
    gnu_regex
)