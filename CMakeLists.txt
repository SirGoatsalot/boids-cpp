cmake_minimum_required(VERSION 3.23)

project(Boids)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)


add_executable(Boids)

target_sources(Boids
	PRIVATE
		src/main.cpp
)

target_link_libraries(Boids PRIVATE SDL3::SDL3)
