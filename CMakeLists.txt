cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.3)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)
add_library(version_lib STATIC lib.cpp lib.h)

set_target_properties(helloworld_cli PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON 
)

target_include_directories(version_lib
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(helloworld_cli
    PRIVATE
    version_lib
)

install(TARGETS version_lib EXPORT versionLibTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)

install(FILES lib.h DESTINATION include)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)