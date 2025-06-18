#include "Forme.h"

Forme *Forme::CreationTriangle(Shader *shader, GLDrawType glDrawType, Transform transform, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, transform, 3, rayon, filaire);
}