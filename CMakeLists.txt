cmake_minimum_required(VERSION 3.2)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(raylib_USE_STATIC_LIBS ON)
find_package(raylib REQUIRED)


project(game LANGUAGES CXX)

# include_directories(engine)
# add_subdirectory(engine)

file(GLOB include_files
					"src/include/*.h"
					"src/include/*.cpp"
					"src/include/Maze/*.h"
					"src/include/Maze/*.cpp"
					"src/include/Window/*.h"
					"src/include/Window/*.cpp"
					"src/include/Game/*.h"
					"src/include/Game/*.cpp"
					"src/include/Map/*.h"
					"src/include/Map/*.cpp"
)

add_executable(game src/utils/screen_scaling.cpp ${include_files})

target_include_directories(game PUBLIC ${CMAKE_CURRENT_LIST_DIR}/3rd_lib ${CMAKE_CURRENT_LIST_DIR}/src/include)



# target_link_libraries(game Engine ${raylib_LIBRARIES})
target_link_libraries(game  ${raylib_LIBRARIES})
