#include "Partido.h"

Partido::Partido() {
	this->coligacao = NULL;
}

Partido::~Partido() {
}

Coligacao* Partido::getColigacao() const {
	return this->coligacao;
}

void Partido::setColigacao(Coligacao& coligacao){
	this->coligacao = &coligacao;
}

string Partido::getNome() const { 
	return nome;
}

void Partido::setNome(const string& nome){
	this->nome = nome;
}

set<Candidato *> Partido::getCandidatos() const {
	return set<Candidato*>(candidatos);
}

void Partido::insere(Candidato& v){
	candidatos.insert(&v);
}

int Partido::votosTotais() const{
	int soma_votos = 0;

	for (Candidato* v : this->candidatos) {
		soma_votos += v->getVotos_recebidos();
	}
	return soma_votos;
}

int Partido::numCandidatosEleitos() const{
	int n_candidatos = 0;

	for (Candidato* v : this->candidatos) {
		if (v->isEleito()) {
			n_candidatos++;
		}
	}
	return n_candidatos;
}

void Partido::dadosDoPartido() const{
	cout << this->getNome()  << ", " << this->votosTotais() << " votos, ";
	cout << this->numCandidatosEleitos();

	if (this->numCandidatosEleitos() > 1){
		cout << " candidatos eleitos";
	}
	else {
		cout <<" candidato eleito";
	}
}

bool comparaPartidos (Partido*& a, Partido*& b){
	return a->votosTotais() > b->votosTotais();
}

void Partido::setNumVotos(const int n) {
	this->num_votos = n;
}