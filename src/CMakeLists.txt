find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_executable(program)

target_sources(program 
  PRIVATE
    main.cpp
    Map.cpp
    Player.cpp
)

target_link_libraries(program
  PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
)