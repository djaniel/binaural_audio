cmake_minimum_required(VERSION 3.15)
set(CMAKE_BUILD_TYPE Debug)
#add_compile_options(-fsanitize=address)
#add_link_options(-fsanitize=address)

project(binauralplayer VERSION 0.0.1)

include_directories(
  include
)

option(SAF_PERFORMANCE_LIB SAF_USE_OPEN_BLAS_AND_LAPACKE)

add_subdirectory(SDKs)

add_executable(${PROJECT_NAME} src/main.cpp 
    src/binauralplayer/binauralplayer.cpp
    src/binauralplayer/PluginProcessor.cpp
    src/tinywav/tinywav.c)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE 
    saf
    -lm
    saf_example_ambi_roomsim
  )
