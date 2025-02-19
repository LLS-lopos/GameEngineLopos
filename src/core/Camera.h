#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "../RenduGraphique/Vecteur/Vecteur2D.h"

class Camera
{
private:
    Vecteur2D m_position;
    float m_taille;
    bool m_siHorizontal;
    
public:
    Camera(Vecteur2D position, float taille, bool siHorizontal = true);
    void DefinirPosition(const Vecteur2D& position);
    void DefinirTaille(float taille);
    void DefinirOrientation(bool siHorizontal);
    Vecteur2D ObtenirTailleVetH(float largeur, float hauteur);

    Vecteur2D ObtenirPosition()const;
    float ObtenirTaille()const;
    bool ObtenirOrientation()const;
};

#endif // _CAMERA_H_