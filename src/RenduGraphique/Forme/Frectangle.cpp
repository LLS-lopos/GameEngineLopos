#include "Forme.h"

Forme *Forme::CreationRectangle(Shader *shader, GLDrawType glDrawType, Vecteur2D position, float largeur, float hauteur, bool filaire)
{
    Vecteur2D* point = new Vecteur2D[] 
    {
        Vecteur2D(-largeur / 2.0f, -hauteur / 2.0f), // bas-gauche
        Vecteur2D(largeur / 2.0f, -hauteur / 2.0f),  // bas-droit
        Vecteur2D(largeur / 2.0f, hauteur / 2.0f),   // haut-droit
        Vecteur2D(-largeur / 2.0f, hauteur / 2.0f)   // haut-gauche
        }; 
    unsigned int* indice = new unsigned int[]
    {
        0, 2, 1,
        0, 3, 2
        };
    Forme *rectangle = new Forme(shader, glDrawType, position, 4, point, 6, indice, FormeType::TRIANGLE, filaire);
    return rectangle;
}