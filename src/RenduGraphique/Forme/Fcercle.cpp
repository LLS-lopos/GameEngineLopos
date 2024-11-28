#include "Forme.h"

Forme *Forme::CreationCercle(Shader *shader, GLDrawType glDrawType, int densiter, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, densiter, rayon, filaire);
}