#ifndef _FENETRE_H_
#define _FENETRE_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Fenetre
{
public:
    Fenetre(int largeur, int hauteur, char *titre);
    ~Fenetre();
    Fenetre(int largeur, int hauteur, char *titre, int glMajeurVersion, int glMineureVersion);
    GLFWwindow *recupFenetre() const;
    float ObtenirLargeur()const;
    float ObtenirHauteur()const;
    void RafraichirLH();

    static void DefinirTailleFrameBuffer(GLFWwindow* fenetre, int largeur, int hauteur);
private:
    int m_glMajeurVersion = 3;
    int m_glMineureVersion = 3;

    int m_largeur = 1280;
    int m_hauteur = 720;
    char *m_titre;

    GLFWwindow *m_fenetre;
    int InitialisationGLFW();
    int InitialisationGLAD();
    int CreationFenetre();
    //int FermerFenetre();
};

#endif // _FENETRE_H_