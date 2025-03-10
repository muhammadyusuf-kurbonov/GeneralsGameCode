file(GLOB_RECURSE SOURCES_WWSHADE
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

if(WIN32 OR "${CMAKE_SYSTEM}" MATCHES "Windows")
    file(GLOB_RECURSE SHADER_FILES "*.vsh")
    list(APPEND SHADER_LIST ${SHADER_FILES})
    file(GLOB_RECURSE SHADER_FILES "*.psh")
    list(APPEND SHADER_LIST ${SHADER_FILES})
    foreach(shdfile ${SHADER_LIST})
        get_filename_component(shdfilename ${shdfile} NAME)
        add_custom_command(
            OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${shdfilename}_code.h
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/shdpp.exe ${shdfilename}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
        list(APPEND SOURCES_WWSHADE ${CMAKE_CURRENT_SOURCE_DIR}/${shdfilename}_code.h)
    endforeach()
endif()


add_library(WWShade STATIC ${SOURCES_WWSHADE})

target_link_libraries(WWShade PUBLIC
    WWMath WW3D2 WWLib WWDebug
)