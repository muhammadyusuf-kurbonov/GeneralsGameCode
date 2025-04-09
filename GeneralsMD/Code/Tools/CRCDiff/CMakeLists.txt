add_executable(CRCDiff CRCDiff.cpp expander.cpp KVPair.cpp)
target_link_libraries(CRCDiff PRIVATE Compression)