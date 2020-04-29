#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_HPP_
#define HESTIA_FRAMEWORK_ECS_COMPONENT_HPP_

namespace HGE {
    
    class Component {
        
        private:
        const char * mTag;

        protected:
        // TODO: This may work, may not :S
        Component(const char * tag) : mTag(tag) { }

        public:
        ~Component() { }

        const char * getTag() {
            return mTag;
        }

        virtual void registerSystem() = 0;
    };
}

#endif