#include "Transform.h"

Transform::Transform()
{}

Transform::Transform(Vecteur2D position, Vecteur2D echelle, float angle)
{
    m_position = position;
    m_echelle = echelle;
    m_angle = angle;
}

Matrice3x3 Transform::TransformeMatrice()
{
    return Matrice3x3::TRS(m_position, m_angle, m_echelle);
}