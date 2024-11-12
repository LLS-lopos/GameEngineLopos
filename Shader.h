#ifndef _SHADER_H_
#define _SHADER_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class Shader
{
public:
    Shader(const char *pointShaderSource, const char *fragmentShaderSource);
    void UtilisezShader();

private:
    int m_shaderProgram;

    int ConfigurerPointShader(const char *pointShaderSource);
    int ConfigurerFragmentShader(const char *fragmentShaderSource);
    void ConfigurerShaderProgram(int indexShaderPoint, int indexShaderFragment);
};

#endif // _SHADER_H_