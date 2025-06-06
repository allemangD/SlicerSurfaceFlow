cmake_minimum_required(VERSION 3.16.3...3.19.7 FATAL_ERROR)

project(SlicerSurfaceFlow)

set(CMAKE_CXX_STANDARD 17)
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(libigl)

#-----------------------------------------------------------------------------
# Extension meta-information
set(EXTENSION_HOMEPAGE "https://github.com/allemangd/SlicerSurfaceFlow")
set(EXTENSION_CONTRIBUTORS "David Allemang (University of North Carolina at Chapel Hill")
set(EXTENSION_DESCRIPTION "A small extension for COMP 766 which analyzes certain surface flows on meshes.")
set(EXTENSION_ICONURL "https://www.example.com/Slicer/Extensions/SlicerSurfaceFlow.png")
set(EXTENSION_SCREENSHOTURLS "https://www.example.com/Slicer/Extensions/SlicerSurfaceFlow/Screenshots/1.png")
set(EXTENSION_DEPENDS "NA") # Specified as a list or "NA" if no dependencies

#-----------------------------------------------------------------------------
# Extension dependencies
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

#-----------------------------------------------------------------------------
# Extension modules
add_subdirectory(LibSurfaceFlow)
add_subdirectory(SurfaceFlow)
## NEXT_MODULE

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_GENERATE_CONFIG})
include(${Slicer_EXTENSION_CPACK})
