#ifndef _SYSTEM_FICHIER_H_
#define _SYSTEM_FICHIER_H_
#include <fstream>
#include <sstream>
#include <string>


class SystemFichier
{
public:
	static std::string recup_contenu_fichier(const std::string& nomfichier);
};

#endif