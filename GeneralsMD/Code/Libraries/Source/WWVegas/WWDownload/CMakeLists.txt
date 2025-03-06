set(SOURCES_WWDOWNLOAD Download.cpp FTP.CPP registry.cpp urlBuilder.cpp)

add_library(WWDownload STATIC ${SOURCES_WWDOWNLOAD})

target_include_directories(WWDownload PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)