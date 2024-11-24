cmake_minimum_required(VERSION 3.2)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})


# find_package(raylib REQUIRED)


project(game LANGUAGES CXX)


add_subdirectory(libs/raylib)

file(GLOB include_files
					"src/include/*.h"
					"src/include/*.cpp"
					"src/include/Maze/*.h"
					"src/include/Maze/*.cpp"
					"src/include/Window/*.h"
					"src/include/Window/*.cpp"
					"src/include/Game/*.h"
					"src/include/Game/*.cpp"
					"src/include/Gui/*.h"
					"src/include/Gui/*.cpp"
					"src/include/Player/*.h"
					"src/include/Player/*.cpp"
					"src/include/Timer/*.h"
					"src/include/Timer/*.cpp"
)

add_executable(game src/main.cpp ${include_files})
# add_executable(game src/extract_as_h.cpp ${include_files})


target_include_directories(game PUBLIC  ${CMAKE_CURRENT_LIST_DIR}/src/include ${CMAKE_CURRENT_LIST_DIR}/src/resources)


add_custom_target(copy_resources ALL
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/Resources
	${BINARY_DIR}/Resources
	COMMENT "Copying resources into binary dir")

add_dependencies(game copy_resources)

target_link_libraries(game  PRIVATE raylib)

if (EMSCRIPTEN)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
	set(CMAKE_EXECUTABLE_SUFFIX ".html") # This line is used to set your executable to build with the emscripten html template so that you can directly open it.
endif ()



target_link_libraries(game  PRIVATE raylib)
