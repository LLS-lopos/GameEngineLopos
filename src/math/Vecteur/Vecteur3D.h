#ifndef _VECTEUR3D_H_
#define _VECTEUR3D_H_
#include <iostream>

struct Vecteur3D
{
    float m_x;
    float m_y;
    float m_z;

    Vecteur3D();
    Vecteur3D(float x, float y, float z);
    Vecteur3D(const Vecteur3D& valeur);

    Vecteur3D operator+(const Vecteur3D& valeur) const;
    Vecteur3D operator*(const float& valeur) const;
    Vecteur3D operator-(const Vecteur3D& valeur) const;
    Vecteur3D operator/(const float& valeur) const;

    float Magnitude() const;
    void Normaliser();
    Vecteur3D Normaliser() const;

    Vecteur3D& operator+=(const Vecteur3D& valeur);
    Vecteur3D& operator*=(float valeur);
    Vecteur3D& operator-=(const Vecteur3D& valeur); 
    Vecteur3D& operator/=(float valeur);
    bool operator==(const Vecteur3D& valeur) const;
    bool operator!=(const Vecteur3D& valeur) const;

    static Vecteur3D CrossProduct(const Vecteur3D& a, const Vecteur3D& b);
    static float DotProduct(const Vecteur3D& a, const Vecteur3D& b);
};
std::ostream& operator<<(std::ostream& os, const Vecteur3D& valeur);
#endif