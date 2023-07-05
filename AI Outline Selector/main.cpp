#include <opencv2/opencv.hpp>
#include <fstream>
#include <exception>

int main()
{
    cv::namedWindow("Control", cv::WINDOW_NORMAL); // Create window for control sliders

    int iLowH = 0;
    int iHighH = 10;

    int iLowS = 70;
    int iHighS = 255;

    int iLowV = 50;
    int iHighV = 255;

    // Create trackbars in "Control" window
    cv::createTrackbar("LowH", "Control", &iLowH, 179); // Hue (0 - 179)
    cv::createTrackbar("HighH", "Control", &iHighH, 179);

    cv::createTrackbar("LowS", "Control", &iLowS, 255); // Saturation (0 - 255)
    cv::createTrackbar("HighS", "Control", &iHighS, 255);

    cv::createTrackbar("LowV", "Control", &iLowV, 255); // Value (0 - 255)
    cv::createTrackbar("HighV", "Control", &iHighV, 255);

    cv::VideoCapture cap(0); // capture the video from web cam

    if (!cap.isOpened())  // if not successful, exit program
    {
        std::cout << "Cannot open the web cam" << std::endl;
        return -1;
    }

    while (true)
    {
        cv::Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

        if (!bSuccess) //if not successful, break loop
        {
            std::cout << "Cannot read a frame from video stream" << std::endl;
            break;
        }

        cv::Mat imgHSV;
        cv::cvtColor(imgOriginal, imgHSV, cv::COLOR_BGR2HSV); // Convert the captured frame from BGR to HSV

        cv::Mat imgThresholded;
        cv::inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); // Threshold the image

        // Store the current HSV color range values to an external file
        std::ofstream file;
        file.open("HSVvalues.txt");
        file << "LowH: " << iLowH << "\n";
        file << "HighH: " << iHighH << "\n";
        file << "LowS: " << iLowS << "\n";
        file << "HighS: " << iHighS << "\n";
        file << "LowV: " << iLowV << "\n";
        file << "HighV: " << iHighV << "\n";
        file.close();

        // Show the original image and the thresholded image
        cv::imshow("Original", imgOriginal);
        cv::imshow("Thresholded Image", imgThresholded);

        // Wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        if (cv::waitKey(30) == 27) {
            std::cout << "esc key is pressed by user" << std::endl;
            break;
        }
    }

    return 0;
}
