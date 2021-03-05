#ifndef HESTIA_FRAMEWORK_EXCEPTIONS_H
#define HESTIA_FRAMEWORK_EXCEPTIONS_H

#include <exception>

namespace HGE {

    /**
     * Graphics Module Initialization Exception
     * This error is thrown when a graphics module is invalid at start-up.
     */
    class GraphicModuleInitException : public std::exception {
        virtual const char *errorMsg() const noexcept {
            return "The Graphics Module Failed to Initialise.";
        }
    };
}// namespace HGE

#endif