set(SOURCES_MILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/MilesAudioDevice/MilesAudioManager.cpp
)

set(SOURCES_BINK
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/VideoDevice/Bink/BinkVideoPlayer.cpp
)

file(GLOB_RECURSE SOURCES_W3DDevice
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/W3DDevice/*.cpp
)

file(GLOB_RECURSE SOURCES_WIN32Device
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/W3DDevice/*.cpp
)

add_library(GameEngineDevice STATIC 
    ${SOURCES_W3DDevice} 
    ${SOURCES_WIN32Device}
    ${SOURCES_MILES}
    ${SOURCES_BINK}
)

target_include_directories(GameEngineDevice PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${CMAKE_SOURCE_DIR}/Libraries/Include
)

target_link_libraries(GameEngineDevice PRIVATE WW3D2 GameEngine)