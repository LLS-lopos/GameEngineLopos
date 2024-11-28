#include "Forme.h"

Forme *Forme::CreationGrille(Shader *shader, GLDrawType glDrawType, int n_carre_l, int n_carre_h, bool filaire)
{
    int n_point = ((n_carre_l + 1) + (n_carre_h + 1)) * 2 * 3;
    float *point = new float[n_point];

    int n_indice = ((n_carre_l + 1) + (n_carre_h + 1)) * 2;
    unsigned int *indice = new unsigned int[n_indice];

    float tailleX = 2.0f / n_carre_l;
    for (int x = 0; x < (n_carre_l + 1); x++)
    {
        int index = x * 2;
        point[index * 3] = - 1.0f;
        point[index * 3 + 1] = - 1.0f + x * tailleX;
        point[index * 3 + 2] = 0.0f;

        point[(index + 1) * 3] = 1.0f ;
        point[(index + 1) * 3 + 1] = -1.0f + x * tailleX;
        point[(index + 1) * 3 + 2] = 0.0f;

        indice[index] = index;
        indice[index + 1] = index + 1;
    }
    float tailleY = 2.0f / n_carre_h;
    for (int y = 0; y < (n_carre_h + 1); y++)
    {
        int index = (n_carre_l + 1) * 2.0f + y * 2.0f;
        point[index * 3] = - 1.0f + y * tailleY;
        point[index * 3 + 1] = 1.0f;
        point[index * 3 + 2] = 0.0f;

        point[(index + 1) * 3] = -1.0f + y * tailleY;
        point[(index + 1) * 3 + 1] = -1.0f;
        point[(index + 1) * 3 + 2] = 0.0f;

        indice[index] = index;
        indice[index + 1] = index + 1;
    }
    Forme *grille = new Forme(shader, glDrawType, n_point * sizeof(float), point, n_indice * sizeof(int), indice, FormeType::LIGNE, filaire);
    return grille;
}