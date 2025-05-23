# Interface libraries to set common defines and includes, avoid duplication later
add_library(z_wwcommon INTERFACE)

target_compile_definitions(z_wwcommon INTERFACE
    #NOMINMAX
    WIN32_LEAN_AND_MEAN
)

target_link_libraries(z_wwcommon INTERFACE
    d3d8lib
    core_config
    core_utility
    core_wwcommon
    milesstub
    stlport
)

target_include_directories(z_wwcommon INTERFACE
    .
    WW3D2
    WWAudio
    Wwutil
)

add_subdirectory(WWAudio)
add_subdirectory(WWMath)
add_subdirectory(Wwutil)
add_subdirectory(WW3D2)
add_subdirectory(WWDownload)

# Helpful interface to bundle the ww modules together.
add_library(z_wwvegas INTERFACE)

target_include_directories(z_wwvegas INTERFACE
    .
    WW3D2
    WWAudio
    WWDownload
    Wwutil
)

target_link_libraries(z_wwvegas INTERFACE
    core_wwvegas
    z_ww3d2
    z_wwdownload
    z_wwmath
    z_wwutil
)
