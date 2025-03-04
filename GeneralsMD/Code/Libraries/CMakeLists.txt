FetchContent_Declare(
    miles
    GIT_REPOSITORY https://github.com/TheSuperHackers/miles-sdk-stub.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(miles)

add_subdirectory(Source/EABrowserDispatch)
add_subdirectory(Source/WWVegas/WWDebug)
add_subdirectory(Source/WWVegas/WWLib)
add_subdirectory(Source/WWVegas/WWSaveLoad)
add_subdirectory(Source/WWVegas/WWMath)
add_subdirectory(Source/WWVegas/WWAudio)
add_subdirectory(Source/WWVegas/WW3D2)