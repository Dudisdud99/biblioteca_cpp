#ifndef INICIO_HPP
#define INICIO_HPP

#include <vector>
#include <iostream>
#include <string>

class Usuario;
class Livro;
class Adm;

namespace Inicio {
	void inicio(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm);
}

#endif