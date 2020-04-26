#ifndef HESTIA_FRAMEWORK_COMPONENTS_COMPONENT_H_
#define HESTIA_FRAMEWORK_COMPONENTS_COMPONENT_H_

/**
 * Component Interface
 */
class Component {
    
    private:
    const char * mTag;

    protected:
    // TODO: This may work, may not :S
    Component(const char * tag) : mTag(tag) { }

    public:
    ~Component() {

    }

    const char * getTag() {
        return mTag;
    }

    virtual void registerSystem() = 0;
};

#endif