add_executable(
    dither
    dither.cc
    )
target_link_libraries( dither ${OpenCV_LIBS} )

