#include "SysFichier.h"

std::string SystemFichier::recup_contenu_fichier(const std::string& nomfichier)
{
    std::ifstream in(nomfichier, std::ios::in | std::ios::binary);
    if (in)
    {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        return(contents.str());
    }
    else
    {
        throw(errno);
    }
}

