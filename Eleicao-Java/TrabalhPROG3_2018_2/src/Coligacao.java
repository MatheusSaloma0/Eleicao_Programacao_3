package pkg_01;

import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

/**
 * Classe que implementa atributos e métodos de uma Coligação em uma eleição.
 */
public class Coligacao implements Comparator<Coligacao> {
	private List<Partido> partidos = new LinkedList<Partido>(); // Conjunto de partidos que compõe a coligação.

	/**
	 * @return Uma cópia do conjunto de partidos.
	 */
	public Set<Partido> getPartidos() {
		return new HashSet<Partido>(partidos);
	}

	/**
	 * Insere um partido na coligação.
	 *
	 * @param p Partido a ser inserido.
	 */
	public void insere(Partido p) {
		partidos.add(p);
	}

	/**
	 * Verifica se a coligação contém determinado partido.
	 *
	 * @param p Partido a ser verificado.
	 * @return Valor lógico representando a existência deste partido na coligação.
	 */
	public boolean contem(Partido p) {
		return partidos.contains(p);
	}

	@Override
	public String toString() {
		String result = "Coligação: ";
		for (Partido p : this.partidos) {
			result += p.getNome();
			result += " / ";
		}
		result += "!";
		result = result.replace(" / !", "");
		return result;
	}

	/**
	 * Realiza o somatório dos votos de cada partido da coligação.
	 *
	 * @return A quantidade de votos recebidos pela coligação.
	 */
	public int votosTotais() {
		int soma_votos = 0;

		for (Partido p : this.partidos) {
			soma_votos += p.votosTotais();
		}

		return soma_votos;
	}

	/**
	 * Reúne as informações dos nomes dos partidos, a quantidade total de votos
	 * recebidos e quantos candidatos foram eleitos nesta coligação.
	 *
	 * @return Texto contendo dados da coligacao.
	 */
	public String dadosDaColigacao() {
		String result = "";
		int num_votos = 0;
		int num_eleitos = 0;

		for (Partido p : partidos) {
			num_votos += p.votosTotais();
			num_eleitos += p.numCandidatosEleitos();
		}

		result += this.toString() + ", " + num_votos + " votos, ";

		// result += " votos, ";

		result += num_eleitos;
		if (num_eleitos > 1) {
			result += " candidatos eleitos";
		} else {
			result += " candidato eleito";
		}

		return result;
	}

	@Override
	public int compare(Coligacao c1, Coligacao c2) {
		return c1.votosTotais() - c2.votosTotais();
	}
}
