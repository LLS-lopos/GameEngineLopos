#include "Vecteur3D.h"
#include <math.h>

Vecteur3D::Vecteur3D() : m_x(0.0f), m_y(0.0f), m_z(0.0f) {}
Vecteur3D::Vecteur3D(float x, float y, float z) : m_x(x), m_y(y), m_z(0.0f) {}
Vecteur3D::Vecteur3D(const Vecteur3D& valeur) : m_x(valeur.m_x), m_y(valeur.m_y), m_z(0.0f) {}

Vecteur3D Vecteur3D::operator+(const Vecteur3D& valeur) const
{
    return Vecteur3D(m_x + valeur.m_x, m_y + valeur.m_y, m_z + valeur.m_z);
}

Vecteur3D Vecteur3D::operator*(const float& valeur) const
{
    return Vecteur3D(m_x * valeur, m_y * valeur, m_z * valeur);
}

Vecteur3D Vecteur3D::operator-(const Vecteur3D& valeur) const
{
    return Vecteur3D(m_x - valeur.m_x, m_y - valeur.m_y, m_z - valeur.m_z);
}

Vecteur3D Vecteur3D::operator/(const float& valeur) const
{
    float n = 1.0f / valeur;
    return Vecteur3D(m_x * n, m_y * n, m_z * n);

}

float Vecteur3D::Magnitude() const
{
    return sqrtf(m_x * m_x + m_y * m_y + m_z * m_z);
}

void Vecteur3D::Normaliser()
{
    float distance = Magnitude();
    m_x /= distance;
    m_y /= distance;
    m_z /= distance;
}
Vecteur3D Vecteur3D::Normaliser() const
{
    return (*this) / Magnitude();
}

Vecteur3D& Vecteur3D::operator+=(const Vecteur3D& valeur)
{
    m_x += valeur.m_x;
    m_y += valeur.m_y;
    m_z += valeur.m_z;

    return (*this);
}
Vecteur3D& Vecteur3D::operator*=(float valeur)
{
    m_x *= valeur;
    m_y *= valeur;
    m_z *= valeur;

    return (*this);
}
Vecteur3D& Vecteur3D::operator-=(const Vecteur3D& valeur)
{
    m_x -= valeur.m_x;
    m_y -= valeur.m_y;
    m_z -= valeur.m_z;

    return (*this);
}
Vecteur3D& Vecteur3D::operator/=(float valeur)
{
    m_x *= valeur;
    m_y *= valeur;
    m_z *= valeur;

    return (*this);
}
bool Vecteur3D::operator==(const Vecteur3D& valeur) const
{
    const float epsilon = 1e-5; //ajuster selon les besoins
    return (abs(m_x - valeur.m_x) < epsilon || abs(m_y - valeur.m_y) < epsilon || abs(m_z - valeur.m_z) < epsilon);
}
bool Vecteur3D::operator!=(const Vecteur3D& valeur) const
{
    const float epsilon = 1e-5; //ajuster selon les besoins
    return (abs(m_x - valeur.m_x) > epsilon || abs(m_y - valeur.m_y) > epsilon || abs(m_z - valeur.m_z) > epsilon);
}

float Vecteur3D::DotProduct(const Vecteur3D& a, const Vecteur3D& b)
{
    return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
}

Vecteur3D Vecteur3D::CrossProduct(const Vecteur3D& a, const Vecteur3D& b)
{
    return Vecteur3D(a.m_y * b.m_z - b.m_y * a.m_z, a.m_z * b.m_x - b.m_z * a.m_x, a.m_x * b.m_y - b.m_x * a.m_y);
}

std::ostream& operator<<(std::ostream& os, const Vecteur3D& valeur) {
    os << "(X : " << valeur.m_x << ", Y : " << valeur.m_y << ", Y : )" << valeur.m_z << ")" << std::endl;
    return os; // Retourner l'objet ostream pour permettre le chaînage
}