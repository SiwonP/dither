add_executable(
    dither
    dither.cc
    floyd_steinberg.cc
    jjn.cc
    correction.cc
    )
target_link_libraries( dither ${OpenCV_LIBS} )

