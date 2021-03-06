#version 330 core
layout (location = 0) in vec2 aPos;

out vec4 color;

uniform mat4 screen;
uniform vec4 aColor;

void main()
{
    gl_Position = screen * vec4(aPos, 0.0, 1.0);
    color = aColor;
}