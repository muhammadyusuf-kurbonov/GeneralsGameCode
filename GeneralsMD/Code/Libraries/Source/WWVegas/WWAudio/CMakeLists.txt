file(GLOB_RECURSE SOURCES_WWAUDIO
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.CPP
)

add_library(WWAudio STATIC ${SOURCES_WWAUDIO})

target_link_libraries(WWAudio PUBLIC
    WWMath milesstub
)

target_include_directories(WWAudio PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
)