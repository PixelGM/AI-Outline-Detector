#include <opencv2/opencv.hpp>

int main() {
    // Load the image file
    cv::Mat img = cv::imread("WhatsApp Image 2023-06-22 at 8.34.55 PM.jpeg");

    // Check if image was loaded successfully
    if (img.empty()) {
        std::cout << "Could not read the image file" << std::endl;
        return 1;
    }

    // Draw a rectangle on the image
    // cv::Point(x, y) are the coordinates of the rectangle's top left and bottom right corners
    // cv::Scalar(b, g, r) defines the color of the rectangle in BGR format
    cv::rectangle(img, cv::Point(50, 50), cv::Point(200, 200), cv::Scalar(0, 0, 255), 2);

    // Display the image
    cv::namedWindow("Image with Rectangle", cv::WINDOW_NORMAL);
    cv::imshow("Image with Rectangle", img);

    // Wait for a keystroke in the window
    cv::waitKey(0);

    return 0;
}
