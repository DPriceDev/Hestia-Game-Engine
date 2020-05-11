#ifndef HESTIA_FRAMEWORK_EXCEPTIONS_H
#define HESTIA_FRAMEWORK_EXCEPTIONS_H

#include <exception>

namespace HGE {

    class GraphicModuleInitException: public std::exception {
        virtual const char* errorMsg() const noexcept {
            return "The Graphics Module Failed to Initialise.";
        }
    };
}

#endif