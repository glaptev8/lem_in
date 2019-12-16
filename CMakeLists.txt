cmake_minimum_required(VERSION 3.14)
project(Lem_In C)

set(CMAKE_C_STANDARD 11)

add_executable(Lem_In
        ft_upload.c ft_exit.c)

target_link_libraries(Lem_In LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft.a)
