#include "Transform.h"

Transform::Transform()
{}

Transform::Transform(Vecteur2D position, Vecteur2D echelle, float angle)
{
    m_position = position;
    m_echelle = echelle;
    m_angle = angle;
}