#include "Forme.h"

Forme *Forme::CreationGrille(Shader *shader, GLDrawType glDrawType, int n_carre_l, int n_carre_h, bool filaire)
{
    int n_point = ((n_carre_l + 1) + (n_carre_h + 1)) * 2;
    Vecteur2D* point = new Vecteur2D[n_point];

    int n_indice = ((n_carre_l + 1) + (n_carre_h + 1)) * 2;
    unsigned int* indice = new unsigned int[n_indice];

    float tailleX = 2.0f / n_carre_l;
    for (int x = 0; x < (n_carre_l + 1); x++)
    {
        int index = x * 2;
        point[index].m_x = -1.0f + x * tailleX;
        point[index].m_y = -1.0f;

        point[(index + 1)].m_x = -1.0f + x * tailleX;
        point[(index + 1)].m_y = 1.0f;

        indice[index] = index;
        indice[index+1] = index+1;
    }
    float tailleY = 2.0f / n_carre_h;
    for (int y = 0; y < (n_carre_h + 1); y++)
    {
        int index = (n_carre_l + 1) * 2.0f + y * 2.0f;
        point[index].m_x = -1.0f;
        point[index].m_y = -1.0f + y * tailleY;

        point[(index + 1)].m_x = 1.0f;
        point[(index + 1)].m_y = -1.0f + y * tailleY;

        indice[index] = index;
        indice[index + 1] = index + 1;
    }
    Forme* grille = new Forme(shader, glDrawType, n_point, point, n_indice, indice, FormeType::LIGNE, filaire);
    return grille;
}