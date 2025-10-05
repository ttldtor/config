cmake_minimum_required(VERSION 3.16)

project(inipp)

add_library(inipp INTERFACE)
add_library(inipp::inipp ALIAS inipp)

target_include_directories(inipp INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inipp>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(inipp INTERFACE cxx_std_11)

install(FILES inipp/inipp.h DESTINATION include/inipp)

install(TARGETS inipp
        EXPORT inippTargets
        INCLUDES DESTINATION include
)

install(EXPORT inippTargets
        FILE inippTargets.cmake
        NAMESPACE inipp::
        DESTINATION lib/cmake/inipp
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(unittest)
endif()
