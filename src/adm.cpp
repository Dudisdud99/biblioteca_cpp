#include "lib/adm.hpp"
#include "lib/usuario.hpp"
#include "lib/livro.hpp"

//costrutor e destrutor
 
Adm::Adm(std::string _login, std::string _senha, int _id, int _tipo) : Usuario(_login, _senha, _id, _tipo) {};

Adm::~Adm() {};

bool Adm::operator==(Adm& other) {
    return (this->getLogin() == other.getLogin() && this->getSenha() == other.getSenha());
}

int Adm::opcoesUsuario(std::vector<Livro*>& livros, std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
    int opcao;

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\n1 - Emprestar livro\n2 - Devolver livro\n3 - Pagar multa\n4 - Exibir dados\n5 - Exibir usuarios\n6 - Exibir livros\n0 - Sair\n\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            emprestarLivro(livros);
        }
        else if (opcao == 2) {
            devolverLivro(livros);
        }
        else if (opcao == 3) {
            pagarMulta();
        }
        else if (opcao == 4) {
            exibirDados(livros);
        }
        else if (opcao == 5) {
            exibirUsuarios(usuarios, adms, livros);
            opcoesAdm(usuarios, adms, idUsuario, senhaAdm, livros);
        }
        else if (opcao == 6) {
            exibirLivros(livros);
            opcoesLivro(livros);

        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
    return 0;
}

void Adm::exibirUsuarios(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, std::vector<Livro*>& livros) {
    std::cout << "\n---------------------------\n";
    std::cout << "\nUsuarios:\n\n";
    for (Usuario* usuario : usuarios) {
        std::cout << "Usuario: " << usuario->getLogin() << " , ID: " << usuario->getId() + 1 << " , multa: " << usuario->getMulta() << std::endl;
    }

    bool found = false;
    int thisId = this->getId();
    std::cout << "\nAdministradores:\n\n";
    for (Adm* adm : adms) {
        if (!found) {
            if (adm->getId() == thisId) {
                found = true;
            }
            else {
                std::cout << "Usuario: " << adm->getLogin() << " , ID: " << adm->getId() + 1 << " , multa: " << adm->getMulta() << std::endl;
            }
        }
        else {
            std::cout << "Usuario: " << adm->getLogin() << " , ID: " << adm->getId() + 1 << " , multa: " << adm->getMulta() << std::endl;
        }
    }
}

void Adm::opcoesAdm(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUsuari, std::string senhaAdm, std::vector<Livro*>& livros) {
    int opcao;

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\n1 - verificar user \n2 - Add user\n0 - Sair\n\nSua opcao: ";      
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            verificarUser(usuarios, adms, livros);
        }
        else if (opcao == 2) {
            addUser(usuarios, livros, adms, idUsuari, senhaAdm);
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
}

void Adm::deleteUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUser) {
    bool found = false;
    while (true) {
        std::cout << "\n---------------------------\n";
        for (Usuario* usuario : usuarios) {
            if (usuario->getId() == idUser - 1) {
                found = true;
                usuario->autoDeletar(usuarios);
            }
        }
        if (found == false) {
            for (Adm* adm : adms) {
                if (adm->getId() == idUser - 1) {
                    found = true;
                    adm->autoDeletar(adms);
                }
            }
        }
        if (found == false) {
            std::cout << "\nUsuario nao encontrado\n";
        }
        else {
            std::cout << "\nUsuario excluido com sucesso\n";
            break;
        }
    }
}

void Adm::autoDeletar(std::vector<Adm*>& adms) {
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

void Adm::addUser(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms, int idUsuario, std::string senhaAdm) {
    std::string nomeUsuario, senha;
    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\nDigite o nome de usuario: ";
        std::cin >> nomeUsuario;

        bool existeUser = false;

        for (Usuario* usuario : usuarios) {
            if (usuario->getLogin() == nomeUsuario) {
                existeUser = true;
                break;
            }
        }
        if (existeUser == false) {
            for (Adm* adm : adms) {
                if (adm->getLogin() == nomeUsuario) {
                    existeUser = true;
                    break;
                }
            }
        }
        if (existeUser) {
            std::cout << "\nUsuario ja existe\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        if (senha == senhaAdm) {
            std::cout << "\nSenha invalida\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "\nVoce esta cadastrando um administrador ou usuario (1 - Admin, 2 - Usuario): ";
        int opcao;
        std::cin >> opcao;
        if (opcao == 1) {
            bool existeAdm = false;

            for (int i = 0; i < 5; i += 1) {
                std::string codigo;
                std::cout << "Digite o codigo de verificacao: ";
                std::cin >> codigo;
                if (codigo == senhaAdm) {
                    int tipo = 1;
                    Adm* adm = new Adm(nomeUsuario, senha, idUsuario, tipo);
                    adms.push_back(adm);
                    std::cout << "\nAdministrador cadastrado com sucesso!!!\n";
                    existeAdm = true;
                    break;
                }
                else {
                    std::cout << "\nCodigo invalido\n";
                }
            }
            if (existeAdm) {
                break;
            }
            else {
                opcao = 2;
            }

        }
        else if (opcao == 2) {
            int tipo = 2;
            Usuario* usuario = new Usuario(nomeUsuario, senha, idUsuario, tipo);
            usuarios.push_back(usuario);
            std::cout << "\nUsuario cadastrado com sucesso!!!\n";
            break;
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
    idUsuario += 1;

}

void Adm::addLivro(std::vector<Livro*>& livros) {
    Livro* livro = new Livro();
	std::string titulo, autor, genero;
	int ano;

    std::cout << "\n---------------------------\n";
	std::cout << "\nDigite o titulo do livro: ";
	std::cin >> titulo;
	livro->setTitulo(titulo);

	std::cout << "\nDigite o autor do livro: ";
	std::cin >> autor;
	livro->setAutor(autor);

	std::cout << "\nDigite o genero do livro: ";
	std::cin >> genero;
	livro->setGenero(genero);

	std::cout << "\nDigite o ano do livro: ";
	std::cin >> ano;
	livro->setAno(ano);

	livro->setId(livros.size());
	livro->setStatus(true);

	livros.push_back(livro);
}

void Adm::exibirLivros(std::vector<Livro*>& livros) {
    std::cout << "\n---------------------------\n";
    std::cout << "\nLivros:\n\n";
    for (Livro* livro : livros) {
        if (livro->getStatus()) {
            std::cout << "Livro: " << livro->getTitulo() << ", ID: " << livro->getId() + 1 << ", Autor: " << livro->getAutor() << ", Ano: " << livro->getAno() << std::endl;
        }
    }
}

void Adm::opcoesLivro(std::vector<Livro*>& livros) {
    int opcao;
    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\n1 - Adicionar livro\n2 - Remover livro\n0 - Sair\n\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            addLivro(livros);
        }
        else if (opcao == 2) {
            removerLivro(livros);
        }
        else {
            std::cout << "\nOp��o invalida\n";
        }
    }
}

void Adm::removerLivro(std::vector<Livro*>& livros) {
    std::cout << "\n---------------------------\n";
    std::cout << "\nDigite o ID do livro que deseja remover: ";
    int id;
    std::cin >> id;

    for (auto it = livros.begin(); it != livros.end(); ) {
        if ((*it)->getId() == id - 1) {
            if ((*it)->getStatus()) {
                delete* it;
                *it = nullptr;
                it = livros.erase(it);
                break;
            }
            else {
                std::cout << "\nlivro emprestado\n";
            }
        }
        else { 
            ++it;
        }
    }
}

void Adm::verificarUser(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, std::vector<Livro*>& livros) {
    int id;
    bool found = false;

    while (true) {
        std::cout << "\n---------------------------\n";
        std::cout << "\nDigite o ID do usuario: ";
        std::cin >> id;

        int opcao;

        std::cout << "\nE um adm (1 - sim, 2 - nao): ";
        std::cin >> opcao;

        if (opcao == 2) {
            for (Usuario* usuario : usuarios) {
                if (usuario->getId() == id - 1) {
                    std::cout << "\nUsuario encontrado\n";
                    found = true;
                    int idUser = usuario->getId();
                    opcaoAdmUsuario(usuarios, adms, idUser);
                    break;
                }
            }
        }
        else if (opcao == 1) {
            for (Adm* adm : adms) {
                if (adm->getId() == id - 1) {
                    std::cout << "\nUsuario encontrado\n";
                    found = true;
                    adm->exibirDados(livros);
                    int idUser = adm->getId();
                    opcaoAdmUsuario(usuarios, adms, idUser);
                    break;
                }
            }
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }

        if (found == false) {
            std::cout << "\nUsuario nao encontrado\n";
        }
        else {
            break;
        }
    }
}

void Adm::opcaoAdmUsuario(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int idUser) {
    while (true) {
        int opcao;
        std::cout << "\n---------------------------\n";
        std::cout << "\n1 - Deletar\n2 - Multar\n0 - Sair\n\nSua opcao: ";
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            deleteUser(usuarios, adms, idUser);
        }
        else if (opcao == 2) {
            multar(usuarios, adms, idUser);
        }
        else {
            std::cout << "\nOpcao invalida\n";
        }
    }
}

void Adm::multar(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms, int id) {
	int valor;
    std::cout << "\n---------------------------\n";
	std::cout << "\nDigite o valor da multa: ";
	std::cin >> valor;

	for (Usuario* usuario : usuarios) {
		if (usuario->getId() == id) {
			usuario->setMulta(valor);
			std::cout << "\nMulta aplicada com sucesso\n";
			break;
		}
	}
	for (Adm* adm : adms) {
		if (adm->getId() == id) {
			adm->setMulta(valor);
			std::cout << "\nMulta aplicada com sucesso\n";
			break;
		}
	}
}