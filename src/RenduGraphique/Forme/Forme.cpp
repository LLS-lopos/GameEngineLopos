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

Forme *Forme::CreationRectangle(Shader *shader, GLDrawType glDrawType, float largeur, float hauteur, bool filaire)
{
    float point[12] = {-largeur / 2.0f, -hauteur / 2.0f, 0.0f, // bas-gauche
                       largeur / 2.0f, -hauteur / 2.0f, 0.0f,  // bas-droit
                       largeur / 2.0f, hauteur / 2.0f, 0.0f,   // haut-droit
                       -largeur / 2.0f, hauteur / 2.0f, 0.0f}; // haut-gauche
    unsigned int indice[6] = {0, 2, 1, 0, 3, 2};
    Forme *rectangle = new Forme(shader, glDrawType, sizeof(point), point, sizeof(indice), indice, FormeType::TRIANGLE, filaire);
    return rectangle;
}
Forme *Forme::CreationPolygoneRegulier(Shader *shader, GLDrawType glDrawType, int nombre_poly, float rayon, bool filaire)
{
    int n_point = nombre_poly * 3;
    int nombreIndice = (nombre_poly - 2) * 3;
    float *point = new float[n_point];
    unsigned int *indice = new unsigned int[nombreIndice];

    bool siPaire = (nombre_poly % 2) == 0;
    float angle = 0;
    if (siPaire)
        angle = M_PI / 2.0f + 2.0f * M_PI / nombre_poly / 2.0f;
    else
        angle = M_PI / 2.0f;
    
    // Initialisé les points
    for (int i = 0; i < nombre_poly; i++)
    {
        float x = cos(angle) * rayon;
        float y = sin(angle) * rayon;

        angle -= 2.0f * M_PI / nombre_poly;

        point[i * 3] = x;
        point[i * 3 + 1] = y;
        point[i * 3 + 2] = 0.0f;
    }
    // Initialisé les indices
    for (int triangleID = 0; triangleID < nombre_poly - 2; triangleID++)
    {
        indice[triangleID * 3] = 0.0f;
        indice[triangleID * 3 + 1] = triangleID + 1;
        indice[triangleID * 3 + 2] = triangleID + 2;
    }
    Forme *polygone = new Forme(shader, glDrawType, n_point * sizeof(float), point, nombreIndice * sizeof(int), indice, FormeType::TRIANGLE, filaire);
    return polygone;    
}
Forme *Forme::CreationCercle(Shader *shader, GLDrawType glDrawType, int densiter, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, densiter, rayon, filaire);
}
Forme *Forme::CreationCarre(Shader *shader, GLDrawType glDrawType, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, 4, rayon, filaire);
}
Forme *Forme::CreationTriangle(Shader *shader, GLDrawType glDrawType, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, 3, rayon, filaire);
}
Forme *Forme::CreationGrille(Shader *shader, GLDrawType glDrawType, int n_carre_l, int n_carre_h, bool filaire)
{
    int n_point = ((n_carre_l + 1) + (n_carre_h + 1)) * 2 * 3;
    float *point = new float[n_point];

    int n_indice = ((n_carre_l + 1) + (n_carre_h + 1)) * 2;
    unsigned int *indice = new unsigned int[n_indice];

    float tailleX = 2.0f / n_carre_l;
    for (int x = 0; x < (n_carre_l + 1); x++)
    {
        int index = x * 2;
        point[index * 3] = - 1.0f;
        point[index * 3 + 1] = - 1.0f + x * tailleX;
        point[index * 3 + 2] = 0.0f;

        point[(index + 1) * 3] = 1.0f ;
        point[(index + 1) * 3 + 1] = -1.0f + x * tailleX;
        point[(index + 1) * 3 + 2] = 0.0f;

        indice[index] = index;
        indice[index + 1] = index + 1;
    }
    float tailleY = 2.0f / n_carre_h;
    for (int y = 0; y < (n_carre_h + 1); y++)
    {
        int index = (n_carre_l + 1) * 2.0f + y * 2.0f;
        point[index * 3] = - 1.0f + y * tailleY;
        point[index * 3 + 1] = 1.0f;
        point[index * 3 + 2] = 0.0f;

        point[(index + 1) * 3] = -1.0f + y * tailleY;
        point[(index + 1) * 3 + 1] = -1.0f;
        point[(index + 1) * 3 + 2] = 0.0f;

        indice[index] = index;
        indice[index + 1] = index + 1;
    }
    Forme *grille = new Forme(shader, glDrawType, n_point * sizeof(float), point, n_indice * sizeof(int), indice, FormeType::LIGNE, filaire);
    return grille;
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