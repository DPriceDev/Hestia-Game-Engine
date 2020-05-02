#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec4 tintColor;
in float alphaValue;

uniform sampler2D thisTexture;

void main()
{
    vec4 textureColour = texture(thisTexture, TexCoord);

    if(tintColor.w == 1.0f)
        textureColour = textureColour * vec4(tintColor.x, tintColor.y, tintColor.z, 1.0);
    
    textureColour = textureColour * alphaValue;

    if(textureColour.a < 0.1)
        discard;

    FragColor = textureColour;
}