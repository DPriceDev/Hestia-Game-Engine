#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 tintColor;

uniform sampler2D thisTexture;

void main()
{
    FragColor = texture(thisTexture, TexCoord) * vec4(tintColor, 1.0);
}