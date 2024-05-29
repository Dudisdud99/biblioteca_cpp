#ifndef LOGIN_HPP
#define LOGIN_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"
#include "adm.hpp"

void login(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
    std::string login, senha;

    while (true) {
        std::cout << "\nDigite o nome de usuario: ";
        std::cin >> login;

        std::cout << "Digite a senha: ";
        std::cin >> senha;

        bool found = false;

        if (senha == senhaAdm) {
            for (Adm* adm : adms) {
                if (adm->getLogin() == login) {
                    std::cout << "\nAdiminstrador logado\n";
                    adm->opcoesUsuario(livros, usuarios, adms, idUsuario, senhaAdm);
                    found = true;
                    break;
                }
            }
        }
        else {
            for (Usuario* usuario : usuarios) {
                if (usuario->getLogin() == login && usuario->getSenha() == senha) {
                    std::cout << "\nUsuario logado\n";
                    usuario->opcoesUsuario(livros);
                    found = true;
                    break;
                }
            }
        }

        if (found == false) {
            std::cout << "\nUsuario ou senha invalidos\n";
        }
        else {
            break;
        }
    }
}
#endif