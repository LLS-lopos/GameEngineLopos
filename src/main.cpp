#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "RenduGraphique/Forme/Forme.h"
#include "core/Fenetre.h"
#include "RenduGraphique/Vecteur/FormeVec2D.h"
#include "RenduGraphique/OperationVecteur/TranformationUtils.h"

int main()
{
    Fenetre *fenetre = new Fenetre(1280, 720, "LOPOS GAME ENGIME"); 

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
                                        "vec2 scaleVertex = vec2(aPos.x * shapeScale.x, aPos.y * shapeScale.y);\n"
                                        "vec2 rotateVertex = vec2(0.0f, 0.0f);\n"
                                        "rotateVertex.x = scaleVertex.x * cos(shapeAngle) - scaleVertex.y * sin(shapeAngle);\n"
                                        "rotateVertex.y = scaleVertex.y * cos(shapeAngle) + scaleVertex.x * sin(shapeAngle);\n"
                                        "vec2 verticeInWorldSpace = vec2(shapePosition.x + rotateVertex.x, shapePosition.y + rotateVertex.y);\n"
                                        "vec2 verticeInCameraSpace = verticeInWorldSpace - cameraPosition;\n"
                                        "vec2 verticeInNDCSpace;\n"
                                        "verticeInNDCSpace.x = verticeInCameraSpace.x*2.0/cameraHorizontalSize;\n"
                                        "verticeInNDCSpace.y = verticeInCameraSpace.y*2.0/cameraVerticalSize;\n"
                                        "gl_Position = vec4(verticeInNDCSpace.x, verticeInNDCSpace.y, aPos.z, 1.0);\n"
                                    "}\n";

    const char *fragmentShaderSource = "#version 330 core\n"
                                        "out vec4 FdfragColor;\n"
                                        "void main()\n"
                                        "{\n"
                                        "	FdfragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f)\n;"
                                        "}\n";
    
    Vecteur2D cameraPos = Vecteur2D(0.0f, 0.0f);
    Camera* cam = new Camera(cameraPos, 10, true);

    Vecteur2D Pos1 = Vecteur2D(-1.5f, 0.5f);
    Vecteur2D Pos2 = Vecteur2D(1.5f, 0.5f);
    
    // identiter
    Vecteur2D F0 = Vecteur2D(-2.0f, 0.0f);
    Vecteur2D val0 = Vecteur2D(0.0f, -1.5f);
    Vecteur2D identiter1 = TranformationUtils::Identiter(val0);
    FormeVec2D* testIdentiter = new FormeVec2D(identiter1, F0, 1.0f, 1.0f, 1.0f, 1.0f);
    // echelle
    Vecteur2D scale0 = TranformationUtils::Echelle(val0, -1.5);
    FormeVec2D* testEchelle = new FormeVec2D(scale0, F0, 1.0f, 0.0f, 1.0f, 1.0f);

    // translation
    Vecteur2D PosT1 = Vecteur2D(0.0f, 0.0f);
    Vecteur2D PosT2 = Vecteur2D(1.5f, 1.5f);
    Vecteur2D PosTval = Vecteur2D(1.0f, 0.0f);
    float temps = 0.0;
    Vecteur2D Tranformation1 = TranformationUtils::Translation(PosT1, Vecteur2D(-2.0f, 0.0f));
    FormeVec2D* test1 = new FormeVec2D(PosT2, PosT1, 1.0f, 0.0f, 0.0f, 1.0f);
    FormeVec2D* test1trans = new FormeVec2D(Tranformation1, PosT1, 0.0f, 1.0f, 0.0f, 1.0f);
    
    //Rotation
    Vecteur2D point1 = Vecteur2D(1.0f, -1.0f);
    Vecteur2D initPoint1 = Vecteur2D(1.0f, 0.0f);
    float angle = 0.0f;
    Vecteur2D rotation1 = TranformationUtils::Rotation(initPoint1, angle);
    FormeVec2D* valR1 = new FormeVec2D(initPoint1, point1, 1.0f, 1.0f, 1.0f, 1.0f);
    FormeVec2D* valR2 = new FormeVec2D(rotation1, point1, 1.0f, 0.50f, 1.0f, 1.0f);
    
    
    Shader *shader = new Shader(pointShaderSource, fragmentShaderSource);

    Transform tr = Transform(cameraPos, Vecteur2D(1.0f, 1.0f), 0.0f);
    Forme *tri = Forme::CreationTriangle(shader, GLDrawType::GL_DRAW_STREAM, tr, 0.4);
    Forme *grille = Forme::CreationGrille(shader, GLDrawType::GL_DRAW_STREAM, tr, 15, 15);
    Forme *poly = Forme::CreationPolygoneRegulier(shader, GLDrawType::GL_DRAW_STREAM, tr, 10, 0.2f);
    Forme *carre = Forme::CreationCarre(shader, GLDrawType::GL_DRAW_STREAM, tr, 0.2);
    Forme *cercle = Forme::CreationCercle(shader, GLDrawType::GL_DRAW_STREAM, tr, 50, 0.4f, false);
    Forme *rectangle = Forme::CreationRectangle(shader, GLDrawType::GL_DRAW_STREAM, tr, 1.8, 0.5);

    while (!glfwWindowShouldClose(fenetre->recupFenetre())) // Boucle principale
    {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Couleur de fond
        glClear(GL_COLOR_BUFFER_BIT);

        float mise_echelle = TranformationUtils::PingPong(temps, 1.0f);
        Tranformation1 = TranformationUtils::Translation(PosT1, PosTval * mise_echelle);
        test1trans->RecupValeur(Tranformation1);

        test1->Draw(cam, fenetre);
        testIdentiter->Draw(cam, fenetre);
        testEchelle->Draw(cam, fenetre);
        test1trans->Draw(cam, fenetre);
        

        float horloge = TranformationUtils::PingPong(temps*300, 360.0f);
        rotation1 = TranformationUtils::Rotation(initPoint1, horloge);
        valR2->RecupValeur(rotation1);
        valR1->Draw(cam, fenetre);
        valR2->Draw(cam, fenetre);
        
        grille->Draw(cam, fenetre);
        tri->DefinirPosition(Vecteur2D(-1.5, 1));
        tri->Draw(cam, fenetre);
        tri->DefinirPosition(Vecteur2D(1.5, 1));
        tri->Draw(cam, fenetre);
        cercle->DefinirPosition(Pos2);
        cercle->Draw(cam, fenetre);
        cercle->DefinirPosition(Pos1);
        cercle->Draw(cam, fenetre);
        rectangle->DefinirPosition(Vecteur2D(0, -1.5));
        rectangle->Draw(cam, fenetre);

        float nez = TranformationUtils::PingPong(temps*10, 2.0f);
        poly->DefinirEchelle(Vecteur2D(nez, nez));
        float angle = TranformationUtils::Repeter(temps*200, 360.0f);
        poly->DefinirRotation(angle);
        poly->DefinirPosition(Vecteur2D(0.0f, -0.15f));
        poly->Draw(cam, fenetre);       

        temps += 0.001f;
        glfwSwapBuffers(fenetre->recupFenetre());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
