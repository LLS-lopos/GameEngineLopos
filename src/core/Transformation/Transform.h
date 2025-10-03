#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include "../../math/Vecteur/Vecteur2D.h"
#include "../../math/Matrice/Matrice_3x3.h"

struct Transform
{
    /* data */
public:
    Transform();
    Transform(Vecteur2D position, Vecteur2D echelle, float angle);
    Vecteur2D m_position;
    Vecteur2D m_echelle;
    float m_angle;

    Matrice3x3 TransformeMatrice();
};

#endif // _TRANSFORM_H_