cmake_minimum_required(VERSION 3.14)
project(lem_in)

set(CMAKE_CXX_STANDARD 14)

add_executable(lem_in
		ft_exit.c
		ft_upload.c
		header.h
		)
target_link_libraries(lem_in LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft.a)
