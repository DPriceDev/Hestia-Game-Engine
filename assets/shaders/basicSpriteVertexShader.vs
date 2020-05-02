#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 texCoords;

uniform mat4 screen;
uniform mat4 model;

out vec2 TexCoord;

void main()
{
    gl_Position = screen * model * vec4(aPos, 0.0, 1.0);
    TexCoord = texCoords;
}