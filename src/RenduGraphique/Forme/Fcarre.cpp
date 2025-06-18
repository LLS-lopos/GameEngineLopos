#include "Forme.h"

Forme *Forme::CreationCarre(Shader *shader, GLDrawType glDrawType, Transform transform, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, transform, 4, rayon, filaire);
}