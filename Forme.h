#ifndef _FORME_H_
#define _FORME_H_
#include "Shader.h"
#include <iostream>

enum GLDrawType
{
    GL_DRAW_STREAM = 0x88E0,
    GL_DRAW_STATIC = 0x88E4,
    GL_DRAW_DYNAMIC = 0x88E8
};
class Forme
{
public:
    Forme(Shader *shader, GLDrawType glDrawType, int pointTaille, float point[], int indiceTaille, unsigned int indice[]);
    static Forme *CreationTriangle(Shader *shader, GLDrawType glDrawType,
                                   float x1, float y1, float z1,
                                   float x2, float y2, float z2,
                                   float x3, float y3, float z3);
    static Forme *CreationRectangle(Shader *shader, GLDrawType glDrawType, float largeur, float hauteur);
    void Draw();

private:
    GLuint m_vbo;
    GLuint m_vao;
    GLuint m_ebo;
    GLDrawType m_glDrawType;
    Shader *m_shader;

    int nombreTriangle = 1;
    void ConfigureVBO(int pointTaille, float point[]);
    void ConfigureEBO(int indiceTaille, unsigned int indice[]);
};
#endif // _FORME_H_