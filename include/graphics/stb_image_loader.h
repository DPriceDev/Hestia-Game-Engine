//
// Created by david on 21/03/2021.
//

#ifndef HESTIA_BREAKOUT_STB_IMAGE_LOADER_H
#define HESTIA_BREAKOUT_STB_IMAGE_LOADER_H

#include "image_loader.h"

class StbImageLoader : public ImageLoader {
public:
    StbImageLoader();
    ~StbImageLoader() override = default;
    Image loadImageFromFile(const char *filename) override;
    void freeImage(Image &image) override;
};

#endif //HESTIA_BREAKOUT_STB_IMAGE_LOADER_H
