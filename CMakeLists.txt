cmake_minimum_required(VERSION 3.28)

set(PROJECT_MAJOR_VERSION "0" CACHE INTERNAL "Major version")
set(PROJECT_MINOR_VERSION "0" CACHE INTERNAL "Minor version")
set(PROJECT_PATCH_VERSION "0" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION} CACHE INTERNAL "Project version")

project(template_cpp_project VERSION ${PROJECT_VERSION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/generated)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/current_version.hpp.cmake_gen
    ${CMAKE_BINARY_DIR}/generated/current_version.hpp
)

add_executable(template_cpp_project main.cpp)
add_library(emptylibrary EmptyLibrary.cpp)
add_executable(test_executable test_entrypoint.cpp)

set_target_properties(template_cpp_project emptylibrary test_executable PROPERTIES
    CMAKE_CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(emptylibrary
    PUBLIC "${CMAKE_BINARY_DIR}/generated"
)

target_include_directories(test_executable
    PUBLIC "${CMAKE_BINARY_DIR}/generated"
)

target_include_directories(emptylibrary
    PRIVATE "${CMAKE_BINARY_DIR}"
)

set_target_properties(test_executable PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(template_cpp_project PRIVATE
    emptylibrary
)

target_link_libraries(test_executable
    ${Boost_LIBRARIES}
    emptylibrary
)

if (MSVC)
    target_compile_options(template_cpp_project PRIVATE
        /W4
    )
    target_compile_options(emptylibrary PRIVATE
        /W4
    )
    target_compile_options(test_executable PRIVATE
        /W4
    )
else ()
    target_compile_options(template_cpp_project PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(emptylibrary PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_executable PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif ()

install(TARGETS template_cpp_project RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT donotwritehere@gmail.com)

include(CPack)

enable_testing()

add_test(test_executable test_executable)
