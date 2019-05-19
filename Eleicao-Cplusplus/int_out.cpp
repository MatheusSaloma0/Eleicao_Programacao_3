#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include "Eleicao.h"
#include <map>
#include <locale>
#include <algorithm>
#include <cstring>
#include "in_out.h"

using namespace std;

Eleicao* lerArquivo(string file){
    string linha;
	ifstream input(file);

	if (input.is_open()) {
		vector<Candidato*> candidatos;
		map<string, Partido*> partidos;
		vector<Coligacao*> coligacoes;

		string eleito;
		string nome;
		string votos;
		string part;
		string colig;

		getline(input, linha); // Ignora a primeira linha do arquivo.
		while (!input.eof()) {
			getline(input, linha);
			if(linha.empty()) { break; }
			
			istringstream line_aux(linha);
			getline(line_aux, eleito, ';');
			line_aux.ignore(5, ';');
			getline(line_aux, nome, ';');
			getline(line_aux, colig, ';');
			getline(line_aux, votos, ';');

			Candidato *c = new Candidato();
			
			candidatos.push_back(c);

			if (eleito.at(0) == '*') c->setEleito(true);

			c->setNome(nome);
			
			locale brasilLocale("pt_BR.UTF-8");
			int v;
			istringstream vts(votos.c_str());
			vts.imbue(brasilLocale);
			vts >> v;
			c->setVotos_recebidos(v);

			for (unsigned int i = 0; i < colig.length(); i++) {
				if (colig.at(i) == '/') {
					colig.erase(colig.begin() + i - 1);
					colig.erase(colig.begin() + i);
				}
				if (colig.at(i) == '-'){
					colig.erase(colig.begin() + i-1);
					colig.erase(colig.begin() + i);
				}
			} 
			
			istringstream ss_colig(colig);
			getline(ss_colig, part, '-');

			map<string, Partido*>::iterator it = partidos.find(part);
			if (it == partidos.end()){ //Nao esta no mapa
				Partido *p = new Partido();
				p->setNome(part);
				c->setPartido(*p);
				p->insere(*c);
				partidos.insert(pair<string, Partido*>(p->getNome(), p));
			} else {
				c->setPartido(*it->second);
				(it->second)->insere(*c);
			}

			if (c->getPartido()->getColigacao() == NULL) {
				if (ss_colig.good()) { // Se o partido estiver em uma coligação.

					Coligacao *col = new Coligacao();

					string nomePartido;

					do {
						getline(ss_colig,nomePartido,'/');
						if (partidos.count(nomePartido) == 0){
							Partido *p = new Partido();
							p->setNome(nomePartido);
							partidos.insert(pair<string, Partido *>(string(nomePartido), p));
							p->setColigacao(*col);
						}

						if (col->contem(*(partidos.find(string(nomePartido)))->second) == false){
							Partido *p = partidos.find(string(nomePartido))->second;
							col->insere(*p);
							p->setColigacao(*col);
						}
					} while (ss_colig.good());
					coligacoes.push_back(col);
				} 
				else {
					Coligacao *col = new Coligacao();
					c->getPartido()->setColigacao(*col);
					col->insere(*c->getPartido());
					coligacoes.push_back(col);
				}
			}
		}

		vector<Partido*> partidos2;
		for (pair<string,Partido*> p : partidos) {
			partidos2.push_back(p.second);
		}
		
		std::sort(candidatos.begin(),candidatos.end(),comparaCandidatos);
		std::sort(partidos2.begin(),partidos2.end(),comparaPartidos);
		std::sort(coligacoes.begin(),coligacoes.end(),comparaColigacoes);
		
		Eleicao* elec = new Eleicao(candidatos,partidos2,coligacoes);

		input.close();
    	return elec;   
    }
	cout << "Erro na leitura do arquivo " << file << endl;
    return NULL;
}

void dadosDosPartidos(Eleicao *e){
	cout << "Votação (nominal) dos partidos e número de candidatos eleitos:\n";

	int i = 1;
	int votos_totais = 0;

	for (Partido* p : e->getPartidos()) {
		if (p->getCandidatos().size() > 0){
			cout << i << " - ";
			p->dadosDoPartido();
			cout << endl;
			votos_totais += p->votosTotais();
			i++;
		}
	}
	cout << "\nTotal de votos nominais: " << votos_totais << endl;
}

void dadosDasColigacoes(Eleicao *e){
	cout << "Votação (nominal) das coligações e número de candidatos eleitos:" << endl;
	int i = 1;

	for (Coligacao* c : e->getColigacoes()) {
		cout << i << " - ";
		c->dadosDaColigacao();
		cout << endl;
		i++;
	}
}

void candidatosEleitos(Eleicao *e){
	cout << "Vereadores eleitos:" << endl;
	int i = 1;

	for (Candidato* v : e->getCandidatos()) {
		if (v->isEleito()){
			cout << i << " - ";
			v->toString();
			cout << endl;
			i++;
		}
	}
}

void candidatosMaisVotados(Eleicao *e){
	cout << "Candidatos mais votados";
	cout << "(em ordem decrescente de votação e respeitando número de vagas):" << endl;

	for (int i = 0; i < e->numVagas(); i++) {
		cout << i + 1 << " - ";
		e->getCandidatos().at(i)->toString();
		cout << endl;
	}
}

void votacaoMajoritaria(Eleicao *e) {
	cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram"; 
	cout << " eleitos:\n(com sua posição no ranking de mais votados)" << endl;

	for(int i = 0; i < e->numVagas(); i++) {
		if(!e->getCandidatos().at(i)->isEleito()) {
			cout << i + 1 << " - ";
			e->getCandidatos().at(i)->toString();
			cout << endl;
		}
	}
}

void beneficiadosSistProp(Eleicao *e){
	cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
	cout << "(com sua posição no ranking de mais votados)" << endl;
	
	for (unsigned int i = e->numVagas(); i < e->getCandidatos().size(); i++) {
		if (e->getCandidatos().at(i)->isEleito()) {
			cout << (i + 1) << " - " ;
			e->getCandidatos().at(i)->toString();
			cout << endl;
		}
	}
}
