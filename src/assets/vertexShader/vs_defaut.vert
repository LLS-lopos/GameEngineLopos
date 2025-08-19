#version 330 core

layout (location = 0) in vec3 aPos;
uniform mat3 model;
uniform mat3 vue;
uniform mat3 NDCespace;

void main()
{
    vec3 vertexInLocaleSpace = vec3(aPos.x,aPos.y,1.0f);
    vec3 vertexInNDCSpace = NDCespace * vue * model * vertexInLocaleSpace;

    gl_Position = vec4(vertexInNDCSpace.x, vertexInNDCSpace.y, aPos.z, 1.0);
}