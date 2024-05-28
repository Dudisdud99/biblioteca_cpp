#include <iostream>
#include <string>
#include <vector>
#include "lib/usuario.hpp"
#include "lib/adm.hpp"
#include "lib/livro.hpp"

// inicio de sessão


void cadastroUsuario(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
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

        if(existeUser == false){
            for (Adm* adm : adms) {
                if (adm->getLogin() == login) {
                    existeUser = true;
                    break;
                }
            }
        }
        if(existeUser){
            std::cout << "\nUsuario ja existe\n";
        }
        else{
            break;
        }
    }


    while(true){
        std::cout << "\nDigite a senha: ";
        std::cin >> senha;

        if(senha == senhaAdm){
            std::cout << "\nSenha invalida\n";
        }
        else{
            break;
        }
    }

    Usuario* usuario = new Usuario(login, senha, idUsuario);
    usuarios.push_back(usuario);
    std::cout << "\nUsuario adicionado: \n";

    idUsuario+=1;
}

bool cadastroAdm(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
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

        if(existeUser == false){
            for (Adm* adm : adms) {
                if (adm->getLogin() == login) {
                    existeUser = true;
                    break;
                }
            }
        }
        if(existeUser){
            std::cout << "\nUsuario ja existe\n";
        }
        else{
            break;
        }
    }

    int invalida = 0;
    bool boa = true;

    while(invalida<5){
        std::cout << "Digite a senha: ";
        std::cin >> senha;


        if(senha == senhaAdm){
            break;
        }
        else{
            std::cout << "\nSenha invalida\n";
            invalida+=1;
        }
        if(invalida == 5){
            std::cout << "\nNamero maximo de tentativas excedido\n";
            boa = false;
            return boa;
        }
    }

    Adm* adm = new Adm(login, senha, idUsuario);
    adms.push_back(adm);
    std::cout << "\nAdministrador adicionado: \n";

    idUsuario+=1;

    return boa;
}

void cadastro(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int& idUsuario, std::string senhaAdm) {
    char opcao;

    bool boa;
    while (true) {
        std::cout << "\nVc deseja cadastrar um usuario ou um administrador? (u/a): ";
        std::cin >> opcao;

        if (opcao == 'u') {
            cadastroUsuario(usuarios, adms, idUsuario, senhaAdm);
            break;
        }
        else if (opcao == 'a') {
            boa = cadastroAdm(usuarios, adms, idUsuario, senhaAdm);
            if (boa) {
                break;
            }
        }
        else {
            std::cout << "\nOpção invalida\n";
        }
    }
}

void login(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
    std::string login, senha;

    while(true){
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

        if(found == false) {
            std::cout << "\nUsuario ou senha invalidos\n";
        }
        else{
            break;
        } 
    }
}

void inicio(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
    int opcao;
    
    std::cout << "\nBem-vindo ao sistema de biblioteca\n";
    
    do {
        std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            cadastro(usuarios, adms, idUsuario, senhaAdm);
        } else if (opcao == 2) {
            login(usuarios, livros, adms, idUsuario, senhaAdm);
        } else if (opcao == 0) {
            return;
        } else {
            std::cout << "\nOpcao invalida\n";
        }
    } while(opcao != 0);
}

// inicialização de adicionais

void iniciarMultas(std::vector<Usuario*>& usuarios) {
    for (Usuario* usuario : usuarios) {
        usuario->calcMulta();
    }
}

void inicializarLivros(std::vector<Livro*>& livros){
    for (int i = 0; i < 10; i++) {
        Livro* livro = new Livro();
        livro->setTitulo("Livro " + std::to_string(i+1));
        livro->setAutor("Autor " + std::to_string(i+1));
        livro->setAno(2000 + i+1);
        livro->setGenero("Genero " + std::to_string(i+1));
        livro->setId(i);
        livros.push_back(livro);
    }
}

int main() {
    std::vector<Usuario*> usuarios;
    std::vector<Livro*> livros;
    std::vector<Adm*> adms;

    std::string senhaAdm = "admin";

    int idUsuario = 0;

    inicializarLivros(livros);
    iniciarMultas(usuarios);
    inicio(usuarios, livros, adms, idUsuario, senhaAdm);

    for (Usuario* usuario : usuarios) {
        delete usuario;
    }
    usuarios.clear();

    for (Livro* livro : livros) {
        delete livro;
    }
    livros.clear();

    for (Adm* adm : adms) {
    delete adm;
}
adms.clear();

    return 0;
}