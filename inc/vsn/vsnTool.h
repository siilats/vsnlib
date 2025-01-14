/*
   Author: Sherman Chen
   Create Time: 2022-07-07
   Email: schen@simviu.com
   Copyright(c): Simviu Inc.
   Website: https://www.simviu.com
 */

#include "vsn/vsnLib.h"

using namespace vsn;

namespace app
{
    //-----------
    // util
    //-----------

    //-----------
    // CmdCalib
    //-----------
    class CmdCalib:public Cmd{
    public:
        using Cmd::Cmd;
        CmdCalib();
    protected:
        bool run_omni_stereo(CStrs& args);
        bool run_stereo(CStrs& args);
        bool run_cam_info(CStrs& args);

    };


    //-----------
    // CmdImg
    //-----------
    class CmdImg:public Cmd{
    public:
        using Cmd::Cmd;
        CmdImg();
    protected:
        bool run_picker(CStrs& args);
        bool run_crop(CStrs& args);
        struct Data{
            int frm_idx=0;
        }; Data data_;

    };
    //-----------
    // CmdVideo
    //-----------
    class CmdVideo:public Cmd{
    public:
        using Cmd::Cmd;
        CmdVideo();
    protected:
        struct Data{
            int frm_idx=0;
            string s_wdir="./";
        }; Data data_;
        bool video_frm_ui(const Img& im);
        bool run_frames(CStrs& args);
        bool run_crop(CStrs& args);
        bool run_enc(CStrs& args);
        bool save_frm(const Img& im);

    };
    //-----------
    // CmdMarker
    //-----------
    class CmdMarker:public Cmd{
    public:
        using Cmd::Cmd;
        CmdMarker();
        struct Cfg{
            CamCfg          camc;
            string swd; // write dir
            bool enShow = false;
            double rot=0;
            bool enWr = false;
            int skip_frm=0;
        };
        Cfg cfg_;
        //----
        Marker::PoseEstimator poseEstr_;
        //----
        bool run_det(CStrs& args)const;
        bool run_pose(CStrs& args);
        bool pose_est(Img& im, vector<Marker>& ms);
        void draw(Img& im,  
                const vector<Marker>& ms)const;
        bool run_pose_video(CStr& sf);
        bool run_pose_img(CStr& sf);
    };

    //-----------
    // VsnTool
    //-----------
    class VsnTool{
    public:
        bool run(CStrs& args);
    protected:
        Cmd cmd_;
        void initCmd(CStrs& args);
        
    };
}


