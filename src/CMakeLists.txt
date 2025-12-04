find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_executable(raycaster491)

target_sources(raycaster491 
  PRIVATE
    main.cpp
    Map.cpp
    Player.cpp
    Ray.cpp
)

target_link_libraries(raycaster491
  PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
)