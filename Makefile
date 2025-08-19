# Variables
Compilateur = g++
Librairies = -I./Libs/ -I./Libs/include/ -I/usr/include/GL
LIBS = -lGL -lGLU -lglut -lglfw -lm
EXsource = Libs/src/glad.c
Source = src/main.cpp src/core/Fenetre.cpp src/RenduGraphique/Forme/Forme.cpp src/RenduGraphique/Shader/Shader.cpp src/RenduGraphique/Forme/Fcarre.cpp src/RenduGraphique/Forme/Fcercle.cpp src/RenduGraphique/Forme/Fgrille.cpp src/RenduGraphique/Forme/FpolygoneRegulier.cpp src/RenduGraphique/Forme/Frectangle.cpp src/RenduGraphique/Forme/Ftriangle.cpp src/RenduGraphique/Vecteur/Vecteur2D.cpp src/RenduGraphique/Vecteur/FormeVec2D.cpp src/core/Camera.cpp src/RenduGraphique/OperationVecteur/TranformationUtils.cpp src/RenduGraphique/Vecteur/Transform.cpp src/RenduGraphique/Matrice/Matrice_2x2.cpp src/RenduGraphique/Matrice/Matrice_3x3.cpp src/utilitaire/SysFichier.cpp

# Ajout du chemin moteur/ pour les fichiers objets
Objets = $(patsubst src/%.cpp, moteur/%.o, $(Source)) $(patsubst Libs/src/%.c, moteur/%.o, $(EXsource))  # Ajoute glad.o
Sortie = moteur/main

# Règles
.PHONY: all clean run

# Règle par défaut pour construire l'exécutable
all: create_dirs $(Sortie)

# Règle pour créer les répertoires nécessaires
create_dirs:
	mkdir -p moteur/core 
	mkdir -p moteur/RenduGraphique/Forme 
	mkdir -p moteur/RenduGraphique/Matrice
	mkdir -p moteur/RenduGraphique/OperationVecteur
	mkdir -p moteur/RenduGraphique/Shader 
	mkdir -p moteur/RenduGraphique/Vecteur
	mkdir -p moteur/utilitaire
	# Créer le répertoire assets et copier son contenu
	mkdir -p moteur/assets
	if [ -d "src/assets" ]; then \
		rsync -a --delete src/assets/ moteur/assets/; \
	fi

# Règle pour créer l'exécutable à partir des fichiers objets
$(Sortie): $(Objets)
	$(Compilateur) $(Objets) -o $(Sortie) $(Librairies) $(LIBS)

# Règle pour compiler les fichiers .cpp en fichiers .o dans le répertoire moteur
moteur/%.o: src/%.cpp
	$(Compilateur) -c $< -o $@ $(Librairies)

# Règle pour compiler glad.c en glad.o dans le répertoire moteur
moteur/glad.o: $(EXsource)
	$(Compilateur) -c $(EXsource) -o moteur/glad.o $(Librairies)

# Règle de nettoyage
clean:
	rm -f $(Sortie) $(Objets)  # Supprime l'exécutable et les fichiers objets

# Règle pour exécuter le programme
run: $(Sortie)
	./${Sortie}