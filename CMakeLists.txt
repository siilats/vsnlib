project(vsnLib)
cmake_minimum_required(VERSION 3.4)

SET(CMAKE_CXX_STANDARD 17)
add_definitions(-fPIC)
#set( OpenCV_STATIC ON ) 

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package (jsoncpp REQUIRED)
find_package(OpenCV 4.5 REQUIRED)
find_package(Gflags REQUIRED)
find_package(PCL 1.3 REQUIRED COMPONENTS common io filters visualization)



add_definitions(${PCL_DEFINITIONS})

#add_executable(pcd_write_test pcd_write.cpp)
#target_link_libraries(pcd_write_test ${PCL_LIBRARIES})

message(STATUS "CMAKE_SYSTEM_PREFIX_PATH = ${CMAKE_SYSTEM_PREFIX_PATH}")
message(STATUS "Eigen3 inc dir: ${EIGEN3_INCLUDE_DIR}")
message(STATUS "JsonCpp_LIBRARIES =: ${JsonCpp_LIBRARIES}")
message(STATUS "OpenCV_DIR: ${OpenCV_DIR}")
message(STATUS "OpenCV inc dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "PCL inc dirs: ${PCL_INCLUDE_DIRS}")
#message(STATUS "PCL libs: ${PCL_LIBRARIES}")

include_directories( 
    ${EIGEN3_INCLUDE_DIR}
    ${OpenCV_DIRS}  
    ${JsonCpp_INCLUDE_DIR}
    ${PCL_INCLUDE_DIRS}
    #${CMAKE_PREFIX_PATH}/include
    /usr/include/jsoncpp
    /opt/dep/local/include
    inc
    )


#--- Hack for Mac brew
message(STATUS "CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")
link_directories(
    /opt/dep/local/lib
    ${PCL_LIBRARY_DIRS}
    ${CMAKE_PREFIX_PATH}/lib)


    
#---- vsnLib 
FILE(GLOB  SRC_VSNLIB src/*.cpp)
add_library(vsnLib ${SRC_VSNLIB})
target_link_libraries(vsnLib   
    ${OpenCV_LIBRARIES} 
    ${Eigen3_LIBRARY}    
    ${JsonCpp_LIBRARIES} 
    ${PCL_LIBRARIES}
    jsoncpp
    )
    
set(ENV{vsnLib_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
  

#---- vsnTest
FILE(GLOB  SRC_VSNTEST test/*.cpp)
add_executable(vsnTest ${SRC_VSNTEST})
target_link_libraries(vsnTest  
    vsnLib
    ${OpenCV_LIBRARIES} 
    )

#---- vsnTool
FILE(GLOB  SRC_VSNTEST apps/*.cpp)
add_executable(vsntool ${SRC_VSNTEST})
target_link_libraries(vsntool  
    ${OpenCV_LIBRARIES} 
    vsnLib)

#---- calib tool
add_subdirectory(calib)