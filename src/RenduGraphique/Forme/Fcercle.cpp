#include "Forme.h"

Forme *Forme::CreationCercle(Shader *shader, GLDrawType glDrawType, Vecteur2D position, int densiter, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, position, densiter, rayon, filaire);
}