#include "Forme.h"
#include <cmath>

Forme *Forme::CreationPolygoneRegulier(Shader *shader, GLDrawType glDrawType, int nombre_poly, float rayon, bool filaire)
{
    int n_point = nombre_poly * 3;
    int nombreIndice = (nombre_poly - 2) * 3;
    float *point = new float[n_point];
    unsigned int *indice = new unsigned int[nombreIndice];

    bool siPaire = (nombre_poly % 2) == 0;
    float angle = 0;
    if (siPaire)
        angle = M_PI / 2.0f + 2.0f * M_PI / nombre_poly / 2.0f;
    else
        angle = M_PI / 2.0f;
    
    // Initialisé les points
    for (int i = 0; i < nombre_poly; i++)
    {
        float x = cos(angle) * rayon;
        float y = sin(angle) * rayon;

        angle -= 2.0f * M_PI / nombre_poly;

        point[i * 3] = x;
        point[i * 3 + 1] = y;
        point[i * 3 + 2] = 0.0f;
    }
    // Initialisé les indices
    for (int triangleID = 0; triangleID < nombre_poly - 2; triangleID++)
    {
        indice[triangleID * 3] = 0.0f;
        indice[triangleID * 3 + 1] = triangleID + 1;
        indice[triangleID * 3 + 2] = triangleID + 2;
    }
    Forme *polygone = new Forme(shader, glDrawType, n_point * sizeof(float), point, nombreIndice * sizeof(int), indice, FormeType::TRIANGLE, filaire);
    return polygone;    
}