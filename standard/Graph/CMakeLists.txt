file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp )

foreach(sourcefile IN LISTS APP_SOURCES)
    string(REPLACE ".cpp" "" program ${sourcefile})
    add_executable(${program} ${sourcefile})
    target_link_libraries(${program} zmq)
endforeach(sourcefile)

add_subdirectory(./tarjan/)