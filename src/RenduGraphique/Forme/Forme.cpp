#include "Forme.h"

Forme::Forme(Shader *shader, GLDrawType glDrawType, Transform transform, int pointTaille, Vecteur2D* point, int indiceTaille, unsigned int* indice, FormeType formeType, bool filaire)
{
    m_shader = shader;
    m_glDrawType = glDrawType;
    m_formeType = formeType;
    m_filaire = filaire;
    m_transform = transform;
    ConfigureVBO(sizeof(Vecteur2D) * pointTaille, point);
    ConfigureEBO(sizeof(int) * indiceTaille, indice);
    n_typeForme = indiceTaille;
    m_point = point;
    m_indice = indice;
    m_pointTaille = pointTaille;
    m_indiceTaille = indiceTaille;
}

Forme::~Forme()
{
    if (m_point) {
        delete [] m_point; // Libération de la mémoire
    }
    if (m_indice) {
        delete [] m_indice; // Libération de la mémoire
    }
}

void Forme::Draw(Camera* camera, Fenetre* fenetre) // Dessiner la forme
{
    if (m_filaire)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    m_shader->UtilisezShader();
    m_shader->DefinirUniformVecteur2D("shapePosition", m_transform.m_position);
    m_shader->DefinirUniformVecteur2D("shapeScale", m_transform.m_echelle);
    m_shader->DefinirUniformeFloat("shapeAngle", (m_transform.m_angle * M_PI / 180));
    m_shader->DefinirUniformVecteur2D("cameraPosition", camera->ObtenirPosition());
    Vecteur2D taille = camera->ObtenirTailleVetH(fenetre->ObtenirLargeur(), fenetre->ObtenirHauteur());
    m_shader->DefinirUniformeFloat("cameraHorizontalSize", taille.m_x);
    m_shader->DefinirUniformeFloat("cameraVerticalSize", taille.m_y);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glDrawElements((int)m_formeType, n_typeForme, GL_UNSIGNED_INT, 0);
    if (m_filaire)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void Forme::ConfigureVBO(int pointTaille, Vecteur2D* point)
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

void Forme::DefinirPosition(const Vecteur2D& position)
{
    m_transform.m_position = position;
}

void Forme::DefinirEchelle(const Vecteur2D& echelle)
{
    m_transform.m_echelle = echelle;
}

void Forme::DefinirRotation(const float angle)
{
    m_transform.m_angle = angle;
}

Vecteur2D Forme::ObtenirPosition()const
{
    return m_transform.m_position;
}

void Forme::RecupPoint(unsigned int index, const Vecteur2D& vecteur)
{
    if (index >= m_pointTaille)
        return;

    m_point[index] = vecteur;
    ConfigureVBO(sizeof(Vecteur2D) * m_pointTaille, m_point);
}