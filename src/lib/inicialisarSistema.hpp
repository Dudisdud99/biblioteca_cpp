#ifndef INICIALIZARSISTEMA_HPP
#define INICIALIZARSISTEMA_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"
#include "adm.hpp"
#include "cadastro.hpp"
#include "login.hpp"

void inicio(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
    int opcao;

    std::cout << "\nBem-vindo ao sistema de biblioteca\n";

    do {
        std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            cadastro(usuarios, adms, idUsuario, senhaAdm);
        }
        else if (opcao == 2) {
            login(usuarios, livros, adms, idUsuario, senhaAdm);
        }
        else if (opcao == 0) {
            return;
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    } while (opcao != 0);
}
#endif