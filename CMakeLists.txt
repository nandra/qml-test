cmake_minimum_required(VERSION 3.5)

project(qml)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECT_NAME}
    main.cpp
    main.qml
    liveimage.cpp
    imageprovider.cpp
)

find_package(Qt5Core)
find_package(Qt5Qml)
find_package(Qt5Gui)
find_package(Qt5Quick)
find_package(Qt5Mqtt)
find_package(Qt5Widgets)

target_link_libraries(${PROJECT_NAME}
   Qt5::Core 
   Qt5::Gui
   Qt5::Qml
   Qt5::Quick
   Qt5::Mqtt
   Qt5::Widgets
)

install(
  TARGETS ${PROJECT_NAME}
  RUNTIME
    DESTINATION bin
    COMPONENT runtime
)

