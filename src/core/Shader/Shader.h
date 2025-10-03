#ifndef _SHADER_H_
#define _SHADER_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../math/Vecteur/Vecteur2D.h"
#include "../../math/Matrice/Matrice_3x3.h"
#include <iostream>
#include <string>

class Shader
{
public:
    Shader(const char *pointShaderSource, const char *fragmentShaderSource);
    void UtilisezShader();
    void DefinirUniformVecteur2D(std::string nom, Vecteur2D valeur);
    void DefinirUniformVecteur4D(std::string nom, float r, float g, float b, float a);
    void DefinirUniformeFloat(std::string nom, float valeur);
    void DefinirUniformeMatrice3x3(std::string nom, Matrice3x3 matrice);

private:
    int m_shaderProgram;

    int ConfigurerPointShader(const char *pointShaderSource);
    int ConfigurerFragmentShader(const char *fragmentShaderSource);
    void ConfigurerShaderProgram(int indexShaderPoint, int indexShaderFragment);
};

#endif // _SHADER_H_