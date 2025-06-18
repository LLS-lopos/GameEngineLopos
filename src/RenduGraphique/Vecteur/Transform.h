#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include "Vecteur2D.h"

struct Transform
{
    /* data */
public:
    Transform();
    Transform(Vecteur2D position, Vecteur2D echelle, float angle);
    Vecteur2D m_position;
    Vecteur2D m_echelle;
    float m_angle;
};

#endif // _TRANSFORM_H_