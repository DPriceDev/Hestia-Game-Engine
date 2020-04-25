#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

/**
 * Engine Class
 * Provides a static singletion
 */
class Engine {
    
    private:
    /* Private Variables */
    static Engine* mEngine;
    
    /* Private Constructor */
    Engine() {
         std::cout << "Constructed" << std::endl;
    }

    public:
    /* Public Methods */

    /* Public Methods */
    static Engine* getInstance() {
        if(!mEngine) {
            mEngine = new Engine();
        }
        return mEngine;
    }

    /* Public Destructor */
    ~Engine() { 
        delete mEngine; 
    }
};

#endif