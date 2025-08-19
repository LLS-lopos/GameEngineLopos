#ifndef _MATRICE_2X2_H_
#define _MATRICE_2X2_H_
#include "../Vecteur/Vecteur2D.h"

struct Matrice2x2

{
    public:
    float m[2][2];

    Matrice2x2();
    Matrice2x2(float m00, float m01,
                float m10, float m11);

    Matrice2x2(const Vecteur2D& a, const Vecteur2D& b);
    Matrice2x2(const Matrice2x2& value);

    float& operator ()(int i, int j);
    const float& operator ()(int i, int j)const;

    Matrice2x2& operator +=(const Matrice2x2& b);
    Matrice2x2& operator -=(const Matrice2x2& b);
    Matrice2x2& operator *=(const float& s);
    Matrice2x2& operator *=(const Matrice2x2& b);
    bool operator==(const Matrice2x2& value)const;
    bool operator!=(const Matrice2x2& value)const;
    Matrice2x2 Transpose()const;
    Matrice2x2 Inverse()const;
    float Determinant()const;

    static Matrice2x2 Identity();
    static Matrice2x2 Rotate(const float& angle);
    static Matrice2x2 Scale(const Vecteur2D& scale);
    static Matrice2x2 RS(const float& angle, const Vecteur2D& scale);
        
};
Matrice2x2 operator +(const Matrice2x2& a, const Matrice2x2& b);
Matrice2x2 operator -(const Matrice2x2& a, const Matrice2x2& b);
Matrice2x2 operator *(const Matrice2x2& a, const float& s);
Matrice2x2 operator *(const float& s, const Matrice2x2& a);
Matrice2x2 operator *(const Matrice2x2& a, const Matrice2x2& b);
std::ostream& operator<<(std::ostream& os, const Matrice2x2& value);

Vecteur2D operator*(const Matrice2x2& a, const Vecteur2D& b);
Vecteur2D operator*(const Vecteur2D& b, const Matrice2x2& a);
    
#endif
    