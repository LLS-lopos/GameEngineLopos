#include "Matrice_4x4.h"
#include "Matrice_3x3.h"
#define M_PI           3.14159265358979323846  /* pi */

Matrice4x4::Matrice4x4()
{
	m[0][0] = 0.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 0.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f; m[2][3] = 0.0f;
    m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 0.0f;
}

Matrice4x4::Matrice4x4(float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[3][3] = m33;
}

Matrice4x4::Matrice4x4(const Vecteur3D& a, const Vecteur3D& b, const Vecteur3D& c)
{
    m[0][0] = a.m_x; m[0][1] = b.m_x; m[0][2] = c.m_x; m[0][3] = 0.0f;
	m[1][0] = a.m_y; m[1][1] = b.m_y; m[1][2] = c.m_y; m[1][3] = 0.0f;
	m[2][0] = a.m_z; m[2][1] = b.m_z; m[2][2] = c.m_z; m[2][3] = 0.0f;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f; m[3][3] = 0.0f;
}
Matrice4x4::Matrice4x4(const Vecteur4D& a, const Vecteur4D& b, const Vecteur4D& c, const Vecteur4D& d)
{
    m[0][0] = a.m_x; m[0][1] = b.m_x; m[0][2] = c.m_x; m[0][3] = d.m_x;
	m[1][0] = a.m_y; m[1][1] = b.m_y; m[1][2] = c.m_y; m[1][3] = d.m_y;
	m[2][0] = a.m_z; m[2][1] = b.m_z; m[2][2] = c.m_z; m[2][3] = d.m_z;
    m[2][0] = a.m_w; m[2][1] = b.m_w; m[2][2] = c.m_w; m[3][3] = d.m_w;
}

Matrice4x4::Matrice4x4(const Matrice4x4& value)
{
	m[0][0] = value.m[0][0];
	m[0][1] = value.m[0][1];
	m[0][2] = value.m[0][2];
    m[0][3] = value.m[0][3];

	m[1][0] = value.m[1][0];
	m[1][1] = value.m[1][1];
	m[1][2] = value.m[1][2];
    m[1][3] = value.m[1][3];

	m[2][0] = value.m[2][0];
	m[2][1] = value.m[2][1];
	m[2][2] = value.m[2][2];
    m[2][3] = value.m[2][3];

    m[3][0] = value.m[3][0];
	m[3][1] = value.m[3][1];
	m[3][2] = value.m[3][2];
    m[3][3] = value.m[3][3];
}


float& Matrice4x4::operator ()(int i, int j)
{
	return m[i][j];
}

const float& Matrice4x4::operator ()(int i, int j)const
{
	return m[i][j];
}

Matrice4x4& Matrice4x4::operator +=(const Matrice4x4& b)
{
	m[0][0] += b.m[0][0];
	m[0][1] += b.m[0][1];
	m[0][2] += b.m[0][2];
    m[0][3] += b.m[0][3];

	m[1][0] += b.m[1][0];
	m[1][1] += b.m[1][1];
	m[1][2] += b.m[1][2];
    m[1][3] += b.m[1][3];

	m[2][0] += b.m[2][0];
	m[2][1] += b.m[2][1];
	m[2][2] += b.m[2][2];
    m[2][3] += b.m[2][3];

    m[3][0] += b.m[3][0];
	m[3][1] += b.m[3][1];
	m[3][2] += b.m[3][2];
    m[3][3] += b.m[3][3];

	return (*this);
}

Matrice4x4& Matrice4x4::operator -=(const Matrice4x4& b)
{
	m[0][0] -= b.m[0][0];
	m[0][1] -= b.m[0][1];
	m[0][2] -= b.m[0][2];
    m[0][3] -= b.m[0][3];

	m[1][0] -= b.m[1][0];
	m[1][1] -= b.m[1][1];
	m[1][2] -= b.m[1][2];
    m[1][3] -= b.m[1][3];

	m[2][0] -= b.m[2][0];
	m[2][1] -= b.m[2][1];
	m[2][2] -= b.m[2][2];
    m[2][3] -= b.m[2][3];

    m[3][0] -= b.m[3][0];
	m[3][1] -= b.m[3][1];
	m[3][2] -= b.m[3][2];
    m[3][3] -= b.m[3][3];

	return (*this);
}

Matrice4x4& Matrice4x4::operator *=(const float& s)
{
	m[0][0] *= s;
	m[0][1] *= s;
	m[0][2] *= s;
    m[0][3] *= s;

	m[1][0] *= s;
	m[1][1] *= s;
	m[1][2] *= s;
    m[1][3] *= s;

	m[2][0] *= s;
	m[2][1] *= s;
	m[2][2] *= s;
    m[2][3] *= s;

    m[3][0] *= s;
	m[3][1] *= s;
	m[3][2] *= s;
    m[3][3] *= s;

	return (*this);
}

Matrice4x4& Matrice4x4::operator *=(const Matrice4x4& b)
{
	Matrice4x4 result;

	result.m[0][0] = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0] + m[0][2] * b.m[2][0];
	result.m[0][1] = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1] + m[0][2] * b.m[2][1];
	result.m[0][2] = m[0][0] * b.m[0][2] + m[0][1] * b.m[1][2] + m[0][2] * b.m[2][2];
    result.m[0][3] = m[0][0] * b.m[0][3] + m[0][1] * b.m[1][3] + m[0][2] * b.m[2][3];

	result.m[1][0] = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0] + m[1][2] * b.m[2][0];
	result.m[1][1] = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1] + m[1][2] * b.m[2][1];
	result.m[1][2] = m[1][0] * b.m[0][2] + m[1][1] * b.m[1][2] + m[1][2] * b.m[2][2];
    result.m[1][3] = m[1][0] * b.m[0][3] + m[1][1] * b.m[1][3] + m[1][2] * b.m[2][3];

	result.m[2][0] = m[2][0] * b.m[0][0] + m[2][1] * b.m[1][0] + m[2][2] * b.m[2][0];
	result.m[2][1] = m[2][0] * b.m[0][1] + m[2][1] * b.m[1][1] + m[2][2] * b.m[2][1];
	result.m[2][2] = m[2][0] * b.m[0][2] + m[2][1] * b.m[1][2] + m[2][2] * b.m[2][2];
    result.m[2][3] = m[2][0] * b.m[0][3] + m[2][1] * b.m[1][3] + m[2][2] * b.m[2][3];

    result.m[3][0] = m[3][0] * b.m[0][0] + m[3][1] * b.m[1][0] + m[3][2] * b.m[2][0];
	result.m[3][1] = m[3][0] * b.m[0][1] + m[3][1] * b.m[1][1] + m[3][2] * b.m[2][1];
	result.m[3][2] = m[3][0] * b.m[0][2] + m[3][1] * b.m[1][2] + m[3][2] * b.m[2][2];
    result.m[3][3] = m[3][0] * b.m[0][3] + m[3][1] * b.m[1][3] + m[3][2] * b.m[2][3];

	*this = result;
	return (*this);
}

Matrice4x4 Matrice4x4::Transpose() const
{
	return Matrice4x4(m[0][0], m[1][0], m[2][0], m[3][0],
        m[0][1], m[1][1], m[2][1], m[3][1],
        m[0][2], m[1][2], m[2][2], m[3][2],
        m[0][3], m[1][3], m[2][3], m[3][3]);
}

Matrice4x4 Matrice4x4::Inverse()const
{
	float determinant = Determinant();
	float epsilon = 1e-5; // Change this to the level of precision you need

	if (fabs(determinant) < epsilon)
	{
		throw std::invalid_argument("La Matrice est singulière (le déterminant est 0) et ne peut pas être inversé.");
	}
    Matrice3x3 subMatrix00 = Matrice3x3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);
	Matrice3x3 subMatrix01 = Matrice3x3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);
	Matrice3x3 subMatrix02 = Matrice3x3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);
	Matrice3x3 subMatrix03 = Matrice3x3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);

	Matrice3x3 subMatrix10 = Matrice3x3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);
	Matrice3x3 subMatrix11 = Matrice3x3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);
	Matrice3x3 subMatrix12 = Matrice3x3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);
	Matrice3x3 subMatrix13 = Matrice3x3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);

	Matrice3x3 subMatrix20 = Matrice3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);
	Matrice3x3 subMatrix21 = Matrice3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);
	Matrice3x3 subMatrix22 = Matrice3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);
	Matrice3x3 subMatrix23 = Matrice3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);

	Matrice3x3 subMatrix30 = Matrice3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);
	Matrice3x3 subMatrix31 = Matrice3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);
	Matrice3x3 subMatrix32 = Matrice3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);
	Matrice3x3 subMatrix33 = Matrice3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);

	float C00 = powf(-1, 0 + 0) * subMatrix00.Determinant();
	float C01 = powf(-1, 0 + 1) * subMatrix01.Determinant();
	float C02 = powf(-1, 0 + 2) * subMatrix02.Determinant();
	float C03 = powf(-1, 0 + 3) * subMatrix03.Determinant();

	float C10 = powf(-1, 1 + 0) * subMatrix10.Determinant();
	float C11 = powf(-1, 1 + 1) * subMatrix11.Determinant();
	float C12 = powf(-1, 1 + 2) * subMatrix12.Determinant();
	float C13 = powf(-1, 1 + 3) * subMatrix13.Determinant();

	float C20 = powf(-1, 2 + 0) * subMatrix20.Determinant();
	float C21 = powf(-1, 2 + 1) * subMatrix21.Determinant();
	float C22 = powf(-1, 2 + 2) * subMatrix22.Determinant();
	float C23 = powf(-1, 2 + 3) * subMatrix23.Determinant();

	float C30 = powf(-1, 3 + 0) * subMatrix30.Determinant();
	float C31 = powf(-1, 3 + 1) * subMatrix31.Determinant();
	float C32 = powf(-1, 3 + 2) * subMatrix32.Determinant();
	float C33 = powf(-1, 3 + 3) * subMatrix33.Determinant();

	const Matrice4x4 CofactorMatrix = Matrice4x4(C00, C01, C02, C03,
		C10, C11, C12, C13,
		C20, C21, C22, C23,
		C30, C31, C32, C33);

	Matrice4x4 adjugateMatrix = CofactorMatrix.Transpose();

	return (1.0f / determinant) * adjugateMatrix;
}

float Matrice4x4::Determinant()const
{
	Matrice3x3 subMatrix00 = Matrice3x3(m[1][1], m[1][2], m[1][3],
									  m[2][1], m[2][2], m[2][3],
									  m[3][1], m[3][2], m[3][3]);

	Matrice3x3 subMatrix01 = Matrice3x3(m[1][0], m[1][2], m[1][3],
									  m[2][0], m[2][2], m[2][3],
									  m[3][0], m[3][2], m[3][3]);

	Matrice3x3 subMatrix02 = Matrice3x3(m[1][0], m[1][1], m[1][3],
									  m[2][0], m[2][1], m[2][3],
									  m[3][0], m[3][1], m[3][3]);

	Matrice3x3 subMatrix03 = Matrice3x3(m[1][0], m[1][1], m[1][2],
									  m[2][0], m[2][1], m[2][2],
									  m[3][0], m[3][1], m[3][2]);

	float determinant = m[0][0] * subMatrix00.Determinant() - m[0][1] * subMatrix01.Determinant()
		+ m[0][2] * subMatrix02.Determinant() - m[0][3] * subMatrix03.Determinant();

	return determinant;
}

Matrice4x4 operator +(const Matrice4x4& a, const Matrice4x4& b)
{
	return Matrice4x4(a.m[0][0] + b.m[0][0], a.m[0][1] + b.m[0][1], a.m[0][2] + b.m[0][2], a.m[0][3] + b.m[0][3],
					 a.m[1][0] + b.m[1][0], a.m[1][1] + b.m[1][1], a.m[1][2] + b.m[1][2], a.m[1][3] + b.m[1][3],
					 a.m[2][0] + b.m[2][0], a.m[2][1] + b.m[2][1], a.m[2][2] + b.m[2][2], a.m[2][3] + b.m[2][3],
					 a.m[3][0] + b.m[3][0], a.m[3][1] + b.m[3][1], a.m[3][2] + b.m[3][2], a.m[3][3] + b.m[3][3]);
}

Matrice4x4 operator -(const Matrice4x4& a, const Matrice4x4& b)
{
	return Matrice4x4(a.m[0][0] - b.m[0][0], a.m[0][1] - b.m[0][1], a.m[0][2] - b.m[0][2], a.m[0][3] - b.m[0][3],
		a.m[1][0] - b.m[1][0], a.m[1][1] - b.m[1][1], a.m[1][2] - b.m[1][2], a.m[1][3] - b.m[1][3],
		a.m[2][0] - b.m[2][0], a.m[2][1] - b.m[2][1], a.m[2][2] - b.m[2][2], a.m[2][3] - b.m[2][3],
		a.m[3][0] - b.m[3][0], a.m[3][1] - b.m[3][1], a.m[3][2] - b.m[3][2], a.m[3][3] - b.m[3][3]);
}

Matrice4x4 operator *(const Matrice4x4& a, const float& s)
{
	return Matrice4x4(a.m[0][0] * s, a.m[0][1] * s, a.m[0][2] * s, a.m[0][3] * s,
					 a.m[1][0] * s, a.m[1][1] * s, a.m[1][2] * s, a.m[1][3] * s,
					 a.m[2][0] * s, a.m[2][1] * s, a.m[2][2] * s, a.m[2][3] * s,
					 a.m[3][0] * s, a.m[3][1] * s, a.m[3][2] * s, a.m[3][3] * s);
}

Matrice4x4 operator *(const float& s, const Matrice4x4& a)
{
	return Matrice4x4(s * a.m[0][0], s * a.m[0][1], s * a.m[0][2], s * a.m[0][3],
					 s * a.m[1][0], s * a.m[1][1], s * a.m[1][2], s * a.m[1][3],
					 s * a.m[2][0], s * a.m[2][1], s * a.m[2][2], s * a.m[2][3],
					 s * a.m[3][0], s * a.m[3][1], s * a.m[3][2], s * a.m[3][3]);
}

Matrice4x4 operator *(const Matrice4x4& a, const Matrice4x4& b)
{
	return Matrice4x4(a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] + a.m[0][3] * b.m[3][0],
					 a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] + a.m[0][3] * b.m[3][1],
					 a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] + a.m[0][3] * b.m[3][2],
					 a.m[0][0] * b.m[0][3] + a.m[0][1] * b.m[1][3] + a.m[0][2] * b.m[2][3] + a.m[0][3] * b.m[3][3],

					 a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] + a.m[1][3] * b.m[3][0],
					 a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] + a.m[1][3] * b.m[3][1],
					 a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] + a.m[1][3] * b.m[3][2],
					 a.m[1][0] * b.m[0][3] + a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] + a.m[1][3] * b.m[3][3],

					 a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] + a.m[2][3] * b.m[3][0],
					 a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] + a.m[2][3] * b.m[3][1],
					 a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] + a.m[2][3] * b.m[3][2],
					 a.m[2][0] * b.m[0][3] + a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] + a.m[2][3] * b.m[3][3],

					 a.m[3][0] * b.m[0][0] + a.m[3][1] * b.m[1][0] + a.m[3][2] * b.m[2][0] + a.m[3][3] * b.m[3][0],
					 a.m[3][0] * b.m[0][1] + a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] + a.m[3][3] * b.m[3][1],
					 a.m[3][0] * b.m[0][2] + a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] + a.m[3][3] * b.m[3][2],
					 a.m[3][0] * b.m[0][3] + a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] + a.m[3][3] * b.m[3][3]);
}

bool Matrice4x4::operator==(const Matrice4x4& value) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (abs(m[i][j] - value.m[i][j]) > FLT_EPSILON)
				return false;
		}
	}
	return true;
}

bool Matrice4x4::operator!=(const Matrice4x4& value) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (abs(m[i][j] - value.m[i][j]) > FLT_EPSILON)
				return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Matrice4x4& value)
{
	os << "(m00 : " << value.m[0][0] << ", m01 : " << value.m[0][1] << ", m02 : " << value.m[0][2] << ", m03 : " << value.m[0][3] << ")" << std::endl
		<< "(m10 : " << value.m[1][0] << ", m11 : " << value.m[1][1] << ", m12 : " << value.m[1][2] << ", m13 : " << value.m[1][3] << ")" << std::endl
		<< "(m20 : " << value.m[2][0] << ", m21 : " << value.m[2][1] << ", m22 : " << value.m[2][2] << ", m23 : " << value.m[2][3] << ")" << std::endl
		<< "(m30 : " << value.m[3][0] << ", m31 : " << value.m[3][1] << ", m32 : " << value.m[3][2] << ", m33 : " << value.m[3][3] << ")" << std::endl;
	return os;
}

Matrice4x4 Matrice4x4::Identity()
{
	return Matrice4x4(1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

Matrice4x4 Matrice4x4::Translate(const Vecteur3D& translate)
{
	return Matrice4x4(1.0f, 0.0f, 0.0f, translate.m_x,
					 0.0f, 1.0f, 0.0f, translate.m_y,
					 0.0f, 0.0f, 1.0f, translate.m_z,
                     0.0f, 0.0f, 0.0f, 1.0f);
}

Matrice4x4 Matrice4x4::RotateX(const float& angle)
{
	float angleInRadiant = angle * M_PI / 180.0f;
	return Matrice4x4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosf(angleInRadiant), -sinf(angleInRadiant), 0.0f,
		0.0f, sinf(angleInRadiant), cosf(angleInRadiant), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrice4x4 Matrice4x4::RotateY(const float& angle)
{
	float angleInRadiant = angle * M_PI / 180.0f;
	return Matrice4x4(cosf(angleInRadiant), 0.0f, sinf(angleInRadiant), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-sinf(angleInRadiant), 0.0f, cosf(angleInRadiant), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}
Matrice4x4 Matrice4x4::RotateZ(const float& angle)
{
	float angleInRadiant = angle * M_PI / 180.0f;
	return Matrice4x4(cosf(angleInRadiant), -sinf(angleInRadiant), 0.0f,0.0f,
					 sinf(angleInRadiant), cosf(angleInRadiant), 0.0f,0.0f,
					 0.0f, 0.0f,1.0f, 0.0f,
					 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrice4x4 Matrice4x4::Rotate(const Vecteur3D& angles)
{
	return RotateZ(angles.m_z) * RotateY(angles.m_y) * RotateX(angles.m_x);
}

Matrice4x4 Matrice4x4::ScaleXYZ(const Vecteur3D& scale)
{
	return Matrice4x4(scale.m_x, 0.0f, 0.0f,0.0f,
		0.0f, scale.m_y, 0.0f, 0.0f,
		0.0f, 0.0f, scale.m_z,0.0f,
		0.0f, 0.0f, 0.0f,1.0f);
}

Matrice4x4 Matrice4x4::TS(const Vecteur3D& translate, const Vecteur3D& scale)
{
	return Translate(translate) * ScaleXYZ(scale);
}

Matrice4x4 Matrice4x4::RS(const Vecteur3D& angle, const Vecteur3D& scale)
{
	return Rotate(angle) * ScaleXYZ(scale);
}

Matrice4x4 Matrice4x4::TR(const Vecteur3D& translate, const Vecteur3D& angles)
{
	return Translate(translate) * Rotate(angles);
}

Matrice4x4 Matrice4x4::TRS(const Vecteur3D& translate, const Vecteur3D& angles, const Vecteur3D& scale)
{
	return Translate(translate) * Rotate(angles) * ScaleXYZ(scale);
}

Vecteur3D operator*(const Matrice4x4& a, const Vecteur3D& b)
{
	return Vecteur3D(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * 1.0f, 
					a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * 1.0f,
					a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * 1.0f);
}

Vecteur3D operator*(const Vecteur3D& b, const Matrice4x4& a)
{
	return Vecteur3D(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * 1.0f,
		a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * 1.0f,
		a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * 1.0f);
}

Vecteur4D operator*(const Vecteur4D& b, const Matrice4x4& a)
{
	return Vecteur4D(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * b.m_w,
					a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * b.m_w,
					a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * b.m_w,
					a.m[2][0] * b.m_x + a.m[3][1] * b.m_y + a.m[3][2] * b.m_z + a.m[3][3] * b.m_w);
}

Vecteur4D operator*(const Matrice4x4& a, const Vecteur4D& b)
{
	return Vecteur4D(a.m[0][0] * b.m_x + a.m[0][1] * b.m_y + a.m[0][2] * b.m_z + a.m[0][3] * b.m_w,
		a.m[1][0] * b.m_x + a.m[1][1] * b.m_y + a.m[1][2] * b.m_z + a.m[1][3] * b.m_w,
		a.m[2][0] * b.m_x + a.m[2][1] * b.m_y + a.m[2][2] * b.m_z + a.m[2][3] * b.m_w,
		a.m[2][0] * b.m_x + a.m[3][1] * b.m_y + a.m[3][2] * b.m_z + a.m[3][3] * b.m_w);
}


std::array<float, 16> Matrice4x4::GetAsArray() const
{
	return { m[0][0], m[0][1], m[0][2], m[0][3],
			 m[1][0], m[1][1], m[1][2], m[0][3],
			 m[2][0], m[2][1], m[2][2], m[0][3],
			 m[3][0], m[3][1], m[3][2], m[0][3],
	};
}