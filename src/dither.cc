#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "floyd_steinberg.h"
#include "jjn.h"
#include "stucki.h"
#include "burkes.h"
#include "sierra.h"

using namespace cv;

int main(int argc, char *argv[])
{
    Mat image;

    if (argc < 3) {
        printf("Usage: dither <input_file> <output_file>\n");
    } else {

        image = imread(argv[1], 0);

        floyd_steinberg(image);
        //stucki(image);

        imwrite(argv[2], image);
        image.release();
    }

    return 0;
}
