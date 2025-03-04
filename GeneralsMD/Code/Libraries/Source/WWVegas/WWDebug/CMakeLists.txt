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

if(UNIX)
    target_compile_definitions(WWDebug PUBLIC
        -D_UNIX
    )
else()
    target_compile_definitions(WWDebug PUBLIC
        -DWINVER=0x400
        -D_WIN32_WINNT=0x0400
    )
endif()