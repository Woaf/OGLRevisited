#version 330 core

out vec4 col;

in vec4 ourColor;
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float range;

void main()
{   
    col = mix(texture(texture1, texCoord), texture(texture2, texCoord), range) * ourColor;
}
