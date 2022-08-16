/*
   Author: Sherman Chen
   Create Time: 2022-05-04
   Email: schen@simviu.com
   Copyright(c): Simviu Inc.
   Website: https://www.simviu.com
 */

#pragma once

#include "vsn/eigen_hlpr.h"

#include <opencv2/aruco.hpp>
#include <opencv2/videoio.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include <opencv2/aruco.hpp>
#include <opencv2/videoio.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/core/eigen.hpp>
#include <opencv2/imgproc.hpp>



#include "vsn/vsnLib.h"

namespace ocv{
    using namespace cv;
    using namespace std;
 //  sing namespace ut;
    using namespace vsn;

    extern string str(const cv::Point3d& d, int decim);

    //---- dbg show OpenCV img
    extern bool dbg_showImgWind();
    
    //---------
    // conversion
    //---------
    inline Scalar toCv(const Color& c)
    { return Scalar(c.b, c.g, c.r); }
    inline Point2d toCv(const vec2& v)
    { return Point2d(v.x(), v.y()); }
    inline vec2 toVec(const Point2d& c)
    { vec2 v; v<<c.x, c.y; return v;}
    inline vec2 toVec(const Point2f& c)
    { vec2 v; v<<c.x, c.y; return v;}
    inline vec4 toVec4(const cv::Mat& v)
    { vec4 e; 
      e << v.at<double>(0,0), v.at<double>(1,0), 
           v.at<double>(2,0), v.at<double>(3,0);
      return e;
      }

}