set(SOURCE_WWDEBUG
    wwdebug.cpp
    wwmemlog.cpp
    wwprofile.cpp
)

add_library(WWDebug STATIC ${SOURCE_WWDEBUG})

target_include_directories(WWDebug PUBLIC 
    #${CMAKE_SOURCE_DIR}/GameEngine/Include 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/../WWLib
)