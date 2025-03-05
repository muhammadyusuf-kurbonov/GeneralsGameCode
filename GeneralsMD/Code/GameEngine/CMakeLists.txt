file(GLOB_RECURSE SOURCES_COMMON
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/*.cpp
)

# Remove Debug.cpp from the common sources for UNIX
if(UNIX)
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/System/Debug.cpp)
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/System/registry.cpp)
else()
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/System/DebugUnix.cpp)
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/System/RegistryUnix.cpp)
endif()

file(GLOB_RECURSE SOURCES_GAMECLIENT
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/GameClient/*.cpp
)

add_library(GameEngine STATIC ${SOURCES_COMMON} ${SOURCES_GAMECLIENT})

target_include_directories(GameEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Precompiled
)

target_include_directories(GameEngine PRIVATE
    ${CMAKE_SOURCE_DIR}/Libraries/Include
    # Used in Thing.h via WWMath
    ${CMAKE_SOURCE_DIR}/Libraries/Source/WWVegas
)

target_link_libraries(GameEngine PUBLIC WWLib)
target_link_libraries(GameEngine PRIVATE Compression)

if(WIN32)
    target_link_libraries(GameEngine PRIVATE d3d8 gamespy BrowserDispatch)
else()
    target_include_directories(GameEngine PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/extern/dxvk-native/usr/include/dxvk
        ${CMAKE_CURRENT_SOURCE_DIR}/extern/compat
    )
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")    
else()
    target_compile_options(GameEngine PRIVATE -Wno-invalid-offsetof)
endif()