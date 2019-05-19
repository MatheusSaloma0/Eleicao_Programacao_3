#ifndef COLIGACAO_H_
#define COLIGACAO_H_
#include <list>

class Candidato;
class Partido;

using namespace std;

#include "Candidato.h"
#include "Partido.h"

/**
 * Classe que implementa atributos e metodos de uma Coligacao em uma eleicao.
 */
class Coligacao {
	list<Partido*> partidos;
	int num_votos;
	
public:
	Coligacao();
	virtual ~Coligacao();

	/**
	 * @return Lista de partidos da coligacao.
	 */
	list<Partido*> getPartidos() const;

	/**
	 * Insere um partido na coligacao.
	 *
	 * @param p Partido a ser inserido.
	 */
	void insere(Partido& p);

	/**
	 * Verifica se a coligacao contem determinado partido.
	 *
	 * @param p Partido a ser verificado.
	 * @return Valor logico representando a existencia deste partido na coligacao.
	 */
	bool contem(Partido& p);

	/**
	 * Realiza o somatorio dos votos de cada partido da coligacao.
	 *
	 * @return A quantidade de votos recebidos pela coligacao.
	 */
	int votosTotais();

	string toString();

	/**
	 * Reune informacoes dos nomes dos partidos, a quantidade total de votos
	 * recebidos e quantos candidatos foram eleitos nesta coligacao e imprime
	 * na saida padrao.
	 */
	void dadosDaColigacao();
	
	int numDePartidos();
	
	int compare(Coligacao& c1, Coligacao& c2);

	void setNumVotos(const int n);

};

bool comparaColigacoes (Coligacao*& a, Coligacao*& b);

#endif /* COLIGACAO_H_ */
