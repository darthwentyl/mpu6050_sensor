set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wpedantic -lwiringPi")
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    ${PROJECT_SOURCES_DIR}/main.cpp
    ${PROJECT_SOURCES_DIR}/implementation/Mpu6050ReadData.cpp
    ${PROJECT_SOURCES_DIR}/implementation/AccelerometerMpu6050.cpp
    ${PROJECT_SOURCES_DIR}/implementation/GyroscopeMpu6050.cpp
    ${PROJECT_SOURCES_DIR}/implementation/Mpu6050.cpp
    ${PROJECT_SOURCES_DIR}/utils/AccelerometerHumanReadable.cpp
    ${PROJECT_SOURCES_DIR}/utils/GyroscopeHumanReadable.cpp
    ${PROJECT_SOURCES_DIR}/kalman_filter/KalmanFilterMpu6050.cpp
    ${PROJECT_SOURCES_DIR}/kalman_filter/CalculationRoll.cpp
    ${PROJECT_SOURCES_DIR}/kalman_filter/CalculationPitch.cpp
    ${PROJECT_SOURCES_DIR}/kalman_filter/KalmanMatrixOperation.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
