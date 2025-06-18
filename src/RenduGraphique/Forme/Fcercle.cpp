#include "Forme.h"

Forme *Forme::CreationCercle(Shader *shader, GLDrawType glDrawType, Transform transform, int densiter, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, transform, densiter, rayon, filaire);
}