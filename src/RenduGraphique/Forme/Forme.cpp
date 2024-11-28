#include "Forme.h"
#include <cmath>

Forme::Forme(Shader *shader, GLDrawType glDrawType, int pointTaille, float point[], int indiceTaille, unsigned int indice[], FormeType formeType, bool filaire)
{
    m_shader = shader;
    m_glDrawType = glDrawType;
    m_formeType = formeType;
    m_filaire = filaire;
    ConfigureVBO(pointTaille, point);
    ConfigureEBO(indiceTaille, indice);
    n_typeForme = (int)(indiceTaille / sizeof(int));
}

void Forme::Draw() // Dessiner la forme
{
    if (m_filaire)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    m_shader->UtilisezShader();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glDrawElements((int)m_formeType, n_typeForme, GL_UNSIGNED_INT, 0);
    if (m_filaire)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void Forme::ConfigureVBO(int pointTaille, float point[])
{
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, pointTaille, point, (int)m_glDrawType);
}
void Forme::ConfigureEBO(int indiceTaille, unsigned int indice[])
{
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceTaille, indice, (int)m_glDrawType);
}