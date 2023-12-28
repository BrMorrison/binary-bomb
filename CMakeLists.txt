cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)

# Create the targets
set(SharedCFlags "-Og -fno-stack-protector")
set(PublicCFlags "-g")
set(PrivateCFlags "")

add_library(PubLib OBJECT src/bomb.c)
set_target_properties(PubLib PROPERTIES COMPILE_FLAGS "${PublicCFlags} ${SharedCFlags}")

add_library(PrivLib OBJECT src/secret.c)
set_target_properties(PrivLib PROPERTIES COMPILE_FLAGS "${PrivateCFlags} ${SharedCFlags}")

project(bomb)
add_executable(bomb $<TARGET_OBJECTS:PubLib> $<TARGET_OBJECTS:PrivLib>)
set_target_properties(bomb PROPERTIES COMPILE_FLAGS "-static")
