# Auto add file in workspace
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp )
 
foreach(sourcefile IN LISTS APP_SOURCES)
    string(REPLACE ".cpp" "" program ${sourcefile})
    add_executable(${program} ${sourcefile})
    target_link_libraries(${program} zmq)
endforeach(sourcefile)

add_executable(0605/stl/T1_syt.cpp)
add_executable(0605/stl/T2_syt.cpp)
add_executable(0605/stl/T3_syt.cpp)
add_executable(0605/stl/T4_syt.cpp)