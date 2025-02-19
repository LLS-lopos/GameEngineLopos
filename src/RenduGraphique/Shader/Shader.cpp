#include "Shader.h"

Shader::Shader(const char *pointShaderSource, const char *fragmentShaderSource)
{
    int indexShaderPoint = ConfigurerPointShader(pointShaderSource);
    int indexShaderFragment = ConfigurerFragmentShader(fragmentShaderSource);
    ConfigurerShaderProgram(indexShaderPoint, indexShaderFragment);
}
void Shader::UtilisezShader()
{
    glUseProgram(m_shaderProgram);
}
int Shader::ConfigurerPointShader(const char *pointShaderSource)
{
    unsigned int pointShader = glCreateShader(GL_VERTEX_SHADER);
    int success = 0;
    char infoLog[512];
    glShaderSource(pointShader, 1, &pointShaderSource, NULL);
    glCompileShader(pointShader);
    glGetShaderiv(pointShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(pointShader, 512, NULL, infoLog);
        std::cout << "Erreur lors de la compilation du shader\n"
                  << infoLog << std::endl;
    }
    return pointShader;
}
int Shader::ConfigurerFragmentShader(const char *fragmentShaderSource)
{
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    int success = 0;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Erreur lors de la compilation du shader\n"
                  << infoLog << std::endl;
    }
    return fragmentShader;
}
void Shader::ConfigurerShaderProgram(int indexShaderPoint, int indexShaderFragment)
{
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, indexShaderPoint);
    glAttachShader(m_shaderProgram, indexShaderFragment);
    glLinkProgram(m_shaderProgram);
    int success = 0;
    char infoLog[512];
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
        std::cout << "Erreur lors de la compilation du shader\n"
                  << infoLog << std::endl;
    }
    glDeleteShader(indexShaderPoint);
    glDeleteShader(indexShaderFragment);
}

void Shader::DefinirUniformVecteur2D(std::string nom, Vecteur2D valeur)
{
    int location = glGetUniformLocation(m_shaderProgram, nom.c_str());
    glUniform2f(location, valeur.m_x, valeur.m_y);
}
void Shader::DefinirUniformeFloat(std::string nom, float valeur)
{
    int location = glGetUniformLocation(m_shaderProgram, nom.c_str());
    glUniform1f(location, valeur);
}
