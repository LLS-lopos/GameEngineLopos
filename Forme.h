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
    Forme(Shader *shader, GLDrawType glDrawType, float pointTaille, float point[], bool Filaire);
    Shader *CreationTriangle(Shader *shader, float pointTaille, GLDrawType glDrawType, bool Filaire,
                             float x1, float y1, float z1,
                             float x2, float y2, float z2,
                             float x3, float y3, float z3);
    void Draw();

private:
    GLuint m_vbo;
    GLuint m_vao;
    GLDrawType m_glDrawType;
    Shader *m_shader;

    void ConfigureVBO(float pointTaille, float point[], bool Filaire);
    void ConfigureVAO();
};
#endif // _FORME_H_