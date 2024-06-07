#include <iostream>
#include <string>
#include <vector>
#include "lib/usuario.hpp"
#include "lib/adm.hpp"
#include "lib/livro.hpp"
#include "lib/cadastro.hpp"
#include "lib/login.hpp"
#include "lib/inicio.hpp"

//inicializacao de testes

void iniciarMultas(std::vector<Usuario*>& usuarios) {
    for (Usuario* usuario : usuarios) {
        //usuario->calcMulta();
    }
}

//void inicializarLivros(std::vector<Livro*>& livros) {
//    for (int i = 0; i < 10; i++) {
//        Livro* livro = new Livro();
//        livro->setTitulo("Livro " + std::to_string(i + 1));
//        livro->setAutor("Autor " + std::to_string(i + 1));
//        livro->setAno(2000 + i + 1);
//        livro->setGenero("Genero " + std::to_string(i + 1));
//        livro->setId(i);
//        livros.push_back(livro);
//    }
//}

int main() {
    std::vector<Usuario*> usuarios;
    std::vector<Livro*> livros;
    std::vector<Adm*> adms;

    std::string senhaAdm = "admin";

    int idUsuario = 0;

    //inicializarLivros(livros);
    //iniciarMultas(usuarios);
    inicio(usuarios, livros, adms, idUsuario, senhaAdm);

    for (auto it = usuarios.begin(); it != usuarios.end(); ) {
        delete* it;
        *it = nullptr;
        it = usuarios.erase(it);
    }
    usuarios.clear();

    for (auto it = livros.begin(); it != livros.end(); ) {
        delete* it;
        *it = nullptr;
        it = livros.erase(it);
    }
    livros.clear();

    for (auto it = adms.begin(); it != adms.end(); ) {
        delete* it;
        *it = nullptr;
        it = adms.erase(it);
    }
    adms.clear();

    return 0;
}