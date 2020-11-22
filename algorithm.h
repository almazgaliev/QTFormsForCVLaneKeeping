#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "AVL.h"

atl::Conditional<atl::Array<atl::Conditional<avl::Line2D>>> LinesArray(atl::Array<avl::Line2D>&);
avl::Region CreateROI(avl::Image&);
void SaveIMG(avl::Image&, atl::File);
avl::Image LoadImage(atl::File);
avl::Image YWMask(avl::Image& img, avl::Region& region);

#include "algorithm.cpp"

#endif // ALGORITHM_H
