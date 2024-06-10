#include "lib/emprestimo.hpp"
#include "lib/livro.hpp"

//costrutor e destrutor

Emprestimo::Emprestimo(int _id) {
	idLivro = _id;
	dataEmprestimo = std::chrono::system_clock::now();
	dataDevolucao = dataEmprestimo + std::chrono::hours(24 * 7 * 2);
}

Emprestimo::~Emprestimo() {

}

//get

int Emprestimo::getIdLivro() {
    return idLivro;
}

//set

void Emprestimo::setIdLivro(int _id) {
	idLivro = _id;
}

//funcoes

std::string Emprestimo::mostrarDataEmprestimo() {
    std::time_t time = std::chrono::system_clock::to_time_t(dataEmprestimo);
    struct tm data;
    localtime_s(&data, &time);
    std::string dia = std::to_string(data.tm_mday);
    std::string mes = std::to_string(data.tm_mon);
    std::string ano = std::to_string(data.tm_year);
    return dia + "/" + mes + "/" + ano;
}

std::string Emprestimo::mostrarDataDevolucao() {
    std::time_t time = std::chrono::system_clock::to_time_t(dataDevolucao);
    struct tm data;
    localtime_s(&data, &time);
    std::string dia = std::to_string(data.tm_mday);
    std::string mes = std::to_string(data.tm_mon);
    std::string ano = std::to_string(data.tm_year);
    return dia + "/" + mes + "/" + ano;
}

float Emprestimo::calcMulta() {
    float multa = 0;
    int diferencaHoras = 0;
    std::chrono::time_point<std::chrono::system_clock> agora = std::chrono::system_clock::now();
    if (agora > dataDevolucao) {
        diferencaHoras = std::chrono::duration_cast<std::chrono::hours>(agora - dataDevolucao).count();
        multa = diferencaHoras / 24 * 50;
    }
    return multa;
}
