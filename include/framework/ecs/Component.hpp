#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_HPP_
#define HESTIA_FRAMEWORK_ECS_COMPONENT_HPP_

#include <string>

namespace HGE {
    
    class Component {
        
        private:
        std::string mTag;

        protected:
        // TODO: This may work, may not :S
        Component(std::string tag) : mTag(tag) { }

        public:
        virtual ~Component() = default;

        std::string getTag() {
            return mTag;
        }

        virtual void registerSystem() = 0;
    };
}

#endif