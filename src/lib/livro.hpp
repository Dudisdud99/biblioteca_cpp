#ifndef LIVRO_HPP
#define LIVRO_HPP
#include <iostream>
#include <string>
#include <vector>

class Livro{
    public:
        Livro(){
            status = true;
        };
        ~Livro(){};

        void setTitulo(std::string _titulo){
            titulo = _titulo;
        }

        void setAutor(std::string _autor){
            autor = _autor;
        }

        void setAno(int _ano){
            ano = _ano;
        }

        void setGenero(std::string _genero){
            genero = _genero;
        }   

        std::string getTitulo(){
            return titulo;
        }

        std::string getAutor(){
            return autor;
        }

        int getAno(){
            return ano;
        }

        std::string getGenero(){
            return genero;
        }

        bool getStatus(){
            return status;
        }

        void setStatus(bool _status){
            status = _status;
        }

        void setId(int _id){
            id = _id;
        }

        int getId(){
            return id;
        }
    
    private:
        std::string titulo, autor, genero;
        int ano, id;
        bool status;
};
#endif