cmake_minimum_required(VERSION 3.3)
project(simple_slam)

find_package(Eigen3 REQUIRED)
find_package(OpenCV 3 QUIET)
find_package(Sophus REQUIRED)
if (NOT OpenCV_FOUND)
    find_package(OpenCV 4 REQUIRED)
endif ()
find_package(Boost REQUIRED COMPONENTS system filesystem thread date_time)
message(STATUS "OPENCV: " ${OpenCV_VERSION} " | BOOST: " ${Boost_VERSION})

# Default build as release
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

# Enable compile optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fsee -fomit-frame-pointer -fno-signed-zeros -fno-math-errno -funroll-loops")

# Enable debug flags (use if you want to debug in gdb)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -Wall -Wuninitialized -Wmaybe-uninitialized -fno-omit-frame-pointer")

include_directories(
    src
    ${EIGEN3_INCLUDE_DIR}
    ${Sophus_LIBRARIES}
    ${Boost_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} SHARED
src/cam/CamBase.h
src/cam/CamBase.cpp

src/database/feature.h

src/database/frame.cpp
src/database/frame.h

src/database/mappoint.cpp
src/database/mappoint.h

src/database/sensor_data.h

src/utils/print.cpp
src/utils/print.h
src/utils/common_include.h
)

target_link_libraries(${PROJECT_NAME}
${OpenCV_LIBS}
)