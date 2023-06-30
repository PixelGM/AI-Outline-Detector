#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main() {
    // Request file path from user
    std::string filePath;
    std::cout << "Enter the path to the image file: ";
    std::cin >> filePath;

    // Load the image file
    cv::Mat img = cv::imread(filePath);

    // Check if image was loaded successfully
    if (img.empty()) {
        std::cout << "Could not read the image file" << std::endl;
        return 1;
    }

    // Convert color space from BGR to HSV
    cv::Mat hsv;
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);

    // Define range for red color
    cv::Mat mask;
    cv::inRange(hsv, cv::Scalar(0, 70, 50), cv::Scalar(10, 255, 255), mask);

    // Find contours in the mask
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Draw rectangles around each contour
    for (const auto& contour : contours) {
        cv::Rect rect = cv::boundingRect(contour);
        cv::rectangle(img, rect, cv::Scalar(0, 255, 0), 2);
    }

    // Display the image
    cv::namedWindow("Image with Rectangle", cv::WINDOW_NORMAL);
    cv::imshow("Image with Rectangle", img);

    // Wait for a keystroke in the window
    cv::waitKey(0);

    return 0;
}
