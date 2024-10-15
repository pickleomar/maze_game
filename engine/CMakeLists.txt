# include_directories(include)
add_library(Engine STATIC
	src/Window.cpp
)
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
