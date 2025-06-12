#include "Vecteur2D.h"

Vecteur2D::Vecteur2D() : m_x(0.0f), m_y(0.0f), m_z(0.0f) {}
Vecteur2D::Vecteur2D(float x, float y) : m_x(x), m_y(y), m_z(0.0f) {}
Vecteur2D::Vecteur2D(const Vecteur2D& valeur) : m_x(valeur.m_x), m_y(valeur.m_y), m_z(0.0f) {}

Vecteur2D Vecteur2D::operator+(const Vecteur2D& valeur) const
{
    return Vecteur2D(m_x + valeur.m_x, m_y + valeur.m_y);
}

Vecteur2D Vecteur2D::operator*(const float& valeur) const
{
    return Vecteur2D(m_x * valeur, m_y * valeur);
}

Vecteur2D Vecteur2D::operator-(const Vecteur2D& valeur) const
{
    return Vecteur2D(m_x - valeur.m_x, m_y - valeur.m_y);
}

Vecteur2D Vecteur2D::operator/(const float& valeur) const
{
    if (valeur != 0.0f) {
        float n = 1.0f / valeur;
        return Vecteur2D(m_x * n, m_y * n);
    } else {
        return Vecteur2D(0.0f, 0.0f);
    }
}

float Vecteur2D::Magnitude() const
{
    return sqrtf(m_x * m_x + m_y * m_y);
}

void Vecteur2D::Normaliser()
{
    float distance = Magnitude();
    if (distance != 0.0f) {
        m_x /= distance;
        m_y /= distance;
    }
}
Vecteur2D Vecteur2D::Normaliser() const
{
    float distance = Magnitude();
    if (distance != 0.0f) {
        return Vecteur2D(m_x / distance, m_y / distance);
    }
    return Vecteur2D(0.0f, 0.0f);
}

Vecteur2D& Vecteur2D::operator+=(const Vecteur2D& valeur)
{
    m_x += valeur.m_x;
    m_y += valeur.m_y;
    return (*this);
}
Vecteur2D& Vecteur2D::operator*=(float valeur)
{
    m_x *= valeur;
    m_y *= valeur;
    return (*this);
}
Vecteur2D& Vecteur2D::operator-=(const Vecteur2D& valeur)
{
    m_x -= valeur.m_x;
    m_y -= valeur.m_y;
    return (*this);
}
Vecteur2D& Vecteur2D::operator/=(float valeur)
{
    if (valeur != 0.0f) {
        float n = 1.0f / valeur;
        m_x *= n;
        m_y *= n;
    } else {
        m_x = 0.0f;
        m_y = 0.0f;
    }
    return (*this);
}
bool Vecteur2D::operator==(const Vecteur2D& valeur) const
{
    return (m_x == valeur.m_x && m_y == valeur.m_y);
}
bool Vecteur2D::operator!=(const Vecteur2D& valeur) const
{
    return !(*this == valeur);
}
std::ostream& operator<<(std::ostream& os, const Vecteur2D& valeur) {
    os << "(X : " << valeur.m_x << ", Y : " << valeur.m_y << ")";
    return os; // Retourner l'objet ostream pour permettre le chaînage
}