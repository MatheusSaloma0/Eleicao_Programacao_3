#include "Coligacao.h"

Coligacao::Coligacao() {
}

Coligacao::~Coligacao() {
}

list<Partido*> Coligacao::getPartidos() const{
	return list<Partido *>(partidos);
}

void Coligacao::insere(Partido& p){
	partidos.push_back(&p);
}

int Coligacao::numDePartidos(){
	return this->getPartidos().size();
}

bool Coligacao::contem(Partido& p){
	list<Partido *>::iterator it;
	for (it = this->partidos.begin(); it != this->partidos.end(); it++) {
		if ((*it) == &p) {
			return true;
		}
	}
	return false;
}

int Coligacao::votosTotais(){
	int soma_votos = 0;

	for (Partido* p : this->partidos) {
		soma_votos += p->votosTotais();
	}
	return soma_votos;
}

string Coligacao::toString(){
	string result = "Coligação: ";

	for (Partido* p : this->partidos) {
		result.operator +=(p->getNome());
		result.operator +=(" / ");
	}
	result = result.substr(0,result.length()-2);

	return result;
}

void Coligacao::dadosDaColigacao(){
	int num_votos = 0;
	int num_eleitos = 0;

	for (Partido* p : this->partidos) {
		num_votos += p->votosTotais();
		num_eleitos += p->numCandidatosEleitos();
	}
	cout << this->toString() << ", " << num_votos << " votos, " << num_eleitos;
	
	if (num_eleitos > 1){
		cout << " candidatos eleitos";
	}
	else{
		cout << " candidato eleito";
	}
}

bool comparaColigacoes (Coligacao*& a, Coligacao*& b){
	return a->votosTotais() > b->votosTotais();
}

void Coligacao::setNumVotos(const int n) {
	this->num_votos = n;
}
