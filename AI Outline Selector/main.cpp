#include <opencv2/opencv.hpp>

int main() {
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

    while (true)
    {
        cv::Mat img = cv::imread("WhatsApp Image 2023-06-22 at 8.34.55 PM.jpeg"); // Read the image
        cv::Mat imgHSV;
        cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV); // Convert the captured frame from BGR to HSV

        cv::Mat imgThresholded;
        cv::inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); // Threshold the image

        // Show the original image and the thresholded image
        cv::imshow("Original", img);
        cv::imshow("Thresholded Image", imgThresholded);

        // Wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        if (cv::waitKey(30) == 27) {
            std::cout << "esc key is pressed by user" << std::endl;
            break;
        }
    }

    return 0;
}
