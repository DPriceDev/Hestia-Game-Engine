//
// Created by david on 21/03/2021.
//

#ifndef HESTIA_BREAKOUT_IMAGE_LOADER_H
#define HESTIA_BREAKOUT_IMAGE_LOADER_H

#include <vector>
#include <string>

struct Image {
    int width{ 0 };
    int height{ 0 };
    int channels{ 0 };
    unsigned char* buffer;
};

class ImageLoader {

public:
    virtual Image loadImageFromFile(const char *filename) = 0;
    virtual void freeImage(Image& image) = 0;
    virtual ~ImageLoader() = default;
};

#endif //HESTIA_BREAKOUT_IMAGE_LOADER_H
