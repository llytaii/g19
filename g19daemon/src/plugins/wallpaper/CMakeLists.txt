cmake_minimum_required(VERSION 3.1)

project(wallpaper)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/")

find_package(Qt5Core)
find_package(Qt5Gui)

include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${LIBUSB_1_INCLUDE_DIRS})

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -ggdb")

set(wallpaper_SRC
  wallpaper.cpp
)

qt5_add_resources(wallpaper_QRC wallpaper.qrc)

add_library(wallpaper SHARED ${wallpaper_SRC} ${wallpaper_QRC})
target_link_libraries(wallpaper ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES})

qt5_use_modules(wallpaper Core Gui)

message("Plugins dir ${PLUGINS_DIR}")
install(TARGETS wallpaper LIBRARY DESTINATION ${PLUGINS_DIR})
