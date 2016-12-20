
if (NOT DEFINED _TARGET_PLATFROM)
    set (_TARGET_PLATFORM "AVR")
endif()

if (${_TARGET_PLATFORM} STREQUAL "AVR")
    if (NOT DEFINED MCU)
        set (MCU atmega8)
    endif()

    if (NOT DEFINED FCPU)
        set (FCPU 7372800UL)
    endif()

    find_program (_CXX_COMPILER avr-g++)
    set (CMAKE_CXX_COMPILER ${_CXX_COMPILER})

    find_program (_AR avr-ar)
    set (CMAKE_AR ${_AR})

    find_program(_RANLIB avr-ranlib)
    set (CMAKE_RANLIB ${_RANLIB})

    set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Os -mmcu=${MCU} -DF_CPU=${FCPU}")
    set(FLASH_FLAGS "-R .eeprom -R .fuse -R .lock -R .signature")

elseif (${_TARGET_PLATFORM} STREQUAL "RASPBERRYPI")
    find_program(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++
        /usr/local/linaro/arm-linux-gnueabihf-raspbian/bin/)
    find_program(CMAKE_AR arm-linux-gnueabihf-ar
        /usr/local/linaro/arm-linux-gnueabihf-raspbian/bin/)
    find_program(CMAKE_RANLIB arm-linux-gnueabihf-ranlib
        /usr/local/linaro/arm-linux-gnueabihf-raspbian/bin/)

    set (CMAKE_CXX_FLAGS "-std=c++0x -Wall -Os")

else()
    message (FATAL_ERROR "unknown TARGET_PLATFORM = ${_TARGET_PLATFORM}")
endif()
