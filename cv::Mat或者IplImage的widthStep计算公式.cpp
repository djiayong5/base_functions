cv::Mat或者IplImage的widthStep计算公式.cpp
IplImage或者cv::Mat中的widthStep/step大小计算及原理：

一直以为IplImage结构体中的widthStep元素大小等于width*nChannels，大错特错，查看OpenCV源码，在src/cxcore/cxarray.cpp文件中，找到cvInitImageHeader函数，函数中对widthStep大小赋值如下：

其中IPL_DEPTH_SIGN的定义可以在cxtypes.h中找到，定义为：

int depth = 8; //位深度
#define IPL_DEPTH_SIGN 0x80000000
#define  CV_DEFAULT_IMAGE_ROW_ALIGN 4
align = CV_DEFAULT_IMAGE_ROW_ALIGN


int widthStep = (((width * nChannels * (depth & ~IPL_DEPTH_SIGN) + 7)/8)+ align - 1) & (~(align - 1));
或者：
int widthStep = (((cols * channels * (depth & ~0x80000000) + 7) / 8) + 4 - 1) & (~(4 - 1));
