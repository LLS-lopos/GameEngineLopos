#ifndef _MATRICE_3X3_H_
#define _MATRICE_3X3_H_
#include <ostream>
#include <math.h>
#include "../Vecteur/Vecteur2D.h"
#include <array>
struct Matrice3x3
{
public:
	float m[3][3];

	Matrice3x3();
	Matrice3x3(float m00, float m01, float m02,
			  float m10, float m11, float m12,
			  float m20, float m21, float m22);
	
	Matrice3x3(const Matrice3x3& value);

	float& operator ()(int i, int j);
	const float& operator ()(int i, int j)const;

	Matrice3x3& operator +=(const Matrice3x3& b);
	Matrice3x3& operator -=(const Matrice3x3& b);
	Matrice3x3& operator *=(const float& s);
	Matrice3x3& operator *=(const Matrice3x3& b);
	bool operator==(const Matrice3x3& value)const;
	bool operator!=(const Matrice3x3& value)const;

	Matrice3x3 Transpose()const;
	Matrice3x3 Inverse()const;
	float Determinant()const;

	static Matrice3x3 Identity();
	static Matrice3x3 Translate(const Vecteur2D& translate);
	static Matrice3x3 RotateZ(const float& angle);
	static Matrice3x3 ScaleXY(const Vecteur2D& scale);

	static Matrice3x3 TS(const Vecteur2D& translate, const Vecteur2D& scale);
	static Matrice3x3 RS(const float& angle, const Vecteur2D& scale);
	static Matrice3x3 TR(const Vecteur2D& translate, const float& angle);
	static Matrice3x3 TRS(const Vecteur2D& translate, const float& angle, const Vecteur2D& scale);
	std::array<float, 9> GetAsArray() const;
};
Matrice3x3 operator +(const Matrice3x3& a, const Matrice3x3& b);
Matrice3x3 operator -(const Matrice3x3& a, const Matrice3x3& b);
Matrice3x3 operator *(const Matrice3x3& a, const float& s);
Matrice3x3 operator *(const float& s, const Matrice3x3& a);
Matrice3x3 operator *(const Matrice3x3& a, const Matrice3x3& b);
std::ostream& operator<<(std::ostream& os, const Matrice3x3& value);

Vecteur2D operator*(const Matrice3x3& a, const Vecteur2D& b);
Vecteur2D operator*(const Vecteur2D& b, const Matrice3x3& a);

Vecteur3D operator*(const Matrice3x3& a, const Vecteur3D& b);
Vecteur3D operator*(const Vecteur3D& b, const Matrice3x3& a);

#endif
