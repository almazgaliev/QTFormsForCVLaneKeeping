#include "AVL.h"
#include <iostream>
using namespace std;
//using namespace KernelShape;

auto LinesArray(atl::Array<avl::Line2D>& lines)
{
    auto arr1 = atl::Array<atl::Conditional<avl::Line2D>>(lines.Size()); //Array<Line2D>
    for(int i=0;i<arr1.Size();++i)
        arr1[i] = atl::Conditional<avl::Line2D>(lines[i]);
    return atl::Conditional<atl::Array<atl::Conditional<avl::Line2D>>>(arr1);
}

std::string Algo(std::string filepath) {

    avl::Image img;
    LoadImage(filepath.c_str(),false, img);
    SaveImageToJpeg(img,"/home/omnuse/Изображения/s/img0", atl::NIL, false);
    int H = img.Height();
    int W = img.Width();


    avl::Point2D origin = { W*0.2f , H*0.6f };
    float r_width = W*0.6f;
    float r_height = H*0.4f;
    avl::Rectangle2D r(origin, 0, r_width, r_height);
    avl::Region down_half;
    CreateRectangleRegion(r, atl::NIL, W, H, down_half, atl::NIL);


    avl::Image bw_img;
    AverageChannels(img, atl::NIL,bw_img);
    SaveImageToJpeg(bw_img,"/home/omnuse/Изображения/s/img0_bw", atl::NIL, false);


    avl::Image clahe_img;
    EqualizeImageHistogram(bw_img, atl::NIL, 0.05, 0.35, clahe_img);// SIGABRT
    SaveImageToJpeg(clahe_img,"/home/omnuse/Изображения/s/img1_clahe", atl::NIL, false);


    // сглаживание изображения
    avl::Image smooth_img;
    DilateImage(clahe_img, down_half, atl::NIL, atl::NIL, avl::KernelShape::Ellipse, 3, atl::NIL, smooth_img);
    SaveImageToJpeg(smooth_img,"/home/omnuse/Изображения/s/img2_smooth", atl::NIL, false);




    avl::Image hsl_img;
    RgbToHsl(img, hsl_img);

    avl::Image yellow_img, white_img, yw_img;



    ThresholdImage_HSx(hsl_img, down_half, avl::HSxColorModel::Type::HSL, 0, 255, 160, 255, 140, 255, 2, yellow_img);
    //ThresholdImage_HSx(hsl_img, down_half, HSxColorModel::Type::HSL, 0, 255, 160, 255, 110, 255, 2, yellow_img);
    SaveImageToJpeg(yellow_img, "/home/omnuse/Изображения/s/img3_yw_mask", atl::NIL, false);

    ThresholdImage_HSx(hsl_img, down_half, avl::HSxColorModel::Type::HSL, 0, 255, 0, 210, 170, 255, 2, white_img);
    //ThresholdImage_HSx(hsl_img, down_half, HSxColorModel::Type::HSL, 0, 255, 0, 210, 100, 255, 2, white_img);
    SaveImageToJpeg(white_img, "/home/omnuse/Изображения/s/img3_yw_mask", atl::NIL, false);



    AddImages(yellow_img, white_img, down_half, 1.0f, yw_img);
    SaveImageToJpeg(yw_img, "/home/omnuse/Изображения/s/img3_yw_mask", atl::NIL, false);





    //Умножение чб клахе на бело-желтое изображение
    avl::Image final_mask;
    MultiplyImages(yw_img, clahe_img, down_half, 1.0f, final_mask);
    SaveImageToJpeg(final_mask,"/home/omnuse/Изображения/s/img4_final_mask", atl::NIL, false);


    avl::Image smooth_mask;
    DilateImage(final_mask, down_half, atl::NIL, atl::NIL, avl::KernelShape::Ellipse, 1, atl::NIL, smooth_mask);
    //SmoothImage_Gauss(final_mask, down_half, 1.0f, 1.0f, 2.0f, smooth_mask);
    SaveImageToJpeg(smooth_mask,"/home/omnuse/Изображения/s/img5_smooth_mask", atl::NIL, false);



    avl::Image outedges_img;
    avl::Image canny_img;


    avl::Image final_img;
    DetectEdges(final_mask, down_half, avl::EdgeFilter::Canny, 2.0f, atl::NIL, 15.0f, 5.0f, 0.0f, 1, outedges_img, canny_img);
    //DetectEdges(final_mask, down_half, avl::EdgeFilter::Canny, 2.5, NIL, 20.0f, 30.0f, 1.0f, 1, outedges_img, canny_img);
    SaveImageToJpeg(outedges_img,"/home/omnuse/Изображения/s/img6_outedges", atl::NIL, false);



    // рисуем
    avl::Image lines_img;
    avl::Pixel pix;
    avs::AvsFilter_MakePixel(255,0,0,255,pix);
    avl::DrawingStyle drwstl;
    drwstl.thickness = 5;
    drwstl.filled = true;
    drwstl.opacity = 1;


    atl::Array<avl::Line2D> lines;
    atl::Array<float> scores;

    DetectLines(outedges_img, down_half, 0.5f, 20.0f, 90.0f, 20.0f, 20.0f, lines, scores);
    //DetectLines(outedges_img, down_half, 0.5f, 20.0f, 60.0f, 40.0f, 10.0f, lines, scores);
    SaveImageToJpeg(lines_img,"/home/omnuse/Изображения/s/img7_lines", atl::NIL, false);

    SaveImageToJpeg(img,"/home/omnuse/Изображения/s/img8_lines", atl::NIL, false);

//    atl::Array<avl::Line2D> new_lines(10);

//    for (auto i:lines)
//    {
//        if ((abs(i.a/i.b) > 0.95) && (abs(i.a/i.b) < 1.3))
//        {
//            cout <<"tan = "<< abs(i.a/i.b) <<endl;
//            DrawLine(lines_img, i, NIL, pix, drwstl);
//            DrawLine(img, i, NIL, pix, drwstl);
//            // НЕ РИСУЕТ В ЦИКЛЕ! ХЗ ПОЧЕМУ, ОШИБОК нет
//        }
//    }



//    for (int i=0; i<lines.Size(); i++)
//    {
//        if ((abs(lines[i].a/lines[i].b) > 0.95) && (abs(lines[i].a/lines[i].b) < 1.3) )
//        {
//            cout <<"tan = "<< abs(lines[i].a/lines[i].b) <<endl;
//            new_lines.Insert(i, lines[i]);
//        }
//    }


    return "/home/omnuse/Изображения/s/img8_lines";

}
