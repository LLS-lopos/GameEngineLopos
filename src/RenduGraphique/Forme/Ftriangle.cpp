#include "Forme.h"

Forme *Forme::CreationTriangle(Shader *shader, GLDrawType glDrawType, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, 3, rayon, filaire);
}