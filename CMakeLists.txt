cmake_minimum_required(VERSION 3.5)

project(firmata LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)

add_library(firmata STATIC
  asio_or_boost.hpp
  call_chain.hpp
  client.cpp
  client.hpp
  debounce.cpp
  debounce.hpp
  encoder.cpp
  encoder.hpp
  io_base.hpp
  pin.cpp
  pin.hpp
  pins.cpp
  pins.hpp
  serial_port.cpp
  serial_port.hpp
  types.cpp
  types.hpp
)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED system)

target_include_directories(firmata PUBLIC Threads::Threads Boost::system "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(firmata PRIVATE Threads::Threads Boost::system)
target_compile_definitions(firmata PRIVATE FIRMATA_LIBRARY)
