/*
   Author: Sherman Chen
   Create Time: 2022-07-05
   Email: schen@simviu.com
   Copyright(c): Simviu Inc.
   Website: https://www.simviu.com
 */

#include "vsn/vsnTest.h"

using namespace vsn;
using namespace ut;
using namespace test;

namespace{
    const struct{
        string sf_img = "img_td/1.jpg";

    }lc_;
}
//--------------------------
bool TestImg::run()
{
    auto p = vsn::Img::loadFile(lc_.sf_img);
    if(p==nullptr)
    {
        log_ef(lc_.sf_img);
        return false;
    }
    auto& im = *p;
    
    im.toHsv();
    im.show("hsv");
    while(!vsn::cv_waitESC(10));
    return true;
}

