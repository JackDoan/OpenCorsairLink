cmake_minimum_required(VERSION 3.15)
project(OpenCorsairLink C)

set(CMAKE_C_STANDARD 11)

find_path(LIBUSB_INCLUDE_DIR
        NAMES libusb.h
        PATH_SUFFIXES "include" "libusb" "libusb-1.0")

find_library(LIBUSB_LIBRARY
        NAMES usb-1.0)

execute_process(
        COMMAND git rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
        COMMAND git log -1 --format=%h
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_definitions(-DVERSION=\"v0.9.0.0-${GIT_VERSION}\")

include_directories(extras/cmocka-1.1.1/include)
include_directories(extras/cmocka-1.1.1/include/cmockery)
include_directories(${LIBUSB_INCLUDE_DIR})
include_directories(include)
include_directories(include/logic)
include_directories(include/lowlevel)
include_directories(include/protocol)
include_directories(protocol/asetek)
include_directories(protocol/asetekpro)
include_directories(protocol/commanderpro)
include_directories(protocol/coolit)
include_directories(protocol/rmi)



add_executable(OpenCorsairLink
        include/logic/options.h
        include/logic/scan.h
        include/lowlevel/asetek.h
        include/lowlevel/commanderpro.h
        include/lowlevel/coolit.h
        include/lowlevel/rmi.h
        include/protocol/asetek.h
        include/protocol/asetekpro.h
        include/protocol/commanderpro.h
        include/protocol/coolit.h
        include/protocol/rmi.h
        include/common.h
        include/device.h
        include/driver.h
        include/print.h
        logic/settings/commanderpro.c
        logic/settings/hydro_asetek.c
        logic/settings/hydro_asetekpro.c
        logic/settings/hydro_coolit.c
        logic/settings/psu.c
        logic/options.c
        logic/options_fan.c
        logic/options_led.c
        logic/options_pump.c
        logic/scan.c
        lowlevel/asetek.c
        lowlevel/commanderpro.c
        lowlevel/coolit.c
        lowlevel/rmi.c
        protocol/asetek/core.c
        protocol/asetek/fan.c
        protocol/asetek/led.c
        protocol/asetek/pump.c
        protocol/asetek/temperature.c
        protocol/asetekpro/core.c
        protocol/asetekpro/fan.c
        protocol/asetekpro/led.c
        protocol/asetekpro/pump.c
        protocol/asetekpro/temperature.c
        protocol/commanderpro/core.c
        protocol/commanderpro/fan.c
        protocol/commanderpro/led.c
        protocol/commanderpro/power.c
        protocol/commanderpro/temperature.c
        protocol/coolit/core.c
        protocol/coolit/fan.c
        protocol/coolit/led.c
        protocol/coolit/pump.c
        protocol/coolit/temperature.c
        protocol/rmi/core.c
        protocol/rmi/fan.c
        protocol/rmi/power.c
        protocol/rmi/temperature.c
        protocol/rmi/time.c
        device.c
        driver.c
        main.c
        print.c)

target_link_libraries(OpenCorsairLink ${LIBUSB_LIBRARY} m)
