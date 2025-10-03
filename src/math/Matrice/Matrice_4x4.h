#ifndef _MATRICE_4X4_H_
#define _MATRICE_4X4_H_
#include <ostream>
#include <math.h>
#include "../Vecteur/Vecteur3D.h"
#include "../Vecteur/Vecteur4D.h"
#include <array>
struct Matrice4x4
{
public:
	float m[4][4];

	Matrice4x4();
	Matrice4x4(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33);
    
    Matrice4x4(const Vecteur3D& a,const Vecteur3D& b,const Vecteur3D& c);
    Matrice4x4(const Vecteur4D& a,const Vecteur4D& b,const Vecteur4D& c, const Vecteur4D& d);
	
	Matrice4x4(const Matrice4x4& value);

	float& operator ()(int i, int j);
	const float& operator ()(int i, int j)const;

	Matrice4x4& operator +=(const Matrice4x4& b);
	Matrice4x4& operator -=(const Matrice4x4& b);
	Matrice4x4& operator *=(const float& s);
	Matrice4x4& operator *=(const Matrice4x4& b);
	bool operator==(const Matrice4x4& value)const;
	bool operator!=(const Matrice4x4& value)const;

	Matrice4x4 Transpose()const;
	Matrice4x4 Inverse()const;
	float Determinant()const;

	static Matrice4x4 Identity();
	static Matrice4x4 Translate(const Vecteur3D& translate);
    static Matrice4x4 RotateX(const float& angle);
    static Matrice4x4 RotateY(const float& angle);
	static Matrice4x4 RotateZ(const float& angle);
    static Matrice4x4 Rotate(const Vecteur3D& angle);
	static Matrice4x4 ScaleXYZ(const Vecteur3D& scale);

	static Matrice4x4 TS(const Vecteur3D& translate, const Vecteur3D& scale);
	static Matrice4x4 RS(const Vecteur3D& angle, const Vecteur3D& scale);
	static Matrice4x4 TR(const Vecteur3D& translate, const Vecteur3D& angle);
	static Matrice4x4 TRS(const Vecteur3D& translate, const Vecteur3D& angle, const Vecteur3D& scale);
	std::array<float, 16> GetAsArray() const;
};
Matrice4x4 operator +(const Matrice4x4& a, const Matrice4x4& b);
Matrice4x4 operator -(const Matrice4x4& a, const Matrice4x4& b);
Matrice4x4 operator *(const Matrice4x4& a, const float& s);
Matrice4x4 operator *(const float& s, const Matrice4x4& a);
Matrice4x4 operator *(const Matrice4x4& a, const Matrice4x4& b);
std::ostream& operator<<(std::ostream& os, const Matrice4x4& value);

Vecteur3D operator*(const Matrice4x4& a, const Vecteur3D& b);
Vecteur3D operator*(const Vecteur3D& b, const Matrice4x4& a);
Vecteur4D operator*(const Vecteur4D& b, const Matrice4x4& a);
Vecteur4D operator*(const Matrice4x4& a, const Vecteur4D& b);

#endif
