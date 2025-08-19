cmake_minimum_required(VERSION 3.10)
Project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)
add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

include_directories(include external/glad/include external/glfw/include)

file(GLOB SOURCES src/*.cpp)

add_executable(OpenGL ${SOURCES})

add_custom_command(TARGET OpenGL POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${CMAKE_SOURCE_DIR}/assets"
	"$<TARGET_FILE_DIR:OpenGL>/assets"
)

target_link_libraries(OpenGL glfw glad glm)