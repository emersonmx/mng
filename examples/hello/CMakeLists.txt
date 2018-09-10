add_executable(hello
    main.c
)

add_dependencies(hello
    mng
)

target_link_libraries(hello
    mng

    m
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    ${SDL2MIXER_LIBRARIES}
)
