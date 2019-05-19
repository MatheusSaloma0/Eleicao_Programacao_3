package pkg_01;

import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

/**
 * Classe que implementa atributos e métodos de um Partido em uma eleição.
 */
public class Partido implements Comparator<Partido> {
	private String nome;
	private Set<Candidato> candidatos = new HashSet<Candidato>();
	private Coligacao coligacao;

	public Coligacao getColigacao() {
		return coligacao;
	}

	public void setColigacao(Coligacao coligacao) {
		this.coligacao = coligacao;
	}

	public Partido(String nome) {
		this.nome = nome;
	}

	public Partido() {
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	/**
	 * @return Uma cópia do conjunto de candidatos do partido.
	 */
	public Set<Candidato> getCandidatos() {
		return new HashSet<Candidato>(candidatos);
	}

	/**
	 * Insere um candidato no partido.
	 *
	 * @param v Candidato a ser inserido no partido.
	 */
	public void insere(Candidato v) {
		candidatos.add(v);
	}

	/**
	 * Realiza o somatório dos votos de cada candidato do partido.
	 *
	 * @return A quantidade de votos recebidos pelo partido.
	 */
	public int votosTotais() {
		int soma_votos = 0;

		for (Candidato v : this.candidatos) {
			soma_votos += v.getVotos_recebidos();
		}

		return soma_votos;
	}

	/**
	 * Checa a lista de candidatos, verificando quantos foram eleitos.
	 *
	 * @return A quantidade de candidatos eleitos.
	 */
	public int numCandidatosEleitos() {
		int n_candidatos = 0;

		for (Candidato v : this.candidatos) {
			if (v.isEleito()) {
				n_candidatos++;
			}
		}

		return n_candidatos;
	}

	/**
	 * Reúne as informações do nome do partido, a quantidade total de votos
	 * recebidos e quantos candidatos foram eleitos neste partido.
	 *
	 * @return Texto contendo dados do partido.
	 */
	public String dadosDoPartido() {
		String result = this.getNome() + ", " + this.votosTotais() + " votos, " + this.numCandidatosEleitos();

		if (this.numCandidatosEleitos() > 1) {
			result += " candidatos eleitos";
		} else {
			result += " candidato eleito";
		}
		return result;
	}

	@Override
	public int compare(Partido p1, Partido p2) {
		return p1.votosTotais() - p2.votosTotais();
	}

}
