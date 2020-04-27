#ifndef GRAPHICS_SHADER_HPP
#define GRAPHICS_SHADER_HPP

/**
 * 
 */
struct Shader {

    private:
    const char *mVertexShaderSource;
    const char *mFragmentShaderSource;

    public:
    Shader(const char *vertexShaderSource, const char *fragmentShaderSource) 
            : mVertexShaderSource(vertexShaderSource), mFragmentShaderSource(fragmentShaderSource) { }

    const char * GetVertexShader() {
        return mVertexShaderSource;
    }

    const char * GetFragmentShader() {
        return mFragmentShaderSource;
    }
};

#endif