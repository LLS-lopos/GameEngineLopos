#include "Forme.h"

Forme::Forme(Shader *shader, GLDrawType glDrawType, Transform transform, int pointTaille, Vecteur2D* point, int indiceTaille, unsigned int* indice, FormeType formeType, bool filaire)
{
    m_shader = shader;
    m_glDrawType = glDrawType;
    m_formeType = formeType;
    m_filaire = filaire;
    m_transform = transform;

    ConfigureVAO();

    GenererVBO();
    ConfigureVBO(sizeof(Vecteur2D) * pointTaille, point);
    ConfigureVertex();

    GenererEBO();
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
    
    m_shader->UtilisezShader();
    m_shader->DefinirUniformeMatrice3x3("model", m_transform.TransformeMatrice());
    m_shader->DefinirUniformeMatrice3x3("vue", camera->VueMatrice());
    m_shader->DefinirUniformeMatrice3x3("NDCespace", camera->NDCespaceMatrice(fenetre->ObtenirLargeur(), fenetre->ObtenirHauteur()));

    glBindVertexArray(m_vao);
    glDrawElements((int)m_formeType, n_typeForme, GL_UNSIGNED_INT, 0);
    
    if (m_filaire)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void Forme::ConfigureVAO()
{
    glGenVertexArrays(1, &m_vao);
}
void Forme::ConfigureVertex()
{
    glBindVertexArray(m_vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void Forme::GenererVBO()
{
    glGenBuffers(1, &m_vbo);
}
void Forme::GenererEBO()
{
    glGenBuffers(1, &m_ebo);
}
void Forme::ConfigureVBO(int pointTaille, Vecteur2D* point)
{
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, pointTaille, point, (int)m_glDrawType);
}

void Forme::ConfigureEBO(int indiceTaille, unsigned int indice[])
{
    glBindVertexArray(m_vao);
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