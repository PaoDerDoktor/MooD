CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(MooD)

ADD_CUSTOM_TARGET(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)

ADD_SUBDIRECTORY(submodules/raylib)

ADD_EXECUTABLE(MooD src/mood.c src/player.c src/entity.c src/block.c src/utils.c)

TARGET_INCLUDE_DIRECTORIES(MooD PUBLIC include)

TARGET_LINK_LIBRARIES(MooD PUBLIC raylib)

ADD_DEPENDENCIES(MooD copy_assets)
