#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>
#include <stdio.h>

std::string gray2ascii(cv::Mat gFrame){
    const char map[11] = " .,:;ox%#@";

    std::string asciiArt = "";
    for(int jj = 0; jj < gFrame.rows; jj+=5){
        for(int ii=0; ii < gFrame.cols; ii+=5){
            asciiArt += map[(255-gFrame.at<uchar>(jj, ii))*10/256];
        }
        asciiArt += "\r\n";
    }
    return asciiArt;
}

int main(int, char**){
    cv::Mat frame;
    cv::Mat gFrame;

    cv::VideoCapture cap;

    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API

    cap.open(deviceID, apiID);

    if (!cap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    std::cout << "Start grabbing" << std::endl << "Press any key to terminate" << std::endl;

    while(true){
        cap.read(frame);
        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            return -1;
        }
    
        cv::imshow("Live", frame);

        cv::cvtColor(frame, gFrame, cv::COLOR_BGR2GRAY);
        
        cv::imshow("Live gray", gFrame);

        std::cout << gray2ascii(gFrame) << std::endl << std::endl;

        if (cv::waitKey(5) >= 0) break;
    }

    return 0;
}
