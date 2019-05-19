#ifndef LEITURA_H_
#define LEITURA_H_

#include "Eleicao.h"

using namespace std;

Eleicao* lerArquivo(string file);

/**
 * Reúne informações de todos os partidos, com exceção dos partidos sem candidatos
 * e imprime na saida padrao.
 */
void dadosDosPartidos(Eleicao *e);

/**
 * Reúne informacoes de todas as coligações e imprime na saida padrao.
 */
void dadosDasColigacoes(Eleicao *e);

/**
 * Reúne informações sobre os candidatos eleitos e imprime na saida padrao.
 */
void candidatosEleitos(Eleicao *e);

/**
 * Reúne informações sobre os candidatos mais votados (em ordem decrescente de
 * votacao e respeitando numero de vagas) e imprime na saida padrao.
 */
void candidatosMaisVotados(Eleicao *e);

/**
 * Reúne informações sobre os candidatos que teriam sido eleitos se a votação
 * fosse majoritária, e não foram eleitos e imprime na saida padrao.
 */
void votacaoMajoritaria(Eleicao *e);

/**
 * Reúne informações sobre os candidatos que se beneficiaram do sistema
 * proporcional e imprime na saida padrao.
 */
void beneficiadosSistProp(Eleicao *e);

#endif /* LEITURA_H_ */
