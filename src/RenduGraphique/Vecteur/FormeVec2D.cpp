#include "FormeVec2D.h"

FormeVec2D::FormeVec2D(Vecteur2D vecteur, Vecteur2D position, float r, float g, float b, float a)
{
    const char *pointShaderSource = "#version 330 core\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "uniform vec2 shapePosition;\n"
                                    "uniform vec2 shapeScale;\n"
                                    "uniform float shapeAngle;\n"
                                    "uniform vec2 cameraPosition;\n"
                                    "uniform float cameraVerticalSize;\n"
                                    "uniform float cameraHorizontalSize;\n"		
                                    "void main()\n"
                                    "{\n"
                                        "vec2 verticeInWorldSpace = vec2(shapePosition.x + aPos.x, shapePosition.y + aPos.y);\n"
                                        "vec2 verticeInCameraSpace = verticeInWorldSpace - cameraPosition;\n"
                                        "vec2 verticeInNDCSpace;\n"
                                        "verticeInNDCSpace.x = verticeInCameraSpace.x*2.0/cameraHorizontalSize;\n"
                                        "verticeInNDCSpace.y = verticeInCameraSpace.y*2.0/cameraVerticalSize;\n"
                                        "gl_Position = vec4(verticeInNDCSpace.x, verticeInNDCSpace.y, aPos.z, 1.0);\n"
                                    "}\n";

    const char *fragmentShaderSource = "#version 330 core\n"
                                        "out vec4 FdfragColor;\n"
                                        "uniform vec4 couleur;\n"
                                        "void main()\n"
                                        "{\n"
                                        "\tFdfragColor = vec4(couleur.r, couleur.g, couleur.b, couleur.a);\n"
                                        "}\n";
    
    Vecteur2D* point = new Vecteur2D[]{Vecteur2D(0,0),vecteur};
    unsigned int* indice = new unsigned int[]{0, 1};
    m_shader = new Shader(pointShaderSource, fragmentShaderSource);
    m_shader->DefinirUniformVecteur4D("couleur", r, g, b, a);
    Transform transform = Transform(position, Vecteur2D(1.0f, 1.0f), 0.0f);
    m_forme = new Forme(m_shader, GLDrawType::GL_DRAW_DYNAMIC, transform, 2, point, 2, indice, FormeType::LIGNE);
    RecupValeur(vecteur);
}
FormeVec2D::~FormeVec2D()
{
    delete m_forme;
    m_forme = nullptr;
    delete m_shader;
    m_shader = nullptr;
}

void FormeVec2D::RecupValeur(Vecteur2D vecteur)
{
    valeur = vecteur;
    m_forme->RecupPoint(1, vecteur);
}

void FormeVec2D::RecupPosition(Vecteur2D position)
{
    m_forme->DefinirPosition(position);
}

void FormeVec2D::Draw(Camera* camera, Fenetre* fenetre)
{
    m_forme->Draw(camera, fenetre);
}