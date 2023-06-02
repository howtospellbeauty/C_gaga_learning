#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    std::vector<cv::Point2f> input(1);
    std::vector<cv::Point2f> output(1);
    input[0].x = 100.0;
    input[0].y = 500.0;
    double M[3][3];
    M[0][0] = 22891.0;
    M[0][1] = 0.0;
    M[0][2] = 2746.0;
    M[1][0] = 0.0;
    M[1][1] = 22892.1;
    M[1][2] = 1843.34;
    M[2][0] = 0.0;
    M[2][1] = 0.0;
    M[2][2] = 1.0;

    cv::Mat intrinsicMatrix(3, 3, CV_64F);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            intrinsicMatrix.at<double>(i, j) = M[i][j];

    //std::vector<double> distortion = { 0.151829, -18.8042, 0.0007802, 0.00115257, 677.324 };
    std::vector<double> distortion = { 0.0, 0.0, 0.0, 0.0, 0.0 };

    cv::undistortPoints(input, output, intrinsicMatrix, distortion);

    double x, y, z;
    x = M[0][0] * output[0].x + M[0][1] * output[0].y + M[0][2] * 1.0;
    y = M[1][0] * output[0].x + M[1][1] * output[0].y + M[1][2] * 1.0;
    z = M[2][0] * output[0].x + M[2][1] * output[0].y + M[2][2] * 1.0;

    //intrinsicMatrix.mul(
	std::cout << "Hello world. " << std::endl;
	return 0;
}
