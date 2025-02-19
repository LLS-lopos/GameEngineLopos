#ifndef _VECTEUR2D_H_
#define _VECTEUR2D_H_
#include <ostream>
#include <cmath>

struct Vecteur2D 
{
    float m_x;
    float m_y;

    Vecteur2D();
    Vecteur2D(float x, float y);
    Vecteur2D(const Vecteur2D& valeur);

    Vecteur2D operator+(const Vecteur2D& valeur) const;
    Vecteur2D operator*(const float& valeur) const;
    Vecteur2D operator-(const Vecteur2D& valeur) const;
    Vecteur2D operator/(const float& valeur) const;

    float Magnitude() const;
    void Normaliser();
    Vecteur2D Normaliser() const;

    Vecteur2D& operator+=(const Vecteur2D& valeur);
    Vecteur2D& operator*=(float valeur);
    Vecteur2D& operator-=(const Vecteur2D& valeur); 
    Vecteur2D& operator/=(float valeur);

    bool operator==(const Vecteur2D& valeur) const;
    bool operator!=(const Vecteur2D& valeur) const;
private:
    float m_z;
};
std::ostream& operator<<(std::ostream& os, const Vecteur2D& valeur);
#endif // _VECTEUR2D_H_