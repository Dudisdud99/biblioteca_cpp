#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <chrono>
#include <iostream>
#include <sstream>

class livro;

class Emprestimo {

	public:

        Emprestimo(int _id);

        ~Emprestimo();

        //get

        int getIdLivro();

        //set

        void setIdLivro(int _id);

        //funcoes

        float calcMulta();

        std::string mostrarDataEmprestimo();

        std::string mostrarDataDevolucao();

	private:

		std::chrono::time_point<std::chrono::system_clock> dataEmprestimo, dataDevolucao;
		int idLivro;
};
#endif