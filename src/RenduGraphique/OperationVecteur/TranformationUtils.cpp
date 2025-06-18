#include "TranformationUtils.h"

Vecteur2D TranformationUtils::Identiter(const Vecteur2D& a)
{
    return a;
}

Vecteur2D TranformationUtils::Translation(const Vecteur2D& a, const Vecteur2D& b)
{
    return a+b;
}

Vecteur2D TranformationUtils::Echelle(const Vecteur2D& a, float s)
{
    return a*s;
}
Vecteur2D TranformationUtils::Homothety(const Vecteur2D& a, const Vecteur2D& b, float s)
{
    return (a-b)*s+b;
}
Vecteur2D TranformationUtils::PointReflection(const Vecteur2D& a, const Vecteur2D& centre)
{
    return (centre - a)*2+a;
}
float TranformationUtils::ProduitScalaire(const Vecteur2D& a, const Vecteur2D& b)
{
    return a.m_x * b.m_x + a.m_y * b.m_y;
}
Vecteur2D TranformationUtils::SymetrieAxial(const Vecteur2D& a, const Vecteur2D& axe)
{
    float axeMagniture = axe.Magnitude();
    return a + (axe * (ProduitScalaire(a, axe)/(axeMagniture*axeMagniture))-a) * 2.0f;
}
Vecteur2D TranformationUtils::SymetrieAxial(const Vecteur2D& a, const Vecteur2D& axe, const Vecteur2D& centre)
{
    float axeMagniture = axe.Magnitude();
    return a + (axe * (ProduitScalaire(a-centre, axe)/(axeMagniture*axeMagniture))-(a-centre)) * 2.0f;
}
Vecteur2D TranformationUtils::Rotation(const Vecteur2D& a, const float angle)
{
    float degreVersRadian = angle * M_PI / 180;
    float x = a.m_x * cos(degreVersRadian) - a.m_y * sin(degreVersRadian);
    float y = a.m_y * cos(degreVersRadian) - a.m_x * sin(degreVersRadian);
    return Vecteur2D(x, y);
}
Vecteur2D TranformationUtils::Rotation(const Vecteur2D& a, const Vecteur2D& centre, const float angle)
{
    float degreVersRadian = angle * M_PI / 180;
    float x = centre.m_x + (a.m_x - centre.m_x) * cos(degreVersRadian) - (a.m_y - centre.m_y) * sin(degreVersRadian);
    float y = centre.m_y + (a.m_y - centre.m_y) * cos(degreVersRadian) - (a.m_x - centre.m_y) * sin(degreVersRadian);
    return Vecteur2D(x, y);
}  

float TranformationUtils::PingPong(float t, float longueur)
{
    t = Repeter(t, longueur * 2.0f);
    return longueur - std::abs(t - longueur);
}

float TranformationUtils::Repeter(float t, float longueur)
{
    return std::clamp(t - std::floor(t / longueur) * longueur, 0.0f, longueur);
}