//
// Created by david on 21/03/2021.
//

#include "graphics/stb_image_loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

StbImageLoader::StbImageLoader() {
    stbi_set_flip_vertically_on_load(1);
}

Image StbImageLoader::loadImageFromFile(const char *filename) {
    auto image = Image();
    image.buffer = stbi_load(filename, &image.width, &image.height, &image.channels, 0);
    return image;
}

// todo: pass out and in a unique pointer?
void StbImageLoader::freeImage(Image &image) {
    stbi_image_free(image.buffer);
}
