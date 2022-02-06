# 
# (C) aviware 2022
# Author: Arian Ghoddousi
# Contact: arian.ghoddousi@aviware.net 
# Date: 06 Feb 2022
#

add_library(app_core SHARED "")

target_sources(app_core
    PRIVATE
        adsbcore.cpp
        adsbdecoder.cpp
)

target_include_directories(app_core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include/
        )

target_link_libraries(app_core 
    PUBLIC
        
)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} app_core)
