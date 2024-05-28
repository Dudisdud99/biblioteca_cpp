#ifndef ADM_HPP
#define ADM_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"

class Adm : public Usuario{
    public:
        Adm(std::string _login, std::string _senha, int _id) : Usuario(_login, _senha, _id) {
        };
        ~Adm(){};

        int opcoesUsuario(std::vector<Livro*>& livros, std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
            int opcao;

            while (true){
                std::cout << "\n1 - Emprestar livro\n2 - Devolver livro\n3 - Pagar multa\n4 - Exibir dados\n5 - Exibir usuarios\n0 - Sair\nSua opção: ";
                std::cin >> opcao;

                if (opcao == 1) {
                    emprestarLivro(livros);
                } else if (opcao == 2) {
                    devolverLivro(livros);
                } else if (opcao == 3) {
                    pagarMulta();
                } else if(opcao == 4) {
                    exibirDados(livros);
                } else if(opcao == 5) {
                    exibirUsuarios(usuarios, adms);
                    opcoesAdm(usuarios, adms, idUsuario, senhaAdm, livros);
                } else if(opcao == 6){
                    // exibirLivros();                   
                } else if (opcao == 0) {
                    break;
                } else {
                    std::cout << "\nOpção inválida\n";
                }
            }
            return 0;
        }

        void exibirUsuarios(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms){
            std::cout << "\nUsuários:\n";
            for(Usuario* usuario : usuarios){
                std::cout << "Usuário: " << usuario->getLogin() << " , ID: " << usuario->getId()+1 << " , multa: " << usuario->getMulta() << std::endl;
            }
            std::cout << "\nAdministradores:\n";
            for(Adm* adm : adms){
                std::cout << "Adm: " << adm->getLogin() << " , ID: " << adm->getId()+1 << " , multa: " << adm->getMulta() << std::endl;
            }
        }

        void opcoesAdm(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuari, std::string senhaAdm, std::vector<Livro*>& livros){
            int opcao;

            while(true){
                std::cout << "\nqual acao vc deseja fazer? \n1 - verificar user \n2 - Add user\n0 - Sair\nSua opção: ";                std::cin >> opcao;

                if(opcao == 0){
                    break;
                } else if (opcao == 1){
                    verificarUser(usuarios, adms, livros);
                } else if (opcao == 2){
                    addUser(usuarios, adms, idUsuari, senhaAdm);
                } else {
                    std::cout << "\nOpção inválida\n";
                }
            }
        }

        void deleteUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms){
            bool found = false;
            int id;
            while(true){
                std::cout << "\nDigite o ID do user que deseja excluir: ";
                std::cin >> id;
                for(int i = 0; i < usuarios.size(); i++){
                    if(usuarios[i]->getId() == id-1){
                        found = true;
                        usuarios[i]->~Usuario();
                        break;
                    }
                }
                if(found == false){
                    for(int i = 0; i < adms.size(); i++){
                        if(adms[i]->getId() == id-1){
                            found = true;
                            adms[i]->~Adm();
                            break;
                        }
                    }
                }
                if(found == false){
                    std::cout << "\nUsuário não encontrado\n";
                } else {
                    std::cout << "\nUsuário excluído com sucesso\n";
                    break;
                }
            }
        }

        void addUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm){
            std::string login, senha;

            while (true) {
                std::cout << "\nDigite o nome de usuário: ";
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
                            break;
                        }
                    }
                }
                else{
                    std::cout << "\nUsuário já existe\n";
                }
            }

            std::cout << "Digite a senha: ";
            std::cin >> senha;

            if(senha==senhaAdm){
                Adm* adm = new Adm(login, senha, idUsuario);
                adms.push_back(adm);
                std::cout << "\nAdiminstrador adicionado: \n";
            }
            else{
                Usuario* usuario = new Usuario(login, senha, idUsuario);
                usuarios.push_back(usuario);
                std::cout << "\nUsuário adicionado: \n";
            }

            idUsuario+=1;
        }

        void verificarUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, std::vector<Livro*>& livros){
            int id;
            bool found = false;

            while (true){
                std::cout << "\nDigite o ID do usuário: ";
                std::cin >> id;

                std::string opcao;

                std::cout << "\nE um adm (s/n): ";
                std::cin >> opcao;

                if(opcao == "n"){
                    for (Usuario* usuario : usuarios) {
                        if (usuario->getId() == id-1) {
                            std::cout << "\nUsuário encontrado\n";
                            found = true;
                            usuario->exibirDados(livros);
                            opcaoDeletar(usuarios, adms, usuario->getId());
                            break;
                        }
                    }
                }
                else if(opcao == "s"){
                    for (Adm* adm : adms) {
                        if (adm->getId() == id-1) {
                            std::cout << "\nUsuário encontrado\n";
                            found = true;
                            adm->exibirDados(livros);
                            opcaoDeletar(usuarios, adms, adm->getId());
                            break;
                        }
                    }
                } 
                else{
                    std::cout << "\nOpção inválida\n";
                }

                if(found == false){
                    std::cout << "\nUsuário não encontrado\n";
                }
                else{
                    break;
                }
            }     
        }

        void opcaoDeletar(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int id){
            int opcao;
            std::cout << "\nDeseja deletar o usuário?\n1 - Deletar\n0 - Sair\nSua opcao: ";
            std::cin >> opcao;

            if(opcao == 1){
                // deleteUser(usuarios, adms, id);
            }
        }

};
#endif