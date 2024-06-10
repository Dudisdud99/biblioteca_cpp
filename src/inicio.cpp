#include "lib/inicio.hpp"
#include "lib/cadastro.hpp"
#include "lib/login.hpp"

void Inicio::inicio(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
    int opcao;

    std::cout << "\nBem-vindo ao sistema de biblioteca\n";

    while (true) {
        std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            Cadastro::cadastro(usuarios, livros, adms, idUsuario, senhaAdm);
            Login::login(usuarios, livros, adms, idUsuario, senhaAdm);
        }
        else if (opcao == 2) {
            Login::login(usuarios, livros, adms, idUsuario, senhaAdm);
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
}