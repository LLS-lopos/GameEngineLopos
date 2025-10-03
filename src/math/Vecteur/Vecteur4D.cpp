#include "Vecteur4D.h"
#include <math.h>

Vecteur4D::Vecteur4D() : m_x(0.0f), m_y(0.0f), m_z(0.0f), m_w(0.0f) {}
Vecteur4D::Vecteur4D(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w) {}
Vecteur4D::Vecteur4D(const Vecteur4D& valeur) : m_x(valeur.m_x), m_y(valeur.m_y), m_z(valeur.m_z), m_w(valeur.m_w) {}

Vecteur4D Vecteur4D::operator+(const Vecteur4D& valeur) const
{
    return Vecteur4D(m_x + valeur.m_x, m_y + valeur.m_y, m_z + valeur.m_z, m_w + valeur.m_w);
}

Vecteur4D Vecteur4D::operator*(const float& valeur) const
{
    return Vecteur4D(m_x * valeur, m_y * valeur, m_z * valeur, m_w * valeur);
}

Vecteur4D Vecteur4D::operator-(const Vecteur4D& valeur) const
{
    return Vecteur4D(m_x - valeur.m_x, m_y - valeur.m_y, m_z - valeur.m_z, m_w - valeur.m_w);
}

Vecteur4D Vecteur4D::operator/(const float& valeur) const
{
    float n = 1.0f / valeur;
    return Vecteur4D(m_x * n, m_y * n, m_z *n, m_w * n);
}

float Vecteur4D::Magnitude() const
{
    return sqrtf(m_x * m_x + m_y * m_y +  m_z * m_z + m_w * m_w);
}

void Vecteur4D::Normaliser()
{
    float distance = Magnitude();
    m_x /= distance;
    m_y /= distance;
    m_z /= distance;
    m_w /= distance;
}
Vecteur4D Vecteur4D::Normaliser() const
{
    return (*this) / Magnitude();
}

Vecteur4D& Vecteur4D::operator+=(const Vecteur4D& valeur)
{
    m_x += valeur.m_x;
    m_y += valeur.m_y;
    m_z += valeur.m_z;
    m_w += valeur.m_w;
    return (*this);
}
Vecteur4D& Vecteur4D::operator*=(float valeur)
{
    m_x *= valeur;
    m_y *= valeur;
    m_z *= valeur;
    m_w *= valeur;
    return (*this);
}
Vecteur4D& Vecteur4D::operator-=(const Vecteur4D& valeur)
{
    m_x -= valeur.m_x;
    m_y -= valeur.m_y;
    m_z -= valeur.m_z;
    m_w -= valeur.m_w;
    return (*this);
}
Vecteur4D& Vecteur4D::operator/=(float valeur)
{
    m_x /= valeur;
    m_y /= valeur;
    m_z /= valeur;
    m_w /= valeur;
    return (*this);
}
bool Vecteur4D::operator==(const Vecteur4D& valeur) const
{
    return (abs(m_x - valeur.m_x) < FLT_EPSILON && abs(m_y - valeur.m_y) < FLT_EPSILON && abs(m_z - valeur.m_z) < FLT_EPSILON);
}
bool Vecteur4D::operator!=(const Vecteur4D& valeur) const
{
    return (abs(m_x - valeur.m_x) > FLT_EPSILON || abs(m_y - valeur.m_y) > FLT_EPSILON || abs(m_z - valeur.m_z) > FLT_EPSILON);
}
float Vecteur4D::DotProduct(const Vecteur4D& a, const Vecteur4D& b)
{
    return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z + a.m_w * b.m_w;
}

std::ostream& operator<<(std::ostream& os, const Vecteur4D& valeur) {
    os << "(X : " << valeur.m_x << ", Y : " << valeur.m_y << ", Y : )" << valeur.m_z << ", N : " << valeur.m_w <<")" << std::endl;
    return os; // Retourner l'objet ostream pour permettre le chaînage
}