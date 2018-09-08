add_executable(pong
    main.c
)

add_dependencies(pong
    mng
)

target_link_libraries(pong
    mng

    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    ${SDL2MIXER_LIBRARIES}
)
