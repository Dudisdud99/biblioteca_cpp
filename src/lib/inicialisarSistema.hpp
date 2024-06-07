#ifndef INICIALIZARSISTEMA_HPP
#define INICIALIZARSISTEMA_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"
#include "livro.hpp"
#include "adm.hpp"
#include "cadastro.hpp"
#include "login.hpp"

void inicio(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
    int opcao;

    std::cout << "\nBem-vindo ao sistema de biblioteca\n";

    while (true) {
        std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            cadastro(usuarios, livros, adms, idUsuario, senhaAdm);
        }
        else if (opcao == 2) {
            login(usuarios, livros, adms, idUsuario, senhaAdm);
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
}
#endif