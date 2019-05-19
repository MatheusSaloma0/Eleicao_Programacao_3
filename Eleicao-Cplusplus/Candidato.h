#ifndef CANDIDATO_H_
#define CANDIDATO_H_
#include <string>

class Partido;
class Coligacao;

using namespace std;

#include "Partido.h"
#include "Coligacao.h"

/**
 * Classe que implementa atributos e metodos de um Candidato em uma eleicao.
 */
class Candidato {
	string nome;
	Partido* partido;
	int votos_recebidos;
	bool eleito;

public:
	Candidato();
	virtual ~Candidato();

	string getNome () const;

	void setNome(const string& nome) ;

	Partido* getPartido() const;

	void setPartido(Partido& partido);

	int getVotos_recebidos() const;

	void setVotos_recebidos(const int& votos_recebidos);

	bool isEleito() const;
	
	void setEleito(bool eleito);

	void toString() const;
};

bool comparaCandidatos (Candidato*& a, Candidato*& b);

#endif /* CANDIDATO_H_ */
