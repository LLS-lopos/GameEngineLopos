#include "Forme.h"

Forme *Forme::CreationCarre(Shader *shader, GLDrawType glDrawType, float rayon, bool filaire)
{
    return CreationPolygoneRegulier(shader, glDrawType, 4, rayon, filaire);
}