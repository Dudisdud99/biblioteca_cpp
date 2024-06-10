#ifndef ADM_HPP
#define ADM_HPP

#include <iostream>
#include <vector>

#include "usuario.hpp"

class Livro;

class Adm : public Usuario {

    public:

        Adm(std::string _login, std::string _senha, int _id, int _tipo);

        ~Adm();

        //funcoes

        bool operator==(Adm& other);

        int opcoesUsuario(std::vector<Livro*>& livros, std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm);

        void exibirUsuarios(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, std::vector<Livro*>& livros);

        void opcoesAdm(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuari, std::string senhaAdm, std::vector<Livro*>& livros);

        void deleteUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUser);

        void autoDeletar(std::vector<Adm*>& adms);

        void addUser(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm);

        void addLivro(std::vector<Livro*>& livros);

        void exibirLivros(std::vector<Livro*>& livros);

        void opcoesLivro(std::vector<Livro*>& livros);

        void removerLivro(std::vector<Livro*>& livros);

        void verificarUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, std::vector<Livro*>& livros);

        void opcaoAdmUsuario(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUser);

        void multar(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUser);
};

#endif