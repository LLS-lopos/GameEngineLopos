#ifndef _FORME_H_
#define _FORME_H_
#include "../Shader/Shader.h"
#include "../Vecteur/Vecteur2D.h"
#include <iostream>

enum class GLDrawType
{
    GL_DRAW_STREAM = 0x88E0,
    GL_DRAW_STATIC = 0x88E4,
    GL_DRAW_DYNAMIC = 0x88E8
};
enum class FormeType
{
    POINT = 0x0000,
    LIGNE = 0x0001,
    LIGNE_LOOP = 0x0002,
    LIGNE_STRIP = 0x0003,
    TRIANGLE = 0x0004,
    TRIANGLE_STRIP = 0x0005,
    TRIANGLE_FAN = 0x0006,
};
class Forme
{
public:
    Forme(Shader *shader, GLDrawType glDrawType, int pointTaille, Vecteur2D* point, int indiceTaille, unsigned int* indice, FormeType formeType = FormeType::TRIANGLE, bool filaire = false);
    ~Forme();
    static Forme *CreationRectangle(Shader *shader, GLDrawType glDrawType, float largeur, float hauteur, bool filaire = false);
    static Forme *CreationPolygoneRegulier(Shader *shader, GLDrawType glDrawType, int nombre_poly, float rayon, bool filaire = false);
    static Forme *CreationCercle(Shader *shader, GLDrawType glDrawType, int densiter, float rayon, bool filaire = false);
    static Forme *CreationCarre(Shader *shader, GLDrawType glDrawType, float rayon, bool filaire = false);
    static Forme *CreationTriangle(Shader *shader, GLDrawType glDrawType, float rayon, bool filaire = false);
    static Forme *CreationGrille(Shader *shader, GLDrawType glDrawType, int n_carre_l, int n_carre_h, bool filaire = false);
    void Draw();

private:
    GLuint m_vbo;
    GLuint m_vao;
    GLuint m_ebo;
    FormeType m_formeType;
    GLDrawType m_glDrawType;
    Shader *m_shader;

    Vecteur2D* m_point = nullptr;
    unsigned int* m_indice = nullptr;
    int m_pointTaille;
    int m_indiceTaille;

    bool m_filaire = false;
    int n_typeForme = 1;
    void ConfigureVBO(int pointTaille, Vecteur2D* point);
    void ConfigureEBO(int indiceTaille, unsigned int indice[]);
};
#endif // _FORME_H_