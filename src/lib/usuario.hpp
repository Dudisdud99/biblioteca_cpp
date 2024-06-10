#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <vector>
#include <iostream>
#include <string>

class Livro;
class Emprestimo;

class Usuario {

    public:

        Usuario(std::string _login, std::string _senha, int _id, int _tipo);

        ~Usuario();

        //get

        int getTipo();

        float getMulta();

        int getId();

        std::string getLogin();

        std::string getSenha();

        //set

        void setLoginSenha(std::string _login, std::string _senha);

        void setMulta(float _multa);

        void setStatus(bool _status);

        //funcoes

        void exibirDados(std::vector<Livro*>& livros);

        void emprestarLivro(std::vector<Livro*>& livros);

        void calcMulta();

        void devolverLivro(std::vector<Livro*>& livros);

        void pagarMulta();

        int livrosDisponiveis(std::vector<Livro*>& livros);

        void opcoesUsuario(std::vector<Livro*>& livros, std::vector<Usuario*>& usuarios);

        void autoDeletar(std::vector<Usuario*>& usuarios);

    private:

        std::string senha, login;
        float multa;
        bool status;
        std::vector<Emprestimo*> emprestimos;
        int id, tipo;
};

#endif