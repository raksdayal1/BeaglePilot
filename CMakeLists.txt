cmake_minimum_required(VERSION 3.10)
project(Autopilot)

include_directories(./include/)
include_directories(./include/mavlink/)

# link_directories(/home/debian/Autopilot/library/build/)
link_directories(./lib/)
file(GLOB AP_SRC ./src/*.cpp )

# add_executable(Autopilot ./src/main.cpp ./src/sensor.cpp ./src/rc.cpp ./src/globals.cpp)
add_executable(Autopilot ${AP_SRC})
target_link_libraries(Autopilot librobotics_cape.so pthread)