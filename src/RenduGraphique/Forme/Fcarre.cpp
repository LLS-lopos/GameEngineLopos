#include "Forme.h"

Forme *Forme::CreationCarre(Shader *shader, GLDrawType glDrawType, Vecteur2D position, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, position, 4, rayon, filaire);
}