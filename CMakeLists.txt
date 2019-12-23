cmake_minimum_required(VERSION 3.14)
<<<<<<< HEAD
project(alex_lem C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(alex_lem
        alg_bfs.c
        binary_search.c
        ft_exit.c
        ft_upload.c
        header.h
        lem_alg.c
        sort_char.c
        tab_comp.c)

target_link_libraries(alex_lem LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft.a)
=======
project(lem_in)

set(CMAKE_CXX_STANDARD 14)

add_executable(lem_in
		ft_exit.c
		ft_upload.c
		sort_char.c
		tab_comp.c
		binary_search.c
		alg_bfs.c
		header.h
		lem_alg.c

		)
target_link_libraries(lem_in LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft.a)
>>>>>>> origin/alex
