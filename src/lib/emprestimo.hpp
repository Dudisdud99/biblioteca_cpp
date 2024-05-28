#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>

class Emprestimo {
    public:
        Emprestimo(int _id){
            idLivro = _id;
            dataEmprestimo = std::chrono::system_clock::now();
            dataDevolucao = dataEmprestimo + std::chrono::hours(24*7*2);
        };
    	~Emprestimo(){};

        std::string mostrarDataEmprestimo(){
            std::time_t time = std::chrono::system_clock::to_time_t(dataEmprestimo);
            struct tm data;
            localtime_s(&data, &time);
            std::string dia = std::to_string(data.tm_mday);
            std::string mes = std::to_string(data.tm_mon);
            std::string ano = std::to_string(data.tm_year);
            return dia + "/" + mes + "/" + ano;
        }

        std::string mostrarDataDevolucao(){
            std::time_t time = std::chrono::system_clock::to_time_t(dataDevolucao);
            struct tm data;
            localtime_s(&data, &time);
            std::string dia = std::to_string(data.tm_mday);
            std::string mes = std::to_string(data.tm_mon);
            std::string ano = std::to_string(data.tm_year);
            return dia + "/" + mes + "/" + ano;
        }

        float calcMulta(){
            float multa =0;
            int diferencaHoras = 0;
            std::chrono::time_point<std::chrono::system_clock> agora = std::chrono::system_clock::now();
            if(agora > dataDevolucao){
                diferencaHoras = std::chrono::duration_cast<std::chrono::hours>(agora - dataDevolucao).count();
                multa = diferencaHoras/24 * 50;
            }
            return multa;
        }

        void setIdLivro(int _id){
            idLivro = _id;
        }

        int getIdLivro(){
            return idLivro;
        }

    private:
        std::chrono::time_point<std::chrono::system_clock> dataEmprestimo, dataDevolucao;
        int idLivro;
};
#endif