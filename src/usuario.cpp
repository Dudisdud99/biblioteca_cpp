#include "lib/usuario.hpp"
#include "lib/livro.hpp"

//costrutor e destrutor

Usuario::Usuario(std::string _login, std::string _senha, int _id, int _tipo) {
    login = _login;
    senha = _senha;
    id = _id;
    multa = 0;
    status = true;
    tipo = _tipo;
}

Usuario::~Usuario() {

}

//funcoes

int Usuario::getTipo() {

}

float Usuario::getMulta() {

}

int Usuario::getId() {

}

std::string Usuario::getLogin() {

}

std::string Usuario::getSenha() {

}

void Usuario::setLoginSenha(std::string _login, std::string _senha) {

}

void Usuario::setMulta(float _multa) {

}

void Usuario::setStatus(bool _status) {

}

void Usuario::exibirDados(std::vector<Livro*>& livros) {

}

void Usuario::emprestarLivro(std::vector<Livro*>& livros) {

}

void Usuario::calcMulta() {

}

void Usuario::devolverLivro(std::vector<Livro*>& livros) {

}

void Usuario::pagarMulta() {

}

int Usuario::livrosDisponiveis(std::vector<Livro*>& livros) {

}

void Usuario::opcoesUsuario(std::vector<Livro*>& livros, std::vector<Usuario*>& usuarios) {

}

void Usuario::autoDeletar(std::vector<Usuario*>& usuarios) {

}