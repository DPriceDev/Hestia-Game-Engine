#ifndef HESTIA_UTIL_LOGGER_HPP_
#define HESTIA_UTIL_LOGGER_HPP_

#include <iostream>
#include <string>

/**
 * Log a debug message to console
 * TODO: Add array of items that will follow?
 * TODO: Add to separate thread
 */
static void LogDebug(std::string tag, std::string msg) {
    std::cout << "DEBUG: " << tag << " - " << msg << std::endl;
}

#endif