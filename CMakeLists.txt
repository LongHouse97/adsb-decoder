# 
# (C) aviware 2022
# Author: Arian Ghoddousi
# Contact: arian.ghoddousi@aviware.net 
# Date: 06 Feb 2022
#

cmake_minimum_required(VERSION 3.16.3)

project(ads-b_decoder LANGUAGES CXX VERSION 0.1.0)
set(package_release 1$ENV{CUSTOM_BUILD_TAG})

add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:-Wall>")
add_compile_options(-g -fpic)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
add_subdirectory(src)