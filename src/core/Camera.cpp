#include "Camera.h"

Camera::Camera(Vecteur2D position, float taille, bool siHorizontal)
{
    m_position = position;
    m_taille = taille;
    m_siHorizontal = siHorizontal;
}
void Camera::DefinirPosition(const Vecteur2D& position) 
{
    m_position = position;
}
void Camera::DefinirTaille(float taille)
{
    m_taille = taille;
}
void Camera::DefinirOrientation(bool siHorizontal)
{
    m_siHorizontal = siHorizontal;
}

Vecteur2D Camera::ObtenirTailleVetH(float largeur, float hauteur)
{
    if (m_siHorizontal)
        return Vecteur2D(m_taille, m_taille * hauteur / largeur);
    else
        return Vecteur2D(m_taille * largeur / hauteur, m_taille);
}

Vecteur2D Camera::ObtenirPosition()const
{
    return m_position;
}
float Camera::ObtenirTaille()const
{
    return m_taille;
}
bool Camera::ObtenirOrientation()const
{
    return m_siHorizontal;
}