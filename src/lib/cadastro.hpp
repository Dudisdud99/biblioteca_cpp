#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"
#include "adm.hpp"

void cadastro(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
    std::string login, senha;
    while (true) {
        std::cout << "\nDigite o nome de usuario: ";
        std::cin >> login;

        bool existeUser = false;

        for (Usuario* usuario : usuarios) {
            if (usuario->getLogin() == login) {
                existeUser = true;
                break;
            }
        }
        if (existeUser == false) {
            for (Adm* adm : adms) {
                if (adm->getLogin() == login) {
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
        std::cout << "\nDigite a senha: ";
        std::cin >> senha;

        if (senha == senhaAdm) {
            std::cout << "\nSenha invalida\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Voce esta cadastrando um administrador ou usuario (1 - Admin, 2 - Usuario)";
        int opcao;
		std::cin >> opcao;
		if(opcao == 1){
            std::string codigo;
            std::cout << "Digite o codigo de verificacao: ";
            std::cin >> codigo;
			Adm* adm = new Adm(login, senha, idUsuario);
			adms.push_back(adm);
			std::cout << "\nAdministrador adicionado: \n";
			break;
		}
		else if(opcao == 2){
			Usuario* usuario = new Usuario(login, senha, idUsuario);
			usuarios.push_back(usuario);
			std::cout << "\nUsuario adicionado: \n";
			break;
		}
        else {
            std::cout << "\nOpcao invalida\n";
        }
}

//bool cadastroAdm(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
//    std::string login, senha;
//    while (true) {
//        std::cout << "\nDigite o nome de usuario: ";
//        std::cin >> login;
//
//        bool existeUser = false;
//
//        for (Usuario* usuario : usuarios) {
//            if (usuario->getLogin() == login) {
//                existeUser = true;
//                break;
//            }
//        }
//
//        if (existeUser == false) {
//            for (Adm* adm : adms) {
//                if (adm->getLogin() == login) {
//                    existeUser = true;
//                    break;
//                }
//            }
//        }
//        if (existeUser) {
//            std::cout << "\nUsuario ja existe\n";
//        }
//        else {
//            break;
//        }
//    }
//
//    int invalida = 0;
//    bool boa = true;
//
//    while (invalida < 5) {
//        std::cout << "Digite a senha: ";
//        std::cin >> senha;
//
//
//        if (senha == senhaAdm) {
//            break;
//        }
//        else {
//            std::cout << "\nSenha invalida\n";
//            invalida += 1;
//        }
//        if (invalida == 5) {
//            std::cout << "\nNamero maximo de tentativas excedido\n";
//            boa = false;
//            return boa;
//        }
//    }
//
//    Adm* adm = new Adm(login, senha, idUsuario);
//    adms.push_back(adm);
//    std::cout << "\nAdministrador adicionado: \n";
//
//    idUsuario += 1;
//
//    return boa;
//}

//void cadastro(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
//    char opcao;
//
//    bool boa;
//    while (true) {
//        std::cout << "\nVc deseja cadastrar um usuario ou um administrador? (u/a): ";
//        std::cin >> opcao;
//
//        if (opcao == 'u') {
//            cadastroUsuario(usuarios, adms, idUsuario, senhaAdm);
//            break;
//        }
//        else if (opcao == 'a') {
//            boa = cadastroAdm(usuarios, adms, idUsuario, senhaAdm);
//            if (boa) {
//                break;
//            }
//        }
//        else {
//            std::cout << "\nOpção invalida\n";
//        }
//    }
//}
#endif