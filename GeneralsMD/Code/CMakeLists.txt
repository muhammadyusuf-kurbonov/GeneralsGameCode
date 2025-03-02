# z stands for Zero Hour, i stands for Interface
add_library(zi_gameengine INTERFACE)
add_library(zi_gameengine_include INTERFACE)
add_library(zi_gameenginedevice_include INTERFACE)
add_library(zi_libraries_include INTERFACE)
add_library(zi_libraries_source INTERFACE)
add_library(zi_libraries_source_wwvegas INTERFACE)
add_library(zi_libraries_source_wwvegas_ww3d2 INTERFACE)
add_library(zi_libraries_source_wwvegas_wwdebug INTERFACE)
add_library(zi_libraries_source_wwvegas_wwlib INTERFACE)
add_library(zi_libraries_source_wwvegas_wwmath INTERFACE)
add_library(zi_libraries_source_wwvegas_wwsaveload INTERFACE)
add_library(zi_main INTERFACE)

target_include_directories(zi_gameengine INTERFACE "GameEngine")
target_include_directories(zi_gameengine_include INTERFACE "GameEngine/Include")
target_include_directories(zi_gameenginedevice_include INTERFACE "GameEngineDevice/Source")
target_include_directories(zi_libraries_include INTERFACE "Libraries/Include")
target_include_directories(zi_libraries_source INTERFACE "Libraries/Source")
target_include_directories(zi_libraries_source_wwvegas INTERFACE "Libraries/Source/WWVegas")
target_include_directories(zi_libraries_source_wwvegas_ww3d2 INTERFACE "Libraries/Source/WWVegas/WW3D2")
target_include_directories(zi_libraries_source_wwvegas_wwdebug INTERFACE "Libraries/Source/WWVegas/WWDebug")
target_include_directories(zi_libraries_source_wwvegas_wwlib INTERFACE "Libraries/Source/WWVegas/WWLib")
target_include_directories(zi_libraries_source_wwvegas_wwmath INTERFACE "Libraries/Source/WWVegas/WWMath")
target_include_directories(zi_libraries_source_wwvegas_wwsaveload INTERFACE "Libraries/Source/WWVegas/WWSaveLoad")
target_include_directories(zi_main INTERFACE "Main")

# Contains internal libraries
add_subdirectory(Libraries)

# Remove Debug.cpp from the common sources for UNIX
if(UNIX)
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Source/Common/System/Debug.cpp)
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Source/Common/System/registry.cpp)
else()
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Source/Common/System/DebugUnix.cpp)
    list(REMOVE_ITEM SOURCES_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Source/Common/System/RegistryUnix.cpp)
endif()

add_library(cnc-zero-hour-common STATIC ${SOURCES_COMMON})

target_include_directories(cnc-zero-hour-common PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/Include/Precompiled
    # Used in Thing.h via WWMath
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Source/WWVegas
    # Also pulls WWLib
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Source/WWVegas/WWLib
    # Pulled by wwstring.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Source/WWVegas/WWDebug
    # Required by DataChunk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Source/Compression
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/dxvk-native/usr/include/dxvk
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/compat
)

target_compile_options(cnc-zero-hour-common PRIVATE -Wno-invalid-offsetof)