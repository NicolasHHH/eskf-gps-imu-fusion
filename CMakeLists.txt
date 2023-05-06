cmake_minimum_required(VERSION 3.10)
project(gps_imu_fusion)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_OSX_ARCHITECTURES "arm64")


set(ALL_TARGET_LIBRARIES "")

include(cmake/eigen.cmake)
include(cmake/YAML.cmake)
include(cmake/protobuf.cmake)
include(cmake/global_definition.cmake)

# include_directories(3rd-party/GeographicLib/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(DEPS SHARED
    src/eskf.cpp
    src/gps_flow.cpp
    src/imu_flow.cpp
    src/eskf_flow.cpp
    src/observability_analysis.cpp
        3rd-party/GeographicLib/src/LocalCartesian.cpp
        3rd-party/GeographicLib/src/Geocentric.cpp
        3rd-party/GeographicLib/src/Math.cpp)

target_link_libraries(DEPS
    ${ALL_TARGET_LIBRARIES}
)

add_executable(gps_imu_fusion app/gps_imu_fusion.cpp)
target_link_libraries(gps_imu_fusion DEPS)

#################  TEST  #################
add_executable(test_gps test/test_gps.cpp)
target_link_libraries(test_gps DEPS)

add_executable(test_imu test/test_imu.cpp)
target_link_libraries(test_imu DEPS)

# Add your source files
add_executable(test_protobuf Protobuf/test_gnss_pb.cpp)
# Link the protobuf libraries to your project
target_link_libraries(test_protobuf DEPS)


