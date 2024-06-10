#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <vector>
#include <iostream>

class Usuario;
class Livro;
class Adm;

namespace Login {
	void login(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm);
}

#endif