#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Fenetre.h"
#include "Forme.h"

int main()
{
    Fenetre *fenetre = new Fenetre(1000, 800, new char[]{"LOPOS ENGIME"});

    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout(location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\n";

    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FdfragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FdfragColor = vec4(0.0f, 0.65f, 0.0f, 1.0f);\n"
                                       "}\n";

    Shader *shader = new Shader(vertexShaderSource, fragmentShaderSource);
    Forme *tri = Forme::CreationTriangle(shader, GLDrawType::GL_DRAW_STREAM, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f);
    Forme *forme = Forme::CreationRectangle(shader, GLDrawType::GL_DRAW_STREAM, 1.0f, 0.5f);

    while (!glfwWindowShouldClose(fenetre->recupFenetre())) // Boucle principale
    {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Couleur de fond
        glClear(GL_COLOR_BUFFER_BIT);

        forme->Draw();
        tri->Draw();

        glfwPollEvents();
        glfwSwapBuffers(fenetre->recupFenetre());
    }
    glfwTerminate();
    return 0;
}
