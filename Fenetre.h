#ifndef _FENETRE_H_
#define _FENETRE_H_
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
    int m_glMajeurVersion;
    int m_glMineureVersion;
    int m_largeur;
    int m_hauteur;
    const char *m_titre = new char[]{""};

    GLFWwindow *m_fenetre;
    int InitialisationGLFW();
    int InitialisationGLAD();
    int CreationFenetre();
    int FermerFenetre();
    // void Redimensionner(GLFWwindow *m_fenetre, int m_largeur, int m_hauteur);
};

#endif // _FENETRE_H_