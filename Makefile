# Variables
Compilateur = g++
Librairies = -I./Libs/ -I./Libs/include/ -I/usr/include/GL
LIBS = -lGL -lGLU -lglut -lglfw -lm
EXsource = Libs/src/glad.c
Source = src/main.cpp src/core/Fenetre.cpp src/RenduGraphique/Forme.cpp src/RenduGraphique/Shader.cpp
Objets = $(Source:.cpp=.o) $(EXsource:.c=.o)  # Ajoute glad.o
Sortie = main

# Règles
.PHONY: all clean

# Règle par défaut pour construire l'exécutable
all: $(Sortie)

# Règle pour créer l'exécutable à partir des fichiers objets
$(Sortie): $(Objets)
	$(Compilateur) $(Objets) -o $(Sortie) $(Librairies) $(LIBS)

# Règle pour compiler les fichiers .cpp en fichiers .o
%.o: %.cpp
	$(Compilateur) -c $< -o $@ $(Librairies)

# Règle pour compiler glad.c en glad.o
Libs/src/glad.o: $(EXsource)
	$(Compilateur) -c $(EXsource) -o Libs/src/glad.o $(Librairies)

# Règle de nettoyage
clean:
	rm -f $(Sortie) $(Objets)  # Supprime l'exécutable et les fichiers objets