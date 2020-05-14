#ifndef HESTIA_UTIL_RESOURCE_LOADER_H
#define HESTIA_UTIL_RESOURCE_LOADER_H

#include <string>
#include <fstream>
#include <sstream>

#include "Logger.h"

namespace HGE {

    static void loadFileIntoString(std::string &stringOut, const char * filename) {
        std::ifstream file;
        std::stringstream ss;

        file.exceptions (std::ifstream::failbit | std::ifstream::badbit);

        try {
        file.open(filename);

        ss << file.rdbuf();
        file.close();
        
        stringOut = ss.str();
        } catch (std::ifstream::failure &e) {
            LOG_DEBUG("Resource Loader", "Failed to load file - code: ", e.code(), "\nerror:", e.what());
            stringOut = "";
        }
    }
}

#endif