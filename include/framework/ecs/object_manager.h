#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_MANAGER_H
#define HESTIA_FRAMEWORK_ECS_OBJECT_MANAGER_H

#include <context.h>
#include <memory>
#include <optional>
#include <vector>

#include "component_manager.h"
#include "context.h"
#include "object.h"

namespace HGE {

    /**
     * Object Manager
     */
    class ObjectManager {
        Context* mContext;
        std::vector<std::unique_ptr<IObject>> mObjects{};

    public:
        template<typename Object>
        Object *createObject() {
            auto objectPointer = std::make_unique<Object>(mContext);
            auto ptr = objectPointer.get();

            mObjects.push_back(std::move(objectPointer));
            mObjects.back()->onCreate();
            return ptr;
        }

        template<typename Object>
        [[maybe_unused]] std::optional<Object *> getObjectById(const UID id) const {
            constexpr auto func = [id](const std::unique_ptr<IObject> &pObject) {
                return pObject->getId() == id;
            };
            auto it = std::find_if(mObjects.begin(), mObjects.end(), func);

            if (it != mObjects.end()) {
                return dynamic_cast<Object *>(*it);
            } else {
                return std::nullopt;
            }
        }

        [[maybe_unused]] void destroyObject(const UID id) {
            auto func = [id](const std::unique_ptr<IObject> &pObject) {
                return pObject->getId() == id;
            };

            const auto it = std::find_if(mObjects.begin(), mObjects.end(), func);
            mObjects.erase(it);
        }

        explicit ObjectManager(Context* context) : mContext(context) {}
        ~ObjectManager() = default;
    };
}// namespace HGE

#endif