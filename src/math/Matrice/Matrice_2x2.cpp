#include "Matrice_2x2.h"
# define M_PI           3.14159265358979323846  /* pi */

Matrice2x2::Matrice2x2()
{
	m[0][0] = 0.0f; m[0][1] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 0.0f;
}

Matrice2x2::Matrice2x2(float m00, float m01,
	float m10, float m11)
{
	m[0][0] = m00; m[0][1] = m01;
	m[1][0] = m10; m[1][1] = m11;
}

Matrice2x2::Matrice2x2(const Vecteur2D& a, const Vecteur2D& b)
{
	m[0][0] = a.m_x; m[0][1] = b.m_x;
	m[1][0] = a.m_y; m[1][1] = b.m_y;
}

Matrice2x2::Matrice2x2(const Matrice2x2& value)
{
	m[0][0] = value.m[0][0];
	m[0][1] = value.m[0][1];
	m[1][0] = value.m[1][0];
	m[1][1] = value.m[1][1];
}

float& Matrice2x2::operator ()(int i, int j)
{
	return m[i][j];
}

const float& Matrice2x2::operator ()(int i, int j)const
{
	return m[i][j];
}

Matrice2x2& Matrice2x2::operator +=(const Matrice2x2& b)
{
	m[0][0] += b.m[0][0];
	m[0][1] += b.m[0][1];
	m[1][0] += b.m[1][0];
	m[1][1] += b.m[1][1];

	return (*this);
}

Matrice2x2& Matrice2x2::operator -=(const Matrice2x2& b)
{
	m[0][0] -= b.m[0][0];
	m[0][1] -= b.m[0][1];
	m[1][0] -= b.m[1][0];
	m[1][1] -= b.m[1][1];

	return (*this);
}

Matrice2x2& Matrice2x2::operator *=(const float& s)
{
	m[0][0] *= s;
	m[0][1] *= s;
	m[1][0] *= s;
	m[1][1] *= s;

	return (*this);
}

Matrice2x2& Matrice2x2::operator *=(const Matrice2x2& b)
{
	float t00 = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0];
	float t01 = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1];
	float t10 = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0];
	float t11 = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1];

	m[0][0] = t00;
	m[0][1] = t01;
	m[1][0] = t10;
	m[1][1] = t11;

	return (*this);
}

Matrice2x2 Matrice2x2::Transpose()const
{
	return Matrice2x2(m[0][0], m[1][0],
					 m[0][1], m[1][1]);
}

Matrice2x2 Matrice2x2::Inverse()const
{
	float determinant = Determinant();
	float epsilon = 1e-5; // Change this to the level of precision you need

	if (fabs(determinant) < epsilon)
	{
		throw std::invalid_argument("Matrix is singular (determinant is 0) and cannot be inverted.");
	}
	Matrice2x2 adjugateMatrix = Matrice2x2(m[1][1], -m[0][1],
										-m[1][0], m[0][0]);
	
	return (1.0f / determinant) * adjugateMatrix;
}

float Matrice2x2::Determinant()const
{
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

Matrice2x2 operator +(const Matrice2x2& a, const Matrice2x2& b)
{
	return Matrice2x2(a.m[0][0] + b.m[0][0], a.m[0][1] + b.m[0][1],
		a.m[1][0] + b.m[1][0], a.m[1][1] + b.m[1][1]);
}

Matrice2x2 operator -(const Matrice2x2& a, const Matrice2x2& b)
{
	return Matrice2x2(a.m[0][0] - b.m[0][0], a.m[0][1] - b.m[0][1],
		a.m[1][0] - b.m[1][0], a.m[1][1] - b.m[1][1]);
}

Matrice2x2 operator *(const Matrice2x2& a, const float& s)
{
	return Matrice2x2(a.m[0][0] * s, a.m[0][1] * s,
		a.m[1][0] * s, a.m[1][1] * s);
}

Matrice2x2 operator *(const float& s, const Matrice2x2& a)
{
	return Matrice2x2(s * a.m[0][0], s * a.m[0][1],
		s * a.m[1][0], s * a.m[1][1]);
}

Matrice2x2 operator *(const Matrice2x2& a, const Matrice2x2& b)
{
	return Matrice2x2(a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0],         // Element 00
					 a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1],	        // Element 01
					 a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0],			// Element 10
					 a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]);		// Element 11
}

bool Matrice2x2::operator==(const Matrice2x2& value) const
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (m[i][j] != value.m[i][j])
				return false;
		}
	}
	return true;
}

bool Matrice2x2::operator!=(const Matrice2x2& value) const
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (m[i][j] != value.m[i][j])
				return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Matrice2x2& value)
{
	os << "(m00 : " << value.m[0][0] << ", m01 : " << value.m[0][1] << ")" << std::endl
		<< "(m10 : " << value.m[1][0] << ", m11 : " << value.m[1][1] << ")" << std::endl;
	return os;
}

Matrice2x2 Matrice2x2::Identity()
{
	return Matrice2x2(1.0f, 0.0f,
		0.0f, 1.0f);
}

Matrice2x2 Matrice2x2::Rotate(const float& angle)
{
	float angleInRadian = angle * M_PI / 180.0f;
		return Matrice2x2(cosf(angleInRadian), -sinf(angleInRadian),
						 sinf(angleInRadian), cosf(angleInRadian));
}

Matrice2x2 Matrice2x2::Scale(const Vecteur2D& scale)
{
	return Matrice2x2(scale.m_x,0.0f,
					 0.0f, scale.m_y);
}

Matrice2x2 Matrice2x2::RS(const float& angle, const Vecteur2D& scale)
{
	return Rotate(angle) * Scale(scale);
}

Vecteur2D operator*(const Matrice2x2& a, const Vecteur2D& b)
{
	return Vecteur2D(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y, a.m[1][0] * b.m_x + a.m[1][1] * b.m_y);
}

Vecteur2D operator*(const Vecteur2D& b, const Matrice2x2& a)
{
	return Vecteur2D(b.m_x* a.m[0][0] + b.m_y * a.m[0][1], b.m_x * a.m[1][0] + b.m_y * a.m[1][1]);
}