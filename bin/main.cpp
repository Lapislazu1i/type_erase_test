
#include <stdlib.h>
#include <stdio.h>
#include "hide.h"
#include <iostream>
int main()
{
    {
        auto im = h_image_info::make_unique();
        const auto& im1 = im;
        std::cout << im->width() << "\n";
        im->width() = 2;
        std::cout << im->width() << "\n";
        std::cout << im->height() << "\n";
        im->height() = 4;
        std::cout << im->height() << "\n";
        h_image_info* mp = im.get();
    }
    printf("he\n");
}