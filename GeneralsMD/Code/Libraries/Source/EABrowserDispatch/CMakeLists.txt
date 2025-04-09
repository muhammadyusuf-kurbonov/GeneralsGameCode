add_library(BrowserDispatch INTERFACE)

if(WIN32 OR "${CMAKE_SYSTEM}" MATCHES "Windows")
    add_custom_command(
        OUTPUT BrowserDispatch_i.c BrowserDispatch.h
        COMMAND midl.exe "${CMAKE_CURRENT_LIST_DIR}\\BrowserDispatch.idl" /header BrowserDispatch.h
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS "${CMAKE_CURRENT_LIST_DIR}/BrowserDispatch.idl"
        VERBATIM
    )
    add_library(BrowserDispatchWin STATIC BrowserDispatch_i.c)
    target_link_libraries(BrowserDispatch INTERFACE BrowserDispatchWin)
endif()

target_include_directories(BrowserDispatch INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/..)