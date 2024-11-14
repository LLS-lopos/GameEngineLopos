#include "Forme.h"

Forme::Forme(Shader *shader, GLDrawType glDrawType, float pointTaille, float point[], bool Filaire)
{
    m_shader = shader;
    ConfigureVBO(pointTaille, point, Filaire);
    
}
Shader *Forme::CreationTriangle(Shader *shader, float pointTaille, GLDrawType glDrawType, bool Filaire,
                                float x1, float y1, float z1,
                                float x2, float y2, float z2,
                                float x3, float y3, float z3)
{
    float point[9] = {x1, y1, z1, x2, y2, z2, x3, y3, z3};
    m_shader = shader;
    ConfigureVBO(pointTaille, point, Filaire);
    return m_shader;
}
void Forme::Draw()  // Dessiner la forme
{
    // glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    m_shader->UtilisezShader();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Forme::ConfigureVBO(float pointTaille, float point[], bool Filaire)
{
    glGenBuffers(1, &m_vbo);
    if (Filaire == true)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, pointTaille, point, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    m_shader->UtilisezShader();
}
/*
void Forme::ConfigureVAO()
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
}*/