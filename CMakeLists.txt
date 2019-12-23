cmake_minimum_required(VERSION 3.14)

project(TMP_LEM_IN C)

set(CMAKE_C_STANDARD 11)

add_executable(TMP_LEM_IN
        alg_bfs.c
        binary_search.c
        ft_exit.c
        ft_upload.c
        header.h
        lem_alg.c
        sort_char.c
        tab_comp.c
        main.c
        check_bfr_alg.c)

target_link_libraries(TMP_LEM_IN LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft.a)
