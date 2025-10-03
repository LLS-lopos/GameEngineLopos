#ifndef _TRANFORMATIONUTILS_H_
#define _TRANFORMATIONUTILS_H_
#include "../Vecteur/Vecteur2D.h"
#include <iostream>
#include <math.h>
#include <algorithm>

class TranformationUtils
{
public:
    static Vecteur2D Identiter(const Vecteur2D& a);
    static Vecteur2D Translation(const Vecteur2D& a, const Vecteur2D& b);
    static Vecteur2D Echelle(const Vecteur2D& a, float s);

    static Vecteur2D Homothety(const Vecteur2D& a, const Vecteur2D& b, float s);
    static Vecteur2D PointReflection(const Vecteur2D& a, const Vecteur2D& centre);

    static Vecteur2D SymetrieAxial(const Vecteur2D& a, const Vecteur2D& axe);
    static Vecteur2D SymetrieAxial(const Vecteur2D& a, const Vecteur2D& axe, const Vecteur2D& centre);

    static Vecteur2D Rotation(const Vecteur2D& a, const float angle);
    static Vecteur2D Rotation(const Vecteur2D& a, const Vecteur2D& centre, const float angle);

    static float PingPong(float t, float longueur);
    static float Repeter(float t, float longueur);

private:
    TranformationUtils() {};
    static float ProduitScalaire(const Vecteur2D& a, const Vecteur2D& b);
};


#endif // _TRANFORMATIONUTILS_H_