#ifndef GRAPHICS_SHADER_HPP
#define GRAPHICS_SHADER_HPP

/**
 * 
 */
struct Shader {
    public:
    Shader(const char *vertexShaderSource) : mVertexShaderSource(vertexShaderSource) { }

    const char * GetShader() {
        return mVertexShaderSource;
    }

    private:
    const char *mVertexShaderSource;
};

#endif