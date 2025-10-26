cmake_minimum_required(VERSION 3.15)
project(genius_sensor)

set(CMAKE_CXX_STANDARD 17)

# Detect OS
if(APPLE)
    message(STATUS "Building for Mac -> MockGPIO")
    set(GPIO_SRC src/gpio_mock.cpp)
elseif(UNIX AND NOT APPLE)
    message(STATUS "Building for Raspberry Pi -> LgGPIO")
    set(GPIO_SRC src/gpio_lgpio.cpp)
endif()

add_executable(genius_sensor
    src/main.cpp
    src/sensor.cpp
    ${GPIO_SRC}
)

if(UNIX AND NOT APPLE)
    find_library(LGPIO_LIB lgpio)
    target_link_libraries(genius_sensor ${LGPIO_LIB} pthread rt)
endif()
