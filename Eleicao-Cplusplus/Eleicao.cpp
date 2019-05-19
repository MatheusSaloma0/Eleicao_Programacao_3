#include "Eleicao.h"

Eleicao::Eleicao(vector<Candidato*> c, vector<Partido*> p, vector<Coligacao *> col){

	for(Partido* p1 : p){
		p1->setNumVotos(p1->votosTotais());
	}

	for(Coligacao* c1 : col){
		c1->setNumVotos(c1->votosTotais());
	}

	this->setCandidatos(c);
	this->setPartidos(p);
	this->setColigacoes(col);

	this->num_votos = this->totalVotosNominais();
}

Eleicao::~Eleicao() {
	for(Candidato* c : this->candidatos){
		delete c;
	}

	for(Partido* p : this->partidos){
		delete p;
	}

	for(Coligacao* c : this->coligacoes){
		delete c;
	}
}

vector<Candidato*> Eleicao::getCandidatos(){
	return candidatos;
}

void Eleicao::setCandidatos(vector<Candidato*>& candidatos){
	this->candidatos = candidatos;
}

vector<Partido*> Eleicao::getPartidos(){
	return partidos;
}

void Eleicao::setPartidos(vector<Partido*>& partidos){
	this->partidos = partidos;
}

vector<Coligacao*> Eleicao::getColigacoes(){
	return coligacoes;
}

void Eleicao::setColigacoes(vector<Coligacao*>& coligacoes){
	this->coligacoes = coligacoes;
}

int Eleicao::numVagas(){
	int n_vagas = 0;

	for (Candidato* v : this->candidatos) {
		if (v->isEleito()) {
			n_vagas++;
		}
	}
	return n_vagas;
}

int Eleicao::totalVotosNominais(){
	int n_votos = 0;

	for (Candidato* v : this->candidatos) {
		n_votos += v->getVotos_recebidos();
	}
	return n_votos;
}