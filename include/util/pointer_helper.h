//
// Created by David Price on 18/05/2020.
//

#ifndef HESTIA_ROGUELIKE_DEPENDS_HGE_UTIL_POINTER_HELPER_H
#define HESTIA_ROGUELIKE_DEPENDS_HGE_UTIL_POINTER_HELPER_H

#include <vector>
#include <memory>
#include <algorithm>

namespace HGE {

    template<typename T>
    inline constexpr static auto doesContainPointer(const std::vector<std::unique_ptr<T>> &vector, const T *pointer) {
        return std::find_if(vector.begin(), vector.end(), [pointer](const std::unique_ptr<T> &vPointer) {
            return vPointer.get() == pointer;
        });
    }
}

#endif //HESTIA_ROGUELIKE_DEPENDS_HGE_UTIL_POINTER_HELPER_H
