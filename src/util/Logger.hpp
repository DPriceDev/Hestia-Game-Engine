#ifndef HESTIA_UTIL_LOGGER_HPP_
#define HESTIA_UTIL_LOGGER_HPP_

#include <iostream>
#include <string>

/**
 * Log a debug message to console
 * TODO: Add array of items that will follow?
 */
static long LogDebug(std::string msg) {
    std::cout << "LOG - DEBUG: " << msg << std::endl;
}

#endif