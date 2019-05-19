#include "Candidato.h"

Candidato::Candidato() {
	this->votos_recebidos = 0;
	this->eleito = false;
}

Candidato::~Candidato() {
}

string Candidato::getNome() const {
	return nome;
}

void Candidato::setNome(const string& nome) {
	this->nome = nome;
}

Partido* Candidato::getPartido() const{
	return this->partido;
}

void Candidato::setPartido(Partido& partido){
	this->partido = &partido;
}

int Candidato::getVotos_recebidos() const{
	return votos_recebidos;
}

void Candidato::setVotos_recebidos(const int& votos_recebidos){
	this->votos_recebidos = votos_recebidos;
}

bool Candidato::isEleito() const{
	return eleito;
}

void Candidato::setEleito(bool eleito){
	this->eleito = eleito;
}

void Candidato::toString() const{
	if (this->getPartido()->getColigacao()->numDePartidos() > 1) {
		cout << this->getNome() << " (" << this->getPartido()->getNome() << ", ";
		cout << this->getVotos_recebidos() << " votos) - ";
		cout << this->getPartido()->getColigacao()->toString();

	} else {
		cout << this->getNome() << " (" << this->getPartido()->getNome() << ", ";
		cout << this->getVotos_recebidos() << " votos)";
	}
}

bool comparaCandidatos (Candidato*& a, Candidato*& b){
	return a->getVotos_recebidos() > b->getVotos_recebidos();
}