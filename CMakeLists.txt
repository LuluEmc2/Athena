#Configuration
cmake_minimum_required(VERSION 3.25)
project(athena)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#Add json librairy
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)

#Add http librairy
add_subdirectory(lib/http)

#Add isbn library
add_library(isbn controller/isbn.cpp)
link_libraries(isbn)

#Add controller librairy
add_library(controller controller/controller.cpp)
link_libraries(controller)

#Add container librairy
add_library(container model/container.cpp)
link_libraries(container)

#Add document librairy
add_library(document model/document.cpp)
link_libraries(document)

#Add document view librairy
add_library(document_view view/document_view.cpp)
link_libraries(document_view)

#Add container view librairy
add_library(container_view view/container_view.cpp)
link_libraries(container_view)

#Add utils view librairy
add_library(utils_view view/utils_view.cpp)
link_libraries(utils_view)

#Link isbn to json
target_link_libraries(isbn PRIVATE nlohmann_json::nlohmann_json httplib::httplib)

target_include_directories(isbn PRIVATE 
    ${CMAKE_SOURCE_DIR}/lib/json/include/
    ${CMAKE_SOURCE_DIR}/lib/http
)

#Add include
include_directories(model/)
include_directories(controller/)
include_directories(view/)

#Create exe
add_executable(${PROJECT_NAME} main.cpp)