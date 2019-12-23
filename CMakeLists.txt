set(CMAKE_CXX_STANDARD 11)

add_executable(lem_in
		ft_exit.c
		ft_upload.c
		sort_char.c
		tab_comp.c
		binary_search.c
		alg_bfs.c
		header.h
		lem_alg.c)

target_link_libraries(lem_in LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft.a)
