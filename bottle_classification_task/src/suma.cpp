#include<iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main(){

cv::Mat c=cv::imread("/home/ctai/algorithm/document/test_protocol/possibly_color.png",CV_8UC1);
cv::Mat g=cv::imread("/home/ctai/algorithm/document/test_protocol/possibly_green.png",CV_8UC1);
cv::Mat w=cv::imread("/home/ctai/algorithm/document/test_protocol/possibly_white.png",CV_8UC1);

std::vector<cv::Mat> canales(3);
/*cv::bitwise_not(c,c);
cv::bitwise_not(g,g);
cv::bitwise_not(w,w);*/

canales[0]=c;
canales[1]=g;
canales[2]=w;

for(int i=0;i<w.cols;i++){
	for(int j=0;j<w.rows;j++){
		if(w.at<uchar>(j,i)==255){
	c.at<uchar>(j,i)=255;
	g.at<uchar>(j,i)=255;
	}
}
}

cv::Mat full;

cv::merge(canales,full);
cv::imshow("fullhd",full);
cv::imwrite("/home/ctai/algorithm/document/test_protocol/possibly.png",full);
cv::waitKey(0);
}
