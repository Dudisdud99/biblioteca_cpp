#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <iostream>
#include <string>
#include <vector>
#include "emprestimo.hpp"
#include "livro.hpp"

class Usuario {
    public:
        Usuario(std::string _login, std::string _senha, int _id, int _tipo){
            login = _login;
            senha = _senha;
            id = _id;
            multa = 0;
            status = true;
            tipo = _tipo;
        };
        
        ~Usuario(){
            for (Emprestimo* emprestimo : emprestimos) {
                delete emprestimo;
            }
            emprestimos.clear();
        };

        void setLoginSenha(std::string _login, std::string _senha){
            senha = _senha;
            login = _login;
        }

        int getTipo(){
			return tipo;
		}

        float getMulta(){
            return multa;
        }

        std::string getLogin(){
            return login;
        }

        std::string getSenha(){
            return senha;
        }

        void setMulta(float _multa){
            multa = _multa;
        }

        void setStatus(bool _status){
            status = _status;
        }

        int getId(){
            return id;
        }

        void exibirDados(std::vector<Livro*>& livros){
            std::cout << "\nLogin: " << login << std::endl;
            std::cout << "Multa: " << multa << std::endl;

            if(emprestimos.size() > 0){
                std::cout << "\nLivros emprestados: " << std::endl;
                for(Emprestimo* emprestimo : emprestimos){
                    int id = emprestimo->getIdLivro();
                    std::cout << "\n" << livros[id]->getTitulo() << ", ID: " << id + 1 << std::endl;
                    std::cout << "Data de emprestimo: " << emprestimo->mostrarDataEmprestimo();
                    std::cout << "Data de devolucao: " << emprestimo->mostrarDataDevolucao();
                    if(livros[id]->getStatus()){
                        std::cout << "!!Devolvido!!\n";
                    }
                }
            }
        }

        void emprestarLivro(std::vector<Livro*>& livros){
            if(multa > 300){
                std::cout << "\nUsuário bloqueado por excesso de multa\n";
                return;
            }
            int id = livrosDisponiveis(livros);
            Emprestimo* emprestimo = new Emprestimo(id);
            emprestimos.push_back(emprestimo);
        }

        void calcMulta(){
            multa = 0;
            for(Emprestimo* emprestimo : emprestimos){
                multa += emprestimo->calcMulta();
            }
            setMulta(multa);
        }

        void devolverLivro(std::vector<Livro*>& livros){
            int op;
            bool devolvido = false;
            std::cout << "\nLivros emprestados: \n";
            for(Emprestimo* emprestimo : emprestimos){
                int id = emprestimo->getIdLivro();
                std::cout << livros[id]->getTitulo() << ", ID: " << id+1 << std::endl;
            }
            std::cout << "\nDigite o ID de um livro para devolver: ";
            std::cin >> op;
            for(Emprestimo* emprestimo : emprestimos){
                if(op-1 == emprestimo->getIdLivro()){
                    livros[op-1]->setStatus(true);
                    devolvido = true;
                    break;
                }
            }
            if(devolvido==false){
                std::cout << "\nID invalido\n";
            }
            return;
        }

        void pagarMulta(){
            float valor;
            std::cout << "\nDigite o valor que deseja pagar: ";
            std::cin >> valor;
            multa -= valor;
            if(multa < 0){
                multa = 0;
            }
            std::cout << "\nMulta paga com sucesso\n";
        }

        int livrosDisponiveis(std::vector<Livro*>& livros){
            int nLivro;
            std::cout << "\nEscolha um livro e digite seu ID\n";
            for (int i = 0; i < livros.size(); i++) {
                Livro* livro = livros[i];
                bool status = livros[i]->getStatus();
                if(status){
                    std::cout << "Livro: " << livro->getTitulo() << ", ID: " << livro->getId()+1  << ", Autor: " << livro->getAutor() << ", Ano: "<< livro->getAno() << std::endl;
                }
            }
            std::cout << "\nSua escolha: ";
            std::cin >> nLivro;
            if(nLivro > livros.size() || nLivro < 0){
                std::cout << "\nID inválido\n";
                return -1;
            }
            int id = livros[nLivro-1]->getId();
            livros[nLivro-1]->setStatus(false);
            return id;
        }

        void opcoesUsuario(std::vector<Livro*>& livros, std::vector<Usuario*>& usuarios) {
            int opcao;

            while (true){
                std::cout << "\n1 - Emprestar livro\n2 - Devolver livro\n3 - Pagar multa\n4 - Exibir dados\n0 - Sair\nSua opçao: ";
                std::cin >> opcao;

                if (opcao == 1) {
                    emprestarLivro(livros);
                } else if (opcao == 2) {
                    devolverLivro(livros);
                } else if (opcao == 3) {
                    pagarMulta();
                } else if (opcao == 4) {
                    exibirDados(livros);
                } else if (opcao == 5) {
                    autoDeletar(usuarios);
                } else if (opcao == 0) {
                    break;
                }
                else {
                    std::cout << "\nOpção invalida\n";
                }
            }
        }

        void autoDeletar(std::vector<Usuario*>& usuarios) {
            for (auto it = usuarios.begin(); it != usuarios.end(); ) {
                if (*it == this) {
                    it = usuarios.erase(it);
                    delete this;
                    break;
                }
                else {
                    ++it;
                }
            }
        }

    private:
        std::string senha, login;
        float multa;
        bool status;
        std::vector<Emprestimo*> emprestimos;
        int id, tipo;
};
#endif