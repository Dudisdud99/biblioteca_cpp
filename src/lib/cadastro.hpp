#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"
#include "adm.hpp"
#include "livro.hpp"
#include "login.hpp"

void cadastro(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
    std::string nomeUsuario, senha;
    while (true) {
        std::cout << "\nDigite o nome de usuario: ";
        std::cin >> nomeUsuario;

        bool existeUser = false;

        for (Usuario* usuario : usuarios) {
            if (usuario->getLogin() == nomeUsuario) {
                existeUser = true;
                break;
            }
        }
        if (existeUser == false) {
            for (Adm* adm : adms) {
                if (adm->getLogin() == nomeUsuario) {
                    existeUser = true;
                    break;
                }
            }   
        }
        if (existeUser) {
            std::cout << "\nUsuario ja existe\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        if (senha == senhaAdm) {
            std::cout << "\nSenha invalida\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "\nVoce esta cadastrando um administrador ou usuario (1 - Admin, 2 - Usuario): ";
        int opcao;
		std::cin >> opcao;
		if(opcao == 1){
            bool existeAdm = false;

            for (int i=0; i < 5; i += 1) {
                std::string codigo;
                std::cout << "Digite o codigo de verificacao: ";
                std::cin >> codigo;
                if (codigo == senhaAdm){
                    int tipo = 1;
                    Adm* adm = new Adm(nomeUsuario, senha, idUsuario, tipo);
                    adms.push_back(adm);
                    std::cout << "\nAdministrador cadastrado com sucesso!!!\n";
                    existeAdm = true;
                    break;
                }
				else {
					std::cout << "\nCodigo invalido\n";
				}
            }
            if (existeAdm) {
                break;
            }
            else {
                opcao = 2;
            }

		}
		else if(opcao == 2){
            int tipo = 2;
			Usuario* usuario = new Usuario(nomeUsuario, senha, idUsuario, tipo);
			usuarios.push_back(usuario);
			std::cout << "\nUsuario cadastrado com sucesso!!!\n";
			break;
		}
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
	idUsuario += 1;

    login(usuarios, livros, adms, idUsuario, senhaAdm);
}
#endif