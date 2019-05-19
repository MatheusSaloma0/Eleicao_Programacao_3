#ifndef PARTIDO_H_
#define PARTIDO_H_
#include <iostream>
#include <string>
#include <set>

class Candidato;
class Coligacao;

using namespace std;

#include "Candidato.h"
#include "Coligacao.h"

/**
 * Classe que implementa atributos e metodos de um Partido em uma eleicao.
 */
class Partido {
	string nome;
	Coligacao* coligacao;
	set<Candidato*> candidatos;
	int num_votos;

public:
	Partido();
	virtual ~Partido();

	Coligacao* getColigacao() const;

	void setColigacao(Coligacao& coligacao);

	string getNome() const;

	void setNome(const string& nome);

	/**
	 * @return Conjunto de candidatos do partido.
	 */
	set<Candidato*> getCandidatos() const;

	/**
	 * Insere um candidato no partido.
	 *
	 * @param v Candidato a ser inserido no partido.
	 */
	void insere(Candidato& v);

	/**
	 * Realiza o somatorio dos votos de cada candidato do partido.
	 *
	 * @return A quantidade de votos recebidos pelo partido.
	 */
	int votosTotais() const;

	/**
	 * Checa a lista de candidatos, verificando quantos foram eleitos.
	 *
	 * @return A quantidade de candidatos eleitos.
	 */
	int numCandidatosEleitos() const;

	/**
	 * Reune informacoes do nome do partido, a quantidade total de votos
	 * recebidos e quantos candidatos foram eleitos neste partido e imprime
	 * na saida padrao.
	 */
	void dadosDoPartido() const;

	int compare(Partido& p1, Partido& p2);

	void setNumVotos(const int n);
};

bool comparaPartidos (Partido*& a, Partido*& b);

#endif /* PARTIDO_H_ */
