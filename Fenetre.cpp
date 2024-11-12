#include "Fenetre.h"

Fenetre::Fenetre(int largeur, int hauteur, const char *titre)
    : m_largeur(largeur), m_hauteur(hauteur), m_titre(titre), m_glMajeurVersion(3), m_glMineureVersion(3)
{
    InitialisationGLFW();
    CreationFenetre();
    InitialisationGLAD();
}
Fenetre::Fenetre(int largeur, int hauteur, const char *titre, int glMajeurVersion, int glMineureVersion)
    : m_largeur(largeur), m_hauteur(hauteur), m_titre(titre), m_glMajeurVersion(glMajeurVersion), m_glMineureVersion(glMineureVersion)
{
    InitialisationGLFW();
    CreationFenetre();
    InitialisationGLAD();
}

int Fenetre::InitialisationGLFW()
{
    // Initialisation de GLFW
    if (!glfwInit())
    {
        std::cerr << "Erreur : GLFW n'a pas pu être initialisé." << std::endl;
        return -1;
    }

    std::cout << "GLFW initialisé avec succès." << std::endl;

    glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, m_glMajeurVersion);
    glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, m_glMineureVersion);
    glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwInitHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    return 1;
}

int Fenetre::InitialisationGLAD()
{
    // Initialisation de OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Erreur lors du chargement de OpenGL" << std::endl;
        glfwTerminate();
        return -1;
    }
    std::cout << "OpenGL chargé avec succès." << std::endl;
    return 1;
}

int Fenetre::CreationFenetre()
{
    // Création de la fenêtre
    m_fenetre = glfwCreateWindow(m_largeur, m_hauteur, m_titre, NULL, NULL);
    if (!m_fenetre)
    {
        std::cout << "Erreur lors de la creation de la fenetre" << std::endl;
        glfwTerminate();
        return -1;
    }
    std::cout << "Fenêtre créée avec succès." << std::endl;
    glfwMakeContextCurrent(m_fenetre); // Créer un contexte OpenGL
    return 1;
}
GLFWwindow *Fenetre::recupFenetre() const
{
    return m_fenetre;
}