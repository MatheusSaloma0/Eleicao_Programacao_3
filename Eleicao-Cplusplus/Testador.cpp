#include "in_out.h"

using namespace std;

int main(int argc, char const *argv[]) {
	
	Eleicao *e = lerArquivo(string(argv[1]));
	
	if(e == NULL) exit(1);

	cout << "Número de vagas: "<< e->numVagas() << endl;
	cout << endl;
	
	candidatosEleitos(e);
	cout << endl;

	candidatosMaisVotados(e);
	cout << endl;

	votacaoMajoritaria(e);
	cout << endl;
	
	beneficiadosSistProp(e);
	cout << endl;

	dadosDasColigacoes(e);
	cout << endl;

	dadosDosPartidos(e);
	cout << endl;

	delete e;

	return 0;
}
