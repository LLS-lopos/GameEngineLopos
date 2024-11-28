#include "Forme.h"

Forme *Forme::CreationRectangle(Shader *shader, GLDrawType glDrawType, float largeur, float hauteur, bool filaire)
{
    float point[12] = {-largeur / 2.0f, -hauteur / 2.0f, 0.0f, // bas-gauche
                       largeur / 2.0f, -hauteur / 2.0f, 0.0f,  // bas-droit
                       largeur / 2.0f, hauteur / 2.0f, 0.0f,   // haut-droit
                       -largeur / 2.0f, hauteur / 2.0f, 0.0f}; // haut-gauche
    unsigned int indice[6] = {0, 2, 1, 0, 3, 2};
    Forme *rectangle = new Forme(shader, glDrawType, sizeof(point), point, sizeof(indice), indice, FormeType::TRIANGLE, filaire);
    return rectangle;
}