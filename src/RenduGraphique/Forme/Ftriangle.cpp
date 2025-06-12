#include "Forme.h"

Forme *Forme::CreationTriangle(Shader *shader, GLDrawType glDrawType, Vecteur2D position, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, position, 3, rayon, filaire);
}