#ifndef ADM_HPP
#define ADM_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"

class Adm : public Usuario{
    public:
        Adm(std::string _login, std::string _senha, int _id, int _tipo) : Usuario(_login, _senha, _id, _tipo) {
        };
        ~Adm(){};

        bool operator==(Adm& other) {
            return (this->getLogin() == other.getLogin() && this->getSenha() == other.getSenha());
        }

        int opcoesUsuario(std::vector<Livro*>& livros, std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
            int opcao;

            while (true){
                std::cout << "\n1 - Emprestar livro\n2 - Devolver livro\n3 - Pagar multa\n4 - Exibir dados\n5 - Exibir usuarios\n6 - Exibir livros\n0 - Sair\nSua opcao: ";
                std::cin >> opcao;

                if (opcao == 0) {
                    break;
                } else if (opcao == 1) {
                    emprestarLivro(livros);
                } else if (opcao == 2) {
                    devolverLivro(livros);
                } else if (opcao == 3) {
                    pagarMulta();
                } else if(opcao == 4) {
                    exibirDados(livros);
                } else if(opcao == 5) {
                    exibirUsuarios(usuarios, adms, livros);
                    opcoesAdm(usuarios, adms, idUsuario, senhaAdm, livros);
                } else if(opcao == 6){
                    exibirLivros(livros); 
                    opcoesLivro(livros);

                } else {
                    std::cout << "\nOpção invalida\n";
                }
            }
            return 0;
        }

        void exibirUsuarios(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, std::vector<Livro*>& livros){
            std::cout << "\nUsuários:\n";
            for(Usuario* usuario : usuarios){
                std::cout << "Usuário: " << usuario->getLogin() << " , ID: " << usuario->getId()+1 << " , multa: " << usuario->getMulta() << std::endl;
            }

            bool found = false;
            int thisId = this->getId();
            std::cout << "\nAdministradores:\n";
            for(Adm* adm : adms){
                if (!found) {
                    if (adm->getId() == thisId) {
                        found = true;
                    }
                    else {
						adm->exibirDados(livros);
					}
                }
                else{
                    adm->exibirDados(livros);
                }           
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
                    addUser(usuarios, livros, adms, idUsuari, senhaAdm);
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
                for (Usuario* usuario : usuarios) {
                    if(usuario->getId() == id-1){
						found = true;
                        usuario->autoDeletar(usuarios);
					}
                }
                if(found == false){
                    for (Adm* adm : adms) {
                        if (adm->getId() == id - 1) {
                            found = true;
                            adm->autoDeletar(adms);
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

        void autoDeletar(std::vector<Adm*>& adms) {
            for (auto it = adms.begin(); it != adms.end(); ) {
                if (*it == this) {
                    it = adms.erase(it);
                    delete this;
                    break;
                }
                else {
                    ++it;
                }
            }
        }

        void addUser(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm){
            //cadastro(usuarios, livros, adms, idUsuario, senhaAdm);
        }

        void addLivro(std::vector<Livro*>& livros){
			//livros.push_back(new Livro());
		}

        void exibirLivros(std::vector<Livro*>& livros) {
            std::cout << "\nLivros:\n";
            for (Livro* livro : livros) {
                if (livro->getStatus()) {
					std::cout << "Livro: " << livro->getTitulo() << ", ID: " << livro->getId()+1 << ", Autor: " << livro->getAutor() << ", Ano: " << livro->getAno() << std::endl;
				}
            }
        }

        void opcoesLivro(std::vector<Livro*>& livros){
			int opcao;
			while(true){
				std::cout << "\n1 - Adicionar livro\n2 - Remover livro\n0 - Sair\nSua opção: ";
				std::cin >> opcao;

				if(opcao == 0){
					break;
				} else if(opcao == 1){
					addLivro(livros);
                }
                else if (opcao == 2){
                    removerLivro(livros);
                }
                else {
					std::cout << "\nOpção inválida\n";
				}
			}
		}

        void removerLivro(std::vector<Livro*>& livros) {
            std::cout << "\nDigite o ID do livro que deseja remover: ";
            int id;
            std::cin >> id;

            for (auto it = livros.begin(); it != livros.end(); ) {
				if ((*it)->getId() == id-1) {
					delete* it;
					*it = nullptr;
					it = livros.erase(it);
					break;
				}
				else {
					++it;
				}
			}
        }

        void verificarUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, std::vector<Livro*>& livros){
            int id;
            bool found = false;

            while (true){
                std::cout << "\nDigite o ID do usuário: ";
                std::cin >> id;

                int opcao;

                std::cout << "\nE um adm (1 - sim, 2 - nao): ";
                std::cin >> opcao;

                if(opcao == 1){
                    for (Usuario* usuario : usuarios) {
                        if (usuario->getId() == id-1) {
                            std::cout << "\nUsuário encontrado\n";
                            found = true;
                            usuario->exibirDados(livros);
                            opcaoAdmUsuario(usuarios, adms, usuario->getId());
                            break;
                        }
                    }
                }
                else if(opcao == 2){
                    for (Adm* adm : adms) {
                        if (adm->getId() == id-1) {
                            std::cout << "\nUsuário encontrado\n";
                            found = true;
                            adm->exibirDados(livros);
                            opcaoAdmUsuario(usuarios, adms, adm->getId());
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

        void opcaoAdmUsuario(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int id){
            while (true) {
                int opcao;
                std::cout << "\n1 - Deletar\n2 - Multar\n0 - Sair\nSua opcao: ";
                std::cin >> opcao;

                if(opcao == 0){
                    break;
                }
			    else if(opcao == 1){
				    deleteUser(usuarios, adms);
			    }
			    else if(opcao == 2){
				    //multar(usuarios, adms, id
			    }
			    else{
				    std::cout << "\nOpção inválida\n";
			    }
            }
        }

};
#endif