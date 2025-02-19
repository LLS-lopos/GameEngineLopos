#ifndef _SHADER_H_
#define _SHADER_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Vecteur/Vecteur2D.h"
#include <iostream>
#include <string>

class Shader
{
public:
    Shader(const char *pointShaderSource, const char *fragmentShaderSource);
    void UtilisezShader();
    void DefinirUniformVecteur2D(std::string nom, Vecteur2D valeur);
    void DefinirUniformeFloat(std::string nom, float valeur);

private:
    int m_shaderProgram;

    int ConfigurerPointShader(const char *pointShaderSource);
    int ConfigurerFragmentShader(const char *fragmentShaderSource);
    void ConfigurerShaderProgram(int indexShaderPoint, int indexShaderFragment);
};

#endif // _SHADER_H_