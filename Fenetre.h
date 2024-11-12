#ifndef _FENETRE_H_
#define _FENETRE_H_
// #include "Libs/include/glad/glad.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class Fenetre
{
public:
    Fenetre(int largeur, int hauteur, const char *titre);
    Fenetre(int largeur, int hauteur, const char *titre, int glMajeurVersion, int glMineureVersion);
    GLFWwindow *recupFenetre() const;

private:
    int m_glMajeurVersion = 3;
    int m_glMineureVersion = 3;
    int m_largeur = 800;
    int m_hauteur = 800;
    const char *m_titre = new char[] {"Projet LOPOS @LPS"};

    GLFWwindow *m_fenetre;
    int InitialisationGLFW();
    int InitialisationGLAD();
    int CreationFenetre();
};

#endif // _FENETRE_H_