cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
#project(helloworld VERSION 0.0.1)

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

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(version_lib PRIVATE
        /W4
    )
#    target_compile_options(test_version PRIVATE
#        /W4
#    )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(version_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
#    target_compile_options(test_version PRIVATE
#        -Wall -Wextra -pedantic -Werror
#    )
endif()

install(TARGETS version_lib EXPORT versionLibTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)

install(FILES lib.h DESTINATION include)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)