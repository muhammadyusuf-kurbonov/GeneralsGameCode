set(PROFILE_SRC
    "_pch.cpp"
    "_pch.h"
    "internal_cmd.h"
    "internal_funclevel.h"
    "internal_highlevel.h"
    "internal_result.h"
    "internal.h"
    "profile_cmd.cpp"
    "profile_doc.h"
    "profile_funclevel.cpp"
    "profile_funclevel.h"
    "profile_highlevel.cpp"
    "profile_highlevel.h"
    "profile_result.cpp"
    "profile_result.h"
    "profile.cpp"
    "profile.h"
)

add_library(z_profile STATIC)

target_sources(z_profile PRIVATE ${PROFILE_SRC})

target_include_directories(z_profile INTERFACE
    .
)

target_link_libraries(z_profile PRIVATE
    core_config
    zi_always
)
