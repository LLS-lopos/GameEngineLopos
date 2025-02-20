#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "RenduGraphique/Forme/Forme.h"
#include "core/Fenetre.h"

int main()
{
    Fenetre *fenetre = new Fenetre(800, 800, "LOPOS GAME ENGIME"); 

    const char *pointShaderSource = "#version 330 core\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "uniform vec2 shapePosition;\n"
                                    //"uniform vec2 cameraPosition;\n"
                                    //"uniform float cameraVerticalSize;\n"
                                    //"uniform float cameraHorizontalSize;\n"		
                                    "void main()\n"
                                    "{\n"
                                        "vec2 localToWorldSpace = vec2(shapePosition.x + aPos.x, shapePosition.y + aPos.y);\n"
                                        "gl_Position = vec4(localToWorldSpace.x, localToWorldSpace.y, aPos.z, 1.0);\n"
                                    "}\n";

    const char *fragmentShaderSource = "#version 330 core\n"
                                        "out vec4 FdfragColor;\n"
                                        "void main()\n"
                                        "{\n"
                                        "	FdfragColor = vec4(0.8f, 0.8f, 0.8f, 1.0f)\n;"
                                        "}\n";    
    
    Vecteur2D cameraPos = Vecteur2D(0.0f, 0.0f);
    Vecteur2D Pos1 = Vecteur2D(0.5f, 0.0f);
    Vecteur2D Pos2 = Vecteur2D(-0.5f, -0.0f);

    Camera* cam = new Camera(cameraPos, 10, true);
    Shader *shader = new Shader(pointShaderSource, fragmentShaderSource);

    //Forme *tri = Forme::CreationTriangle(shader, GLDrawType::GL_DRAW_STREAM, cameraPos, 0.5);
    //Forme *poly = Forme::CreationPolygoneRegulier(shader, GLDrawType::GL_DRAW_STREAM, cameraPos, 10, 0.4f);
    //Forme *carre = Forme::CreationCarre(shader, GLDrawType::GL_DRAW_STREAM, cameraPos, 0.2);
    Forme *cercle = Forme::CreationCercle(shader, GLDrawType::GL_DRAW_STREAM, cameraPos, 50, 0.4f);
    Forme *grille = Forme::CreationGrille(shader, GLDrawType::GL_DRAW_STREAM, cameraPos, 15, 15);
    //Forme *rectangle = Forme::CreationRectangle(shader, GLDrawType::GL_DRAW_STREAM, cameraPos, 0.8, 0.3);

    while (!glfwWindowShouldClose(fenetre->recupFenetre())) // Boucle principale
    {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Couleur de fond
        glClear(GL_COLOR_BUFFER_BIT);
        cercle->DefinirPosition(Pos2);
        cercle->Draw(cam, fenetre);
        cercle->DefinirPosition(Pos1);
        cercle->Draw(cam, fenetre);
        grille->Draw(cam, fenetre);

        glfwSwapBuffers(fenetre->recupFenetre());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
