#ifndef HESTIA_UTIL_RESOURCE_LOADER_HPP_
#define HESTIA_UTIL_RESOURCE_LOADER_HPP_

#include <string>
#include <fstream>
#include <sstream>

#include "Logger.hpp"

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
        } catch (std::ifstream::failure e) {
            LogError("Resource Loader", "Failed to load file.");
            stringOut = "";
        }
    }
}

#endif