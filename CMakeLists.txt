cmake_minimum_required(VERSION 3.22.1)
project(CPP)

file(GLOB SRC_FILES
"src/*.cpp")

set (INC_FILES_DIR
include/)

include_directories(
	${INC_FILES_DIR}
)

add_executable(CPP
	${SRC_FILES})

