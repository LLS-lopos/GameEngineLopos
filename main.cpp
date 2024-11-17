#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Fenetre.h"
#include "Forme.h"

int main()
{
    Fenetre *fenetre = new Fenetre(800, 800, new char[]{"LOPOS ENGIME"});

    const char *pointShaderSource = "#version 330 core\n"
                                     "layout(location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\n";

    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FdfragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FdfragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
                                       "}\n";

    Shader *shader = new Shader(pointShaderSource, fragmentShaderSource);
    Forme *tri = Forme::CreationTriangle(shader, GLDrawType::GL_DRAW_STREAM, 0.5);
    Forme *forme = Forme::CreationRectangle(shader, GLDrawType::GL_DRAW_STREAM, 1.0f, 0.5f);
    Forme *poly = Forme::CreationPolygoneRegulier(shader, GLDrawType::GL_DRAW_STREAM, 50, 0.4f);
    Forme *cercle = Forme::CreationCercle(shader, GLDrawType::GL_DRAW_STREAM, 20, 0.4f);
    Forme *carre = Forme::CreationCarre(shader, GLDrawType::GL_DRAW_STREAM, 0.1);
    Forme *grille = Forme::CreationGrille(shader, GLDrawType::GL_DRAW_STREAM, 15, 15);

    while (!glfwWindowShouldClose(fenetre->recupFenetre())) // Boucle principale
    {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Couleur de fond
        glClear(GL_COLOR_BUFFER_BIT);

        grille->Draw();
        cercle->Draw();

        glfwPollEvents();
        glfwSwapBuffers(fenetre->recupFenetre());
    }
    glfwTerminate();
    return 0;
}
