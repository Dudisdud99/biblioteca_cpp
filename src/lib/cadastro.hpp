#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <vector>
#include <iostream>
#include <string>

class Usuario;
class Livro;
class Adm;

namespace Cadastro {
	void cadastro(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm);
}

#endif