#include "correction.h"
#include "floyd_steinberg.h"


using namespace cv;

int floyd_steinberg(Mat image)
{
    int i, j, error, rows, cols, pixel;
    rows = image.rows;
    cols = image.cols;

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            pixel = image.at<uchar>(i ,j);

            if (pixel > 127) {
                error = pixel - 255;
                image.at<uchar>(i, j) = 255;
            } else {
                error = pixel;
                image.at<uchar>(i, j) = 0;
            }

            if (j < cols-1) {
                image.at<uchar>(i, j+1) = correct(image.at<uchar>(i, j+1) + 7*error/16);
            }

            if (j < cols-1 && i < rows-1) {
                image.at<uchar>(i+1, j+1) = correct(image.at<uchar>(i+1, j+1) + error/16);
            }

            if (i < rows-1) {
                image.at<uchar>(i+1, j) = correct(image.at<uchar>(i+1, j) + 5*error/16);
            }

            if (i < rows-1 && j > 0) {
                image.at<uchar>(i+1, j-1) = correct(image.at<uchar>(i+1, j-1) + 3*error/16);
            }
        }
    }
    return 1;
}
