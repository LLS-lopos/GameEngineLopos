#ifndef _FORME_VEC2D_H_
#define _FORME_VEC2D_H_
#include "Vecteur2D.h"
#include "../Forme/Forme.h"

class FormeVec2D
{
public:
    FormeVec2D(Vecteur2D vecteur, Vecteur2D position, float r, float g, float b, float a);
    ~FormeVec2D();
    void RecupValeur(Vecteur2D vecteur);
    void RecupPosition(Vecteur2D position);
    void Draw(Camera* camera, Fenetre* fenetre);

private:
    Vecteur2D valeur;
    Forme* m_forme;
    Shader* m_shader;
};



#endif // _FORME_VEC2D_H_