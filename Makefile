# Variables
Compilateur = g++
Librairies = -I./Libs/ -I./Libs/include/ -I/usr/include/GL
LIBS = -lGL -lGLU -lglut -lglfw -lm
EXsource = Libs/src/glad.c
Source = src/main.cpp src/core/Fenetre.cpp src/core/Forme/Forme.cpp src/core/Shader/Shader.cpp src/core/Forme/Fcarre.cpp src/core/Forme/Fcercle.cpp src/core/Forme/Fgrille.cpp src/core/Forme/FpolygoneRegulier.cpp src/core/Forme/Frectangle.cpp src/core/Forme/Ftriangle.cpp src/math/Vecteur/Vecteur2D.cpp src/math/Vecteur/FormeVec2D.cpp src/core/Camera.cpp src/math/OperationVecteur/TranformationUtils.cpp src/core/Transformation/Transform.cpp src/math/Matrice/Matrice_2x2.cpp src/math/Matrice/Matrice_3x3.cpp src/utilitaire/SysFichier.cpp 

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
	mkdir -p moteur/core/Forme 
	mkdir -p moteur/core/Transformation
	mkdir -p moteur/math/Matrice
	mkdir -p moteur/math/OperationVecteur
	mkdir -p moteur/core/Shader 
	mkdir -p moteur/math/Vecteur
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