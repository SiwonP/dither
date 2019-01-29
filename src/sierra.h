#ifndef SIERRA_H
#define SIERRA_H

#include <opencv2/opencv.hpp>
#include <correction.h>

int sierra3(cv::Mat image);

int two_row_sierra(cv::Mat image);

int sierra_lite(cv::Mat image);

#endif
