#ifndef ELEICAO_H_
#define ELEICAO_H_
#include <vector>
#include "Coligacao.h"

using namespace std;


class Eleicao {
	vector<Candidato*> candidatos;
	vector<Partido*> partidos;
	vector<Coligacao*> coligacoes;
	int num_votos;

public:
	Eleicao(vector<Candidato*> c, vector<Partido*> p, vector<Coligacao *> col);
	virtual ~Eleicao();

	vector<Candidato*> getCandidatos();

	void setCandidatos(vector<Candidato*>& candidatos);

	vector<Partido*> getPartidos();

	void setPartidos(vector<Partido*>& partidos);

	vector<Coligacao*> getColigacoes();

	void setColigacoes(vector<Coligacao*>& coligacoes);

	/**
	 * Conta quantos candidatos foram eleitos, representando a quantidade de vagas.
	 *
	 * @return O numero de vagas da eleição.
	 */
	int numVagas();

	/**
	 * Realiza o somatório de todos os votos recebidos pelos candidatos.
	 *
	 * @return A quantidade total de votos da eleição.
	 */
	int totalVotosNominais();

};

#endif /* ELEICAO_H_ */
