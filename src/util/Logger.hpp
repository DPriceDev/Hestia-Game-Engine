#ifndef HESTIA_UTIL_LOGGER_HPP_
#define HESTIA_UTIL_LOGGER_HPP_

#include <iostream>
#include <string>

static long LogDebug(std::string msg) {
    std::cout << "LOG - DEBUG: " << msg << std::endl;
}

#endif