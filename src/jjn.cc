#include "jjn.h"
#include "correction.h"

using namespace cv;

int jjn(Mat image)
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
                image.at<uchar>(i, j+1) = correct(image.at<uchar>(i, j+1) + 7*error/48);
            }

            if (j < cols-2) {
                image.at<uchar>(i, j+2) = correct(image.at<uchar>(i, j+2) + 5*error/48);
            }

            if (i < rows-1) {
                image.at<uchar>(i+1, j) = correct(image.at<uchar>(i+1, j) + 7*error/48);
            }

            if (i < rows-1 && j < cols-1) {
                image.at<uchar>(i+1, j+1) = correct(image.at<uchar>(i+1, j+1) + 5*error/48);
            }

            if (i < rows-1 && j < cols-2) {
                image.at<uchar>(i+1, j+2) = correct(image.at<uchar>(i+1, j+2) + 3*error/48);
            }

            if (i < rows-1 && j > 0) {
                image.at<uchar>(i+1, j-1) = correct(image.at<uchar>(i+1, j-1) + 5*error/48);
            }

            if (i < rows-1 && j > 1) {
                image.at<uchar>(i+1, j-2) = correct(image.at<uchar>(i+1, j-2) + 3*error/48);
            }

            if (i < rows-2) {
                image.at<uchar>(i+2, j) = correct(image.at<uchar>(i+2, j) + 5*error/48);
            }

            if (i < rows-2 && j < cols-1) {
                image.at<uchar>(i+2, j+1) = correct(image.at<uchar>(i+2, j+1) + 3*error/48);
            }

            if (i < rows-2 && j < cols-2) {
                image.at<uchar>(i+2, j+2) = correct(image.at<uchar>(i+2, j+2) + error/48);
            }

            if (i < rows-2 && j > 0) {
                image.at<uchar>(i+2, j-1) = correct(image.at<uchar>(i+2, j-1) + 3*error/48);
            }

            if (i < rows-2 && j > 1) {
                image.at<uchar>(i+2, j-2) = correct(image.at<uchar>(i+2, j-2) + error/48);
            }

        }
    }
    return 1;
}
