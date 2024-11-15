#include "Forme.h"

Forme::Forme(Shader *shader, GLDrawType glDrawType, int pointTaille, float point[], int indiceTaille, unsigned int indice[])
{
    m_shader = shader;
    m_glDrawType = glDrawType;
    ConfigureVBO(pointTaille, point);
    ConfigureEBO(indiceTaille, indice);
    nombreTriangle = (int)(indiceTaille / sizeof(int));
}
Forme *Forme::CreationTriangle(Shader *shader, GLDrawType glDrawType,
                               float x1, float y1, float z1,
                               float x2, float y2, float z2,
                               float x3, float y3, float z3)
{
    float point[9] = { x1, y1, z1, x2, y2, z2, x3, y3, z3 };
    unsigned int indice[3] = { 0, 1, 2 };
    Forme *triangle = new Forme(shader, glDrawType, sizeof(point), point, sizeof(indice), indice);
    return triangle;
}
Forme *Forme::CreationRectangle(Shader *shader, GLDrawType glDrawType, float largeur, float hauteur)
{
    float point[12] = {-largeur / 2.0f, -hauteur / 2.0f, 0.0f,  // bas-gauche
                        largeur / 2.0f, -hauteur / 2.0f, 0.0f,  // bas-droit
                        largeur /2.0f, hauteur/2.0f, 0.0f,  // haut-droit
                        -largeur / 2.0f, hauteur / 2.0f, 0.0f};  // haut-gauche
    unsigned int indice[6] = {0,2,1,0,3,2};
    Forme *rectangle = new Forme(shader, glDrawType, sizeof(point), point, sizeof(indice), indice);
    return rectangle;
}
void Forme::Draw() // Dessiner la forme
{
    // glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    m_shader->UtilisezShader();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    //glDrawArrays(GL_TRIANGLES, 0, nombreTriangle);
    glDrawElements(GL_TRIANGLES, nombreTriangle, GL_UNSIGNED_INT, 0);
}
void Forme::ConfigureVBO(int pointTaille, float point[])
{
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, pointTaille, point, m_glDrawType);
}
void Forme::ConfigureEBO(int indiceTaille, unsigned int indice[])
{
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceTaille, indice, m_glDrawType);
}