#ifndef _VECTEUR4D_H_
#define _VECTEUR4D_H_
#include <iostream>

struct Vecteur4D
{
    float m_x;
    float m_y;
    float m_z;
    float m_w,

    Vecteur4D();
    Vecteur4D(float x, float y, float z, float w);
    Vecteur4D(const Vecteur4D& valeur);

    Vecteur4D operator+(const Vecteur4D& valeur) const;
    Vecteur4D operator*(const float& valeur) const;
    Vecteur4D operator-(const Vecteur4D& valeur) const;
    Vecteur4D operator/(const float& valeur) const;

    float Magnitude() const;
    void Normaliser();
    Vecteur4D Normaliser() const;

    Vecteur4D& operator+=(const Vecteur4D& valeur);
    Vecteur4D& operator*=(float valeur);
    Vecteur4D& operator-=(const Vecteur4D& valeur); 
    Vecteur4D& operator/=(float valeur);
    bool operator==(const Vecteur4D& valeur) const;
    bool operator!=(const Vecteur4D& valeur) const;

    static float DotProduct(const Vecteur4D& a, const Vecteur4D& b);
};
std::ostream& operator<<(std::ostream& os, const Vecteur4D& valeur);
#endif