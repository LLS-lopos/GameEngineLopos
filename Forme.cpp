#include "Forme.h"

Forme::Forme(Shader *shader, GLDrawType glDrawType, float pointTaille, float point[])
{
    m_shader = shader;
    ConfigureVBO(pointTaille, point);
}
Shader *Forme::CreationTriangle(Shader *shader, float pointTaille, GLDrawType glDrawType,
                                float x1, float y1, float z1,
                                float x2, float y2, float z2,
                                float x3, float y3, float z3)
{
    // forme
    float point[9] = {x1, y1, z1, x2, y2, z2, x3, y3, z3};
    m_shader = shader;
    ConfigureVBO(pointTaille, point);
    return m_shader;
}
void Forme::Draw()
{
    // Dessiner la forme
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    m_shader->UtilisezShader();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Forme::ConfigureVBO(float pointTaille, float point[])
{
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, pointTaille, point, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    m_shader->UtilisezShader();
}